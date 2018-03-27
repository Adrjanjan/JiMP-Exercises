project(lab_02)

set(HEDEAR_FILES Lab_02.h)
set(SOURCE_FILES Lab_02.cpp)

add_library(liblab_02 STATIC ${SOURCE_FILES})
target_include_directories(liblab_02 PUBLIC .)

add_executable(lab_02 ${SOURCE_FILES} main.cpp)

target_link_libraries(lab_02 liblab_02)

