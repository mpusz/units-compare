# Physical Units libraries comparison

This small project strives to compare multiple physical units libraries.

## Dependencies

```bash
conan remote add conan-mpusz https://api.bintray.com/conan/mpusz/conan-mpusz
```

## Building

```bash
mkdir build && cd build
conan install .. -pr <your_conan_profile> -s compiler.cppstd=20 -b=outdated -u
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
cmake --build .
```
