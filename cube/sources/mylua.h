
#ifndef CUBE_LUAHELPER_H
#define CUBE_LUAHELPER_H

#include "./header.h"
#include "./mylibs.h"

extern "C" {
#include "../../cube-packs/lua/sources/lualib.h"
#include "../../cube-packs/lua/sources/lauxlib.h"
}

void mylua_set_global_string(lua_State* L, const char* name, const char* value) {
    lua_pushstring(L, value);
    lua_setglobal(L, name);
}

int mylua_execute_source(const char* source) {
    lua_State* L = luaL_newstate();
    if(L == NULL) {
        return -1;
    }
    
    luaL_openlibs(L);
    mylua_set_global_string(L, "cube_os_name", get_os_name().c_str());
    mylua_set_global_string(L, "cube_project_dir", get_cwd().c_str());
    mylua_set_global_string(L, "cube_archive_dir", (get_cwd() + "/archives").c_str());
    mylua_set_global_string(L, "cube_build_dir", (get_cwd() + "/cube-build").c_str());
    mylua_set_global_string(L, "cube_packs_dir", (get_cwd() + "/cube-packs").c_str());

    int ret = luaL_dostring(L, source);
    if(ret != LUA_OK) {
        return ret;
    }
    
    lua_close(L);
    
    return 0;
}

#endif //CUBE_LUAHELPER_H
