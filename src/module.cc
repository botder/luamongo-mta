// Copyright (c) 2012 Marcus Bauer (mabako@gmail.com)
// see LICENSE for details.

extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

#include <cstring>
#include <cstddef>
#include <lua-mongo/mongo.h>

#ifdef WIN32
    #define MTAEXPORT extern "C" __declspec(dllexport)
#else
    #define MTAEXPORT extern "C"
#endif

#define MODULE_NAME         "MongoDB Database Adapter/luamongo(8e22adc8)"
#define MODULE_AUTHOR       "mabako"
#define MODULE_VERSION      4

static constexpr std::size_t kMaxInfoLength = 128;

MTAEXPORT bool InitModule(void* /*unused*/, char* module_name, char* module_author, float* module_version)
{
    std::strncpy(module_name, MODULE_NAME, kMaxInfoLength );
    std::strncpy(module_author, MODULE_AUTHOR, kMaxInfoLength );
    *module_version = MODULE_VERSION;
    return true;
}

MTAEXPORT void RegisterFunctions(lua_State* luaVM)
{
    lua_settop(luaVM, 0);
    lua_pushstring(luaVM, "mongo");
	luaopen_mongo(luaVM);
}

MTAEXPORT bool DoPulse()
{
    return true;
}

MTAEXPORT bool ShutdownModule()
{
    return true;
}
