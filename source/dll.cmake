file(GLOB_RECURSE SOURCE
    "./src/*.cpp"
	"./*.cpp"
)
file(GLOB_RECURSE SOURCE_CC
	"./src/*.cc*"
	"./*.cc*"
	)
file(GLOB_RECURSE SOURCE_C
    "./src/*.c"
	"./*.c"
)

file(GLOB_RECURSE HEAD
    "./include/*.h"
	"./include/*.hpp"
	"./*.h"
	"./*.hpp"
)


set_property(GLOBAL PROPERTY  dllfilterFiles)

function(FilterDllFile)
    get_property(tmp GLOBAL PROPERTY dllfilterFiles)
    foreach(file IN ITEMS ${ARGN})
        if(${file} MATCHES  "./linux/")
            if(CMAKE_SYSTEM_NAME MATCHES "Linux")
                list(APPEND tmp ${file})
            endif()
        elseif(${file} MATCHES  "./win/")
            if(CMAKE_SYSTEM_NAME MATCHES "Windows")
                list(APPEND tmp ${file})
            endif()
        else()
            list(APPEND tmp ${file})
        endif()
    endforeach()
    set_property(GLOBAL PROPERTY dllfilterFiles "${tmp}")
endfunction()


FilterDllFile(${SOURCE})
FilterDllFile(${SOURCE_CC})
FilterDllFile(${SOURCE_C})
FilterDllFile(${HEAD})


INCLUDE_DIRECTORIES(
)

LINK_DIRECTORIES(
${LIBRARY_OUTPUT_PATH}
)

INCLUDE(../func.cmake)

build_file_tree()
init_include_path()

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    link_libraries(pthread uuid dl)
endif()

get_property(local_dllfilterFiles GLOBAL PROPERTY dllfilterFiles)

ADD_LIBRARY(${PROJECT_NAME} SHARED ${local_dllfilterFiles})


if(CMAKE_SYSTEM_NAME MATCHES "Linux")
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
	target_link_libraries(${PROJECT_NAME} ws2_32.lib)
endif()




