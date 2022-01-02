CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CMAKE_SYSTEM_NAME Linux)

SET(CMAKE_SYSTEM_PROCESSOR arm)

SET(TOOLCHAIN_DIR /opt/hisi-linux/x86-arm/arm-himix200-linux)

SET(CMAKE_C_COMPILER /opt/hisi-linux/x86-arm/arm-himix200-linux/bin/arm-himix200-linux-gcc)
SET(CMAKE_CXX_COMPILER /opt/hisi-linux/x86-arm/arm-himix200-linux/bin/arm-himix200-linux-g++)

SET(CMAKE_FIND_ROOT_PATH  ${TOOLCHAIN_DIR}
 ${TOOLCHAIN_DIR}/arm-himix200-linux/include
 ${TOOLCHAIN_DIR}/arm-himix200-linux/lib )

SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)

SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

SET(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

PROJECT(Hi3516CV500_SDK_V2.0.2.0_MPP_Sample)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -Dhi3516cv500 -DHI_XXXX -lpthread -lm -ldl -DISP_V2 -lstdc++ -Wall -mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -fno-aggressive-loop-optimizations -ldl -ffunction-sections -fdata-sections -O2 -fstack-protector-strong -fPIC -Wall -DHI_RELEASE -Wno-error=implicit-function-declaration -DVER_X=1 -DVER_Y=0 -DVER_Z=0 -DVER_P=0 -DVER_B=10 -DUSER_BIT_32 -DKERNEL_BIT_32 -Wno-date-time -DSENSOR0_TYPE=SONY_IMX335_MIPI_5M_30FPS_12BIT -DSENSOR1_TYPE=SONY_IMX327_MIPI_2M_30FPS_12BIT -DHI_ACODEC_TYPE_INNER -DHI_ACODEC_TYPE_HDMI")


#if use hispark LCD, use this c flags.
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -Dhi3516cv500 -DHI_XXXX -lpthread -lm -ldl -DISP_V2 -lstdc++ -Wall -mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -fno-aggressive-loop-optimizations -ldl -ffunction-sections -fdata-sections -O2 -fstack-protector-strong -fPIC -Wall -DHI_RELEASE -Wno-error=implicit-function-declaration -DVER_X=1 -DVER_Y=0 -DVER_Z=0 -DVER_P=0 -DVER_B=10 -DUSER_BIT_32 -DKERNEL_BIT_32 -Wno-date-time -DSENSOR0_TYPE=SONY_IMX335_MIPI_5M_30FPS_12BIT -DSENSOR1_TYPE=SONY_IMX327_MIPI_2M_30FPS_12BIT -DHI_ACODEC_TYPE_INNER -DHI_ACODEC_TYPE_HDMI -DHISPARK_LCD")

INCLUDE_DIRECTORIES(include)

add_subdirectory(src)


