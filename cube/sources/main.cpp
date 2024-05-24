
#include <stdio.h>
#include <stdlib.h>
#include <map>

#include "./luahelper.h"
#include "./command_build.h"

int main(int argc, char** argv) {
    if(argc <= 1) {
        printf("Arguments invalid.\n");
        exit(-1);
    }
    
    std::map<const char*, const char*> commands;
    commands["build"] = command_build;
    
    const char* command_name = argv[1];
    int ret = do_lua_source(command_name);
    if(ret != 0) {
        return ret;
    }
    
    return 0;
}
