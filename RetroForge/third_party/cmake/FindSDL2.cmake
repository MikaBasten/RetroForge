# FindSDL2.cmake

find_path(SDL2_INCLUDE_DIR SDL2/SDL.h
    PATH_SUFFIXES include
)

find_library(SDL2_LIBRARY
    NAMES SDL2
    PATH_SUFFIXES lib
)

find_library(SDL2MAIN_LIBRARY
    NAMES SDL2main
    PATH_SUFFIXES lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2 DEFAULT_MSG SDL2_LIBRARY SDL2_INCLUDE_DIR SDL2MAIN_LIBRARY)

mark_as_advanced(SDL2_INCLUDE_DIR SDL2_LIBRARY SDL2MAIN_LIBRARY)
