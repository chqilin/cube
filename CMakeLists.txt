cmake_minimum_required(VERSION 3.26)

project("cube")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB LUA_SOURCE_FILES "cube-packs/lua/sources/*.c")
add_library("lua")
target_sources("lua" PRIVATE ${LUA_SOURCE_FILES})

file(GLOB CUBE_SOURCE_FILES "cube/sources/*.cpp")
add_executable("cube")
target_sources("cube" PRIVATE ${CUBE_SOURCE_FILES})
target_include_directories("cube" PRIVATE
        "./cube-packs/eokas-base/arcives/include")
target_link_directories("cube" PRIVATE
        "./cube-packs/eokas-base/arcives/lib/macOS/${CMAKE_BUILD_TYPE}")
target_link_libraries("cube" PRIVATE "lua" "eokas-base")
