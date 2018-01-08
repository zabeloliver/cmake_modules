message(STATUS "Hello")
# this one is important
#SET(TOOL_PATH $ENV{TOOLCHAIN})
SET(CMAKE_SYSTEM_NAME GNU)
set(TOOL_PATH ${PROJECT_SOURCE_DIR}/toolchain)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# specify the cross compiler

SET(ENV{BIN_RX} "${TOOL_PATH}/bin/")
SET(ENV{INC_RX} "${TOOL_PATH}/inc/")
SET(CMAKE_C_COMPILER "${TOOL_PATH}/bin/ccrx.exe")
SET(CMAKE_CXX_COMPILER "${TOOL_PATH}/bin/ccrx.exe")
SET(CMAKE_ASM_COMPILER "${TOOL_PATH}/bin/asrx.exe")
set(CMAKE_LINKER "${TOOL_PATH}/bin/rlink.exe")

# sepcify how compiler works
set(CMAKE_C_LINK_EXECUTABLE "<CMAKE_LINKER> -form=abs -output=<TARGET>.abs <OBJECTS>")

# where is the target environment 
SET(CMAKE_FIND_ROOT_PATH "${TOOL_PATH}")
include_directories("${TOOL_PATH}/inc/")

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)


