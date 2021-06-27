Please install gcc, cmake & ctest

To build & run unit tests, do the following:

first time:
git submodule update --init
mkdir build && cd build
cmake ..

subsequent times:
make -j$(nproc)
ctest --verbose