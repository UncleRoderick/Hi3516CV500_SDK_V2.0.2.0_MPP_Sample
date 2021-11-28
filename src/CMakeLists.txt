aux_source_directory (. SRC_LIST)

INCLUDE_DIRECTORIES(./lvgl/)

aux_source_directory (./lvgl SRC_LIST)

aux_source_directory (./lvgl/lvgl/src/core SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra SRC_LIST)

aux_source_directory (./lvgl/lvgl/src/extra/layouts/flex SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/layouts/grid SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/themes/basic SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/themes/default SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/themes/mono SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/animimg SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/calendar SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/chart SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/colorwheel SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/imgbtn SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/keyboard SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/led SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/list SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/meter SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/msgbox SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/span SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/spinbox SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/spinner SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/tabview SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/tileview SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/extra/widgets/win SRC_LIST) 

aux_source_directory (./lvgl/lvgl/src/gpu SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/misc SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/draw SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/font SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/hal SRC_LIST) 
aux_source_directory (./lvgl/lvgl/src/widgets SRC_LIST) 

aux_source_directory (./lvgl/lv_drivers/gtkdrv SRC_LIST) 
aux_source_directory (./lvgl/lv_drivers/win32drv SRC_LIST) 
aux_source_directory (./lvgl/lv_drivers/display SRC_LIST) 
aux_source_directory (./lvgl/lv_drivers/indev SRC_LIST) 
aux_source_directory (./lvgl/lv_drivers/sdl SRC_LIST) 
aux_source_directory (./lvgl/lv_drivers/wayland SRC_LIST) 

aux_source_directory (./lvgl/lv_demos/src/lv_demo_music SRC_LIST) 
aux_source_directory (./lvgl/lv_demos/src/lv_demo_music/assets SRC_LIST) 

aux_source_directory (./lvgl/lv_demos/src/lv_demo_widgets SRC_LIST) 
aux_source_directory (./lvgl/lv_demos/src/lv_demo_widgets/assets SRC_LIST) 

aux_source_directory (./lvgl/lv_demos/src/lv_demo_benchmark SRC_LIST) 
aux_source_directory (./lvgl/lv_demos/src/lv_demo_benchmark/assets SRC_LIST) 

aux_source_directory (./lvgl/lv_demos/src/lv_demo_keypad_encoder SRC_LIST) 

aux_source_directory (./lvgl/lv_demos/src/lv_demo_stress SRC_LIST) 
aux_source_directory (./lvgl/lv_demos/src/lv_demo_stress/assets SRC_LIST) 

add_executable (EXEC_MPP_SAMPLE ${SRC_LIST})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(EXEC_MPP_SAMPLE pthread dl m
	${CMAKE_SOURCE_DIR}/lib/libhdmi.a
	${CMAKE_SOURCE_DIR}/lib/lib_hiae.a 
	${CMAKE_SOURCE_DIR}/lib/libisp.a 
	${CMAKE_SOURCE_DIR}/lib/lib_hidehaze.a 
	${CMAKE_SOURCE_DIR}/lib/lib_hidrc.a 
	${CMAKE_SOURCE_DIR}/lib/lib_hildci.a 
	${CMAKE_SOURCE_DIR}/lib/lib_hicalcflicker.a 
	${CMAKE_SOURCE_DIR}/lib/lib_hiawb.a 
	${CMAKE_SOURCE_DIR}/lib/libmpi.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_imx327.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_imx327_2l.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_imx307.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_imx307_2l.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_imx458.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_mn34220.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_os05a.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_os08a10.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_gc2053.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_sc4210.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_ov12870.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_os04b10.a 
	${CMAKE_SOURCE_DIR}/lib/libsns_imx415.a
	${CMAKE_SOURCE_DIR}/lib/libsns_imx335.a
	${CMAKE_SOURCE_DIR}/lib/libVoiceEngine.a 
	${CMAKE_SOURCE_DIR}/lib/libupvqe.a 
	${CMAKE_SOURCE_DIR}/lib/libdnvqe.a
	${CMAKE_SOURCE_DIR}/lib/libsecurec.a)
