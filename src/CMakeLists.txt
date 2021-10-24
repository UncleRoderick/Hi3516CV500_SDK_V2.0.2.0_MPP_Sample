aux_source_directory (. SRC_LIST)

add_executable (EXEC_MPP_SAMPLE ${SRC_LIST})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(EXEC_MPP_SAMPLE pthread dl m
	${CMAKE_SOURCE_DIR}/lib/libmpi.a 
	${CMAKE_SOURCE_DIR}/lib/libhdmi.a
	${CMAKE_SOURCE_DIR}/lib/lib_hiae.a 
	${CMAKE_SOURCE_DIR}/lib/libisp.a 
	${CMAKE_SOURCE_DIR}/lib/lib_hidehaze.a 
	${CMAKE_SOURCE_DIR}/lib/lib_hidrc.a 
	${CMAKE_SOURCE_DIR}/lib/lib_hildci.a 
	${CMAKE_SOURCE_DIR}/lib/lib_hicalcflicker.a 
	${CMAKE_SOURCE_DIR}/lib/lib_hiawb.a 
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
