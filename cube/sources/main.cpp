
#include "./header.h"
#include "./mylibs.h"
#include "./mylua.h"

#include "./actions/create.h"
#include "./actions/install.h"
#include "./actions/build.h"
#include "./actions/publish.h"

#include <cstdio>
#include <cstdlib>
#include <map>

int main(int argc, char** argv) {
    if(argc <= 1) {
        printf("Arguments invalid.\n");
        exit(-1);
    }

    std::map<std::string, const char*> actions;
    // actions["create"] = action_create;
    // actions["install"] = action_install;
    actions["build"] = action_build;
    // actions["publish"] = action_publish;
    
    std::string action_name = argv[1];
    auto action_iter = actions.find(action_name);
    if(action_iter == actions.end()) {
        printf("The action '%s' is undefined.\n", action_name.c_str());
        exit(-1);
    }
    const char* action_content = action_iter->second;
    int ret = mylua_execute_source(action_content);
    if(ret != 0) {
        return ret;
    }
    
    return 0;
}
