file(GLOB_RECURSE SOURCE "./src/*.cpp" 
"./thirdparty/*/*.cpp")


file(GLOB_RECURSE HEAD
    "./include/*.h"
	"./include/*.hpp"
	"./thirdparty/*/*.h"
	"./thirdparty/*/*.hpp"
)

set_property(GLOBAL PROPERTY  libfilterFiles)
function(FilterLibFile)
    get_property(tmp GLOBAL PROPERTY libfilterFiles)
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
    set_property(GLOBAL PROPERTY libfilterFiles "${tmp}")
endfunction()

FilterLibFile(${SOURCE})
FilterLibFile(${HEAD})




INCLUDE_DIRECTORIES(
${WINDAPI_INCLUDE_PATH}
)

INCLUDE_DIRECTORIES(
${GENDATA_INCLUDE_PATH}
)

INCLUDE(../func.cmake)
build_file_tree()
init_include_path()

get_property(local_libfilterFiles GLOBAL PROPERTY libfilterFiles)

ADD_LIBRARY(${PROJECT_NAME} STATIC  ${local_libfilterFiles})



SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})