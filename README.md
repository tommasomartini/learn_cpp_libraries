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

