project(MyModule C)

set(EXECUTABLE_NAME MyModule.abs)
set(SRC_FILES
	${PROJECT_SOURCE_DIR}/module.c
	${PROJECT_SOURCE_DIR}/main.c
)
#include_directories(${PROJECT_SOURCE_DIR})
add_executable(${EXECUTABLE_NAME} ${SRC_FILES})
