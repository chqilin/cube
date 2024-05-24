cmake_minimum_required(VERSION 3.26)

project("cube")


file(GLOB LUA_SOURCE_FILES "cube-packs/lua/*.c")
add_library("cube-packs/lua")
target_sources("cube-packs/lua" PRIVATE ${LUA_SOURCE_FILES})

file(GLOB CUBE_SOURCE_FILES "cube/*.cpp")
add_executable("cube")
target_sources("cube" PRIVATE ${CUBE_SOURCE_FILES})
target_link_libraries("cube" PRIVATE "cube-packs/lua")
