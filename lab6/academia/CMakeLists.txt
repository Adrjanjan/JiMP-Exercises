
project(studentrepository)

set(HEDEAR_FILES StudentRepository.h StudentYear.h Student.h)
set(SOURCE_FILES StudentRepository.cpp StudyYear.cpp Student.cpp)

add_library(libstudentrepository STATIC ${SOURCE_FILES})
target_include_directories(libstudentrepository PUBLIC .)

add_executable(studentrepository ${SOURCE_FILES} main.cpp)

target_link_libraries(studentrepository libstudentrepository)
target_link_libraries(libstudentrepository libstudentrepositoryqueries)

