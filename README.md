# Hi3516CV500_SDK_V2.0.2.0_Sample_MPP
Sample cmake project for Hi3516DV300/Hi3156CV500/Hi3516AV300 base on SDK Hi3516CV500_SDK_V2.0.2.0.

编译事项：
1.注意事项
  
  本工程默认Sensor为IMX335，确认板子的Sensor是否一致，如果不一致请修改CMakeLists.txt中的CMAKE_C_FLAGS.
  如果板子是单Sensor的，请将SENSOR1_TYPE也设置为SENSOR0_TYPE的Sensor（或者其他Sensor），不然会报错SENSOR1_TYPE未定义。
  
  -DSENSOR0_TYPE=SONY_IMX335_MIPI_5M_30FPS_12BIT 
  
  -DSENSOR1_TYPE=SONY_IMX327_MIPI_2M_30FPS_12BIT
  
  ################# select sensor type for your sample ###############################
  ####    SONY_IMX335_MIPI_5M_30FPS_12BIT              #################
  ####    SONY_IMX335_MIPI_5M_30FPS_10BIT_WDR2TO1      #################
  ####    SONY_IMX335_MIPI_4M_30FPS_12BIT              #################
  ####    SONY_IMX335_MIPI_4M_30FPS_10BIT_WDR2TO1      #################
  ####    SONY_IMX327_MIPI_2M_30FPS_12BIT              #################
  ####    SONY_IMX327_MIPI_2M_30FPS_12BIT_WDR2TO1      #################
  ####    SONY_IMX327_2L_MIPI_2M_30FPS_12BIT           #################
  ####    SONY_IMX327_2L_MIPI_2M_30FPS_12BIT_WDR2TO1   #################
  ####    SONY_IMX307_MIPI_2M_30FPS_12BIT              #################
  ####    SONY_IMX307_MIPI_2M_30FPS_12BIT_WDR2TO1      #################
  ####    SONY_IMX307_2L_MIPI_2M_30FPS_12BIT           #################
  ####    SONY_IMX307_2L_MIPI_2M_30FPS_12BIT_WDR2TO1   #################
  ####    SONY_IMX458_MIPI_1M_129FPS_10BIT             #################
  ####    SONY_IMX458_MIPI_2M_90FPS_10BIT              #################
  ####    SONY_IMX458_MIPI_4M_40FPS_10BIT              #################
  ####    SONY_IMX458_MIPI_4M_60FPS_10BIT              #################
  ####    SONY_IMX458_MIPI_8M_30FPS_10BIT              #################
  ####    SONY_IMX458_MIPI_12M_20FPS_10BIT             #################
  ####    PANASONIC_MN34220_LVDS_2M_30FPS_12BIT        #################
  ####    OMNIVISION_OS04B10_MIPI_4M_30FPS_10BIT       #################
  ####    OMNIVISION_OS05A_MIPI_4M_30FPS_12BIT         #################
  ####    OMNIVISION_OS05A_MIPI_4M_30FPS_10BIT_WDR2TO1 #################
  ####    OMNIVISION_OS08A10_MIPI_8M_30FPS_10BIT       #################
  ####    GALAXYCORE_GC2053_MIPI_2M_30FPS_10BIT        #################
  ####    SMART_SC4210_MIPI_3M_30FPS_12BIT             #################
  ####    SMART_SC4210_MIPI_3M_30FPS_10BIT_WDR2TO1     #################
  ####    OMNIVISION_OV12870_MIPI_1M_240FPS_10BIT      #################
  ####    OMNIVISION_OV12870_MIPI_2M_120FPS_10BIT      #################
  ####    OMNIVISION_OV12870_MIPI_8M_30FPS_10BIT       #################
  ####    OMNIVISION_OV12870_MIPI_12M_30FPS_10BIT      #################
  ####    SONY_IMX415_MIPI_8M_30FPS_12BIT              #################
  ####    SONY_IMX415_MIPI_8M_20FPS_12BIT              #################

2.创建build目录
  
  mkdir build

3.进入build目录生成Makefile
  
  cd build
  
  cmake ..
  
4.build目录编译生成可执行文件
  
  make
  
5.运行可执行程序
  
  生成的可执行文件为bin目录下的EXEC_MPP_SAMPLE.
  
  复制到板子上即可运行，运行前请确保加载ko文件。

