cmake_minimum_required(VERSION 3.3)
project(Serializacja)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Serialization/Serialization/src/file/FileReader.c
    Serialization/Serialization/src/file/FileReader.h
    Serialization/Serialization/src/serializer/SerializationReader.c
    Serialization/Serialization/src/serializer/SerializationReader.h
    Serialization/Serialization/src/serializer/SerializationWriter.c
    Serialization/Serialization/src/serializer/SerializationWriter.h
    Serialization/Serialization/src/type/Type.h
    Serialization/Serialization/src/main.c)

add_executable(Serializacja ${SOURCE_FILES})