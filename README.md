# learn_cpp_libraries
Exercises to learn how static and dynamic libraries work in C++

# Exercise 1
Simple hello-world using a function in the same file.
The function is declared before the main and defined after the main.
Compile with:
```
g++ main.cpp -o main
```

# Exercise 2
The function greet() is moved to a cpp file in the same folder as the main.
Compile with:
```
g++ main.cpp -o main
```

# Exercise 3
The function greet() is declared in a .hpp file and defined in a .cpp file.
Both files are in the same folder as the main.
Compile with:
```
g++ main.cpp greet.cpp -o main
```

# Exercise 4
The function greet() is declared in a .hpp file and defined in a .cpp file.
Both files are in a different folder than the main.
Compile with:
```
g++ main.cpp ../greet/greet.cpp -o main -I ../greet
```

# Exercise 5
Understand the "Life of an Elf". Exercise carried out in the ex1 folder.

Based on: https://kishuagarwal.github.io/life-of-a-binary.html

## Preprocessing
See the output of:
```
g++ -E main.cpp
```

## Compilation
See the output of:
```
g++ -S main.cpp
```
It produces a .s file with human-readable assemply code.

## Assembly
Turn the source file into a .o object file by:
```
g++ -c main.cpp
```
You can see the content of this file with:
```
objdump -d main.o
```
main.o is an ELF: a binary file used in Linux. See its header with:
```
eu-readelf -h main.o
```

## Linking
The g++ command automatically invokes the linker, usually ld. To see how the linker is invoked, use `g++ -v main.cpp`.

## Loading
When you actually run the binary, an `execve` system call is invoken, which loads the binary in memory. At this point dynamically linked libraries are also loaded in memory.

# Exercise 6
Compile and link greet as a static library.

1. Compile greet to an object file (format .o). Since its header is in a different folder, we need to use `-I` to tell the compiler where to find it: `g++ -c src/greet.cpp -o ./bin/greet.o -I ./include`
1. Turn the greet.o object file into an archive, that is a static library, using `ar`: `ar rcs lib/libgreet.a bin/greet.o` Note that the archive we create must start with "lib" and end in ".a" for the linker to find it.
1. Compile the main file: `g++ src/main.cpp -I ./include/ -L ./lib/ -lgreet -o ./bin/main`
Here we are doing multiple things:
   1. `-I ./include/` tells the compiler where to find the header files (only `greet.hpp` in this case);
   1. `-L ./lib/` tells the compiler where the static library is;
   1. `-lgreet` tells the linker to statically link a library called "libgreet.a".

# Exercise 7
Compile and link greet as a dynamic library.

1. Compile greet to an object file. We need the `-fPIC` directive to output a Position Independent Code, which is necessary to dynamically link: `g++ -c -fPIC ./src/greet.cpp -I ./include/ -o ./bin/greet.o`
1. Turn the greet.o object file into a shared library. Also in this case the output must start with "lib", but it will end in ".so" (for Shared Object): `g++ -shared ./bin/greet.o -o ./lib/libgreet.so`
1. Compile the main: `g++ ./src/main.cpp -I ./include/ -L ./lib/ -l greet -o ./bin/main`
1. The loader must know where the library to load and link is. Therefore the folder containing the library must be put into the `LD_LIBRARY_PATH` environment variable: `export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH`
1. Now the main can be run: `./bin/main`

