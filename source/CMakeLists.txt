CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(TecCoding)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    SET(CMAKE_C_COMPILER /usr/bin/gcc)
    SET(CMAKE_CXX_COMPILER /usr/bin/g++)

    # set(CMAKE_CXX_COMPILE_OPTIONS_PIC "-fPIC")
    # set(CMAKE_C_COMPILE_OPTIONS_PIC "-fPIC")
    add_compile_options(-fPIC)
    # set(CMAKE_C_FLAGS"$ {CMAKE_C_FLAGS} -fPIC")
    # set(CMAKE_CXX_FLAGS"$ {CMAKE_CXX_FLAGS} -fPIC")

    add_definitions(-DLINUX)
	add_definitions(-std=c++17)
    add_definitions("-Wall -g")
    include_directories("/usr/lib/gcc/x86_64-redhat-linux/10.2.0/include/c++/10.2.0")
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_definitions(-DWIN)
	add_definitions(
    -DUNICODE
    -D_CRT_SECURE_NO_DEPRECATE
    -D_CRT_NON_CONFORMING_SWPRINTFS
    -D_SCL_SECURE_NO_WARNINGS
    )
	add_definitions( "/W3 /wd4251 /wd4996 /nologo /wd4819" )
endif()

add_subdirectory(Coding)