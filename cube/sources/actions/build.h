
#ifndef CUBE_COMMAND_BUILD_H
#define CUBE_COMMAND_BUILD_H

const char* action_build = R"(
local os_name = cube_os_name;
local project_dir = cube_project_dir;
local project_file = project_dir .. "/cube.lua";

print("os name: ".. os_name);
print("project file: "..project_file);

local project_chunk = loadfile(project_file);
if project_chunk == nil then
    print("Can not find the file 'cube.lua' in the project directory.");
    return;
end
local project_info = project_chunk();
print("project name: " .. project_info.name);
print("project version: " .. project_info.version);

local build_rules_file = cube_build_dir .. "/build.ninja";
print("build_rules_file: " .. build_rules_file);
local stream = io.open(build_rules_file, "w");
if stream == nil then
    print("Can not write build.ninja");
end

do
    stream:write("ninja_required_version = 1.10\n");
    stream:write("\n");

    stream:write("builddir = "..cube_build_dir.."\n");
    stream:write("cflags = -Wall -std=c++17 -O3\n");
    stream:write("lflags = \n");
    stream:write("defines = \n");
    stream:write("includes = \n");
    stream:write("libraries = \n");
    stream:write("runtimes = \n");
    stream:write("\n");

    stream:write("rule cc\n");
    stream:write("    command = clang++ -o $out $in -c $cflags $defines $includes\n");
    stream:write("rule ar\n");
    stream:write("    command = ar -r $out $in\n");
    stream:write("rule so\n");
    stream:write("    command = clang++ -o $out $in -shared -fPIC $lflags $libraries $runtimes\n");
    stream:write("rule ex\n");
    stream:write("    command = clang++ -o $out $in $lflags $libraries $runtimes\n");
    stream:write("\n");
end

local build_info = project_info.build;

local outputs = {};


stream:close();


)";

#endif //CUBE_COMMAND_BUILD_H
