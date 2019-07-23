# Lua library from Multi Theft Auto
add_subdirectory(lua-mta)

# MongoDB C Driver
set(ENABLE_TESTS OFF CACHE BOOL "")
set(ENABLE_EXAMPLES OFF CACHE BOOL "")
set(ENABLE_UNINSTALL OFF CACHE BOOL "")
set(ENABLE_STATIC ON CACHE BOOL "")
add_subdirectory(mongo-c-driver)

# Lua wrapper for MongoDB C Driver
add_library(lua-mongo STATIC
    lua-mongo/src/bson.c
    lua-mongo/src/bsontype.c
    lua-mongo/src/bulkoperation.c
    lua-mongo/src/client.c
    lua-mongo/src/collection.c
    lua-mongo/src/cursor.c
    lua-mongo/src/database.c
    lua-mongo/src/flags.c
    lua-mongo/src/gridfs.c
    lua-mongo/src/gridfsfile.c
    lua-mongo/src/gridfsfilelist.c
    lua-mongo/src/objectid.c
    lua-mongo/src/readprefs.c
    lua-mongo/src/util.c
    lua-mongo/src/main.c
)

target_include_directories(lua-mongo PRIVATE lua-mongo/src ${CMAKE_CURRENT_BINARY_DIR}/mongo-c-driver/src/libmongoc/src mongo-c-driver/src/libmongoc/src)
target_include_directories(lua-mongo PUBLIC lua-mongo/include)
target_link_libraries(lua-mongo PRIVATE lua mongoc_static bson_static)
set_target_properties(lua-mongo PROPERTIES LINKER_LANGUAGE C)
