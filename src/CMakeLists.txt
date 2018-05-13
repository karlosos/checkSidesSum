project(checksidessum)

set(HEADER_FILES
        InputProcessor.h)

set(SOURCE_FILES
        InputProcessor.cpp)

add_library(checksidessum STATIC ${SOURCE_FILES} ${HEADER_FILES})
