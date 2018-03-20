
project(lab_04)

set(HEDEAR_FILES Lab04.h)
set(SOURCE_FILES Lab04.cpp)

add_library(liblab_04 STATIC ${SOURCE_FILES})
target_include_directories(liblab_04 PUBLIC .)

add_executable(lab_04 ${SOURCE_FILES} main.cpp)

target_link_libraries(lab_04 liblab_04)
