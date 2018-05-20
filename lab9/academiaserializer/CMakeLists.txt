
project(serialization)

set(HEDEAR_FILES Building.h BuildingRepository.h JsonSerializer.h Room.h Serialization.h Serializable.h Serializer.h XmlSerializer.h)
set(SOURCE_FILES Building.cpp BuildingRepository.cpp JsonSerializer.cpp Room.cpp Serialization.cpp Serializable.cpp Serializer.cpp XmlSerializer.cpp)

add_library(libserialization STATIC ${SOURCE_FILES})
target_include_directories(libserialization PUBLIC .)

add_executable(serialization ${SOURCE_FILES} main.cpp)

target_link_libraries(serialization libserialization)

