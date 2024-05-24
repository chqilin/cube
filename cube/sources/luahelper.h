
#ifndef CUBE_LUAHELPER_H
#define CUBE_LUAHELPER_H

extern "C" {
#include "../../lua/lualib.h"
#include "../../lua/lauxlib.h"
}

int do_lua_source(const char* source) {
    lua_State* L = luaL_newstate();
    if(L == NULL) {
        return -1;
    }
    
    luaL_openlibs(L);
    
    int ret = luaL_dostring(L, source);
    if(ret != LUA_OK) {
        return ret;
    }
    
    lua_close(L);
    
    return 0;
}

int do_lua_file(const char* filename) {
    lua_State* L = luaL_newstate();
    if(L == NULL) {
        return -1;
    }
    
    luaL_openlibs(L);
    
    int ret = luaL_dofile(L, filename);
    if(ret != LUA_OK) {
        return ret;
    }
    
    lua_close(L);
    
    return 0;
}

#endif //CUBE_LUAHELPER_H
