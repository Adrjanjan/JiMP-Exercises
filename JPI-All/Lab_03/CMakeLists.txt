
project(lab_03)


set(HEDEAR_FILES Lab_03.h)
set(SOURCE_FILES Lab_03.cpp)

add_library(liblab_03 STATIC ${SOURCE_FILES})
target_include_directories(liblab_03 PUBLIC .)

add_executable(lab_03 ${SOURCE_FILES} main.cpp)

target_link_libraries(lab_03 liblab_03)

