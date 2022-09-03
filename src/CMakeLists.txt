set(SOURCES
        Emulator.cpp
        Cartridge.cpp
        CPUInstruction.cpp
        X.cpp)

set(HEADERS
        ExampleClass.h
        Cartridge.h
        CPU.h
        CPUInstruction.h
        Definitions.h)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES} ${HEADERS})