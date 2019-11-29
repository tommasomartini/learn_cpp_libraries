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


