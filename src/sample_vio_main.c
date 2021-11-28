#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include "sample_comm.h"
#include "hi_common.h"
#include "sample_vio.h"
#include "mpi_sys.h"
#include "hifb.h"
#include "loadbmp.h"
#include "hi_tde_api.h"
#include "hi_tde_type.h"
#include "hi_tde_errcode.h"
#include "hi_math.h"
#include "loadbmp.h"
#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_demos/lv_demo.h"

#include "lv_drivers/indev/mouse.h"

#define WIDTH			1920
#define HEIGHT			1080
#define DISP_BUF_SIZE 	(128 * 1024)

/******************************************************************************
* function : show usage
******************************************************************************/
void SAMPLE_VIO_Usage(char *sPrgNm)
{
    printf("Usage : %s <index>\n", sPrgNm);
    printf("index:\n");
    printf("\t 0)LVGL HiFB Sample.\n");
    printf("\t 1)GDC - VPSS LowDelay.\n");
    printf("\t 2)FPN Calibrate & Correction.\n");
    printf("\t 3)WDR Switch.\n");
    printf("\t 4)90/180/270/0/free Rotate.\n");
    printf("\t 5)VI-VPSS-VO(MIPI_TX).\n\n");
    printf("\t If you have any questions, please look at readme.txt!\n");
    return;
}

/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}

HI_S32 SAMPLE_HIFB_LVGL(HI_VOID)
{	
	HI_S32                   s32Ret        = HI_SUCCESS;
    VB_CONFIG_S              stVbConf;
	SAMPLE_VO_CONFIG_S		stVoDevInfo;

	stVoDevInfo.VoDev = SAMPLE_VO_DEV_UHD;
	stVoDevInfo.enVoIntfType = VO_INTF_HDMI;
    stVoDevInfo.enIntfSync        = VO_OUTPUT_1080P60;
    stVoDevInfo.u32BgColor        = COLOR_RGB_BLUE;
    stVoDevInfo.enPixFormat       = PIXEL_FORMAT_YVU_SEMIPLANAR_420;
    stVoDevInfo.stDispRect.s32X        = 0;
    stVoDevInfo.stDispRect.s32Y        = 0;
    stVoDevInfo.stDispRect.u32Width        = WIDTH;
    stVoDevInfo.stDispRect.u32Height        = HEIGHT;
    stVoDevInfo.stImageSize.u32Width       = WIDTH;
    stVoDevInfo.stImageSize.u32Height       = HEIGHT;
    stVoDevInfo.enVoPartMode      = VO_PART_MODE_SINGLE;
    stVoDevInfo.u32DisBufLen      = 3;
    stVoDevInfo.enDstDynamicRange = DYNAMIC_RANGE_SDR8;
	stVoDevInfo.enVoMode          = VO_MODE_1MUX;

    /******************************************
     step  1: init variable
    ******************************************/
    memset(&stVbConf, 0, sizeof(VB_CONFIG_S));

    /******************************************
     step 2: mpp system init.
    ******************************************/
    s32Ret = SAMPLE_COMM_SYS_Init(&stVbConf);
    if (HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("system init failed with %d!\n", s32Ret);
        goto SAMPLE_HIFB_StandarMode_0;
    }

    /******************************************
     step 3: Start VO device.
     NOTE: Step 3 is optional when VO is running on other system.
    ******************************************/
    s32Ret = SAMPLE_COMM_VO_StartVO(&stVoDevInfo);
    if (HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("SAMPLE_COMM_VO_StartVO failed with %d!\n", s32Ret);
        goto SAMPLE_HIFB_StandarMode_0;
    }

    /******************************************
     step 4:  start hifb.
    *****************************************/
	/*LittlevGL init*/
	lv_init();
	
	/*Linux frame buffer device init*/
	fbdev_init();
	
	/*A small buffer for LittlevGL to draw the screen's content*/
	static lv_color_t buf[DISP_BUF_SIZE];
	
	/*Initialize a descriptor for the buffer*/
	static lv_disp_draw_buf_t disp_buf;
	lv_disp_draw_buf_init(&disp_buf, buf, NULL, DISP_BUF_SIZE);
	
	/*Initialize and register a display driver*/
	static lv_disp_drv_t disp_drv;
	lv_disp_drv_init(&disp_drv);
	disp_drv.draw_buf	= &disp_buf;
	disp_drv.flush_cb	= fbdev_flush;
	disp_drv.hor_res	= WIDTH;
	disp_drv.ver_res	= HEIGHT;
	lv_disp_drv_register(&disp_drv);
	
	/*Create a Demo*/
	//lv_demo_widgets();
	lv_demo_benchmark();
	
	/*Handle LitlevGL tasks (tickless mode)*/
	while(1) {
		lv_task_handler();
		usleep(5000);
	}
	
	SAMPLE_COMM_VO_StopVO(&stVoDevInfo);
SAMPLE_HIFB_StandarMode_0:
	SAMPLE_COMM_SYS_Exit();
	
	return s32Ret;
}


/******************************************************************************
* function    : main()
* Description : main
******************************************************************************/
#ifdef __HuaweiLite__
int app_main(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
	HI_S32 s32Index;
    HI_S32 s32Ret = HI_FAILURE;
	HI_U32 u32VoIntfType = 0;

    if (argc < 2 || argc > 2)
    {
        SAMPLE_VIO_Usage(argv[0]);
        return HI_FAILURE;
    }
	
    signal(SIGINT, SAMPLE_VIO_HandleSig);
    signal(SIGTERM, SAMPLE_VIO_HandleSig);

    s32Index = atoi(argv[1]);
    switch (s32Index)
    {
        case 0:
            s32Ret = SAMPLE_HIFB_LVGL();
            break;
		
        case 1:
            s32Ret = SAMPLE_VIO_ViVpssLowDelay(u32VoIntfType);
            break;

        case 2:
            s32Ret = SAMPLE_VIO_FPN(u32VoIntfType);
            break;

        case 3:
            s32Ret = SAMPLE_VIO_ViWdrSwitch(u32VoIntfType);
            break;

        case 4:
            s32Ret = SAMPLE_VIO_Rotate(u32VoIntfType);
            break;

        case 5:
            s32Ret = SAMPLE_VIO_VPSS_VO_MIPI_TX(u32VoIntfType);
            break;

        default:
            SAMPLE_PRT("the index %d is invaild!\n",s32Index);
            SAMPLE_VIO_Usage(argv[0]);
            SAMPLE_VIO_MsgExit();
            return HI_FAILURE;
    }

    if (HI_SUCCESS == s32Ret)
    {
        SAMPLE_PRT("sample_vio exit success!\n");
    }
    else
    {
        SAMPLE_PRT("sample_vio exit abnormally!\n");
    }

    SAMPLE_VIO_MsgExit();

    return s32Ret;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */
