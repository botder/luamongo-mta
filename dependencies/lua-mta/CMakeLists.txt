include(FetchContent)

FetchContent_Declare(mtasa-blue
    GIT_REPOSITORY "https://github.com/multitheftauto/mtasa-blue.git"
    GIT_TAG        master
)

FetchContent_GetProperties(mtasa-blue)
if(NOT mtasa-blue_POPULATED)
    FetchContent_Populate(mtasa-blue)

    set(MTASA_ROOT "${mtasa-blue_SOURCE_DIR}")
    set(MTASA_LUA_DIR "${MTASA_ROOT}/vendor/lua/src")
    
    file(GLOB MTASA_LUA_SOURCES "${MTASA_LUA_DIR}/*.c" "${MTASA_LUA_DIR}/*.h")

    if(WIN32)
        add_library(lua SHARED ${MTASA_LUA_SOURCES})
        target_compile_definitions(lua PUBLIC LUA_BUILD_AS_DLL)
        target_compile_definitions(lua PUBLIC _CRT_SECURE_NO_WARNINGS)
    else()
        add_library(lua STATIC ${MTASA_LUA_SOURCES})
    endif()

    set_target_properties(lua PROPERTIES OUTPUT_NAME "lua5.1")
    target_include_directories(lua PUBLIC ${MTASA_LUA_DIR})
endif()
