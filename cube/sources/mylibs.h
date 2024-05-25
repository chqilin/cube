
#ifndef CUBE_LIBS_H
#define CUBE_LIBS_H

#include "./header.h"

#include <string>

#if _EOKAS_OS == _EOKAS_OS_WIN64
#include <direct.h>
#else
#include <unistd.h>
#endif

std::string get_os_name() {
    #if _EOKAS_OS == _EOKAS_OS_WIN64
    return "Windows";
    #elif _EOKAS_OS == _EOKAS_OS_MACOS
    return "macOS";
    #elif _EOKAS_OS == _EOKAS_OS_LINUX
    return "Linux";
    #endif
}

std::string get_cwd() {
    char cwd[1024];
#if _EOKAS_OS == _EOKAS_OS_WINDOWS
    _getcwd(cwd, sizeof(cwd));
#else
    getcwd(cwd, sizeof(cwd));
#endif
    return cwd;
}

#endif //CUBE_LIBS_H
