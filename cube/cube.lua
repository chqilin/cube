name = "cube";
version = "1.0.0";
cube = "1.0.0";
dependencies = {
    lua = "5.4.6",
    ninja = "0.0.1",
};
build = {
    type = "executable",
    flags = {""},
    headers = {
        "./src/cube"
    },
    sources = {
        "./src/cube"
    },
};
deploy = {

};
