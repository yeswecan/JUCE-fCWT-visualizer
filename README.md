# fCWT Visualizer made in Juce

## About <a name = "about"></a>

Visualizing [fCWT](https://github.com/fastlib/fCWT) features using JUCE framework.

## Compiling <a name = "getting_started"></a>

fCWT is a submodule here, but you should build it from source:
```
$ cd fCWT
$ mkdir -p build
$ cd build
$ cmake ../ -DBUILD_BENCHMARK=OFF
$ make 
$ sudo make install
```

### Deps for fCWT:
Cmake >=3.10
C++17 compiler (GCC 10+, Clang or Microsoft Visual C++ 15.7+);
FFTW >=3.3 (if you choose to use own FFTW installation)
OpenMP >=5

I had to add libomp and fftw3 includes to "header search paths" (installed both via brew) and add their libary paths via "library search paths". I had to add fCWT library via "Link binary with libraries".

### Also, from their installation section:
Please note that you'll need to configure FFTW to use OpenMP for multithreading and 256-bit vector instructions (e.g., AVX) to obtain comparable results to the benchmark. Standard configuration binaries obtained via brew or apt-get generally don't have AVX enabled.