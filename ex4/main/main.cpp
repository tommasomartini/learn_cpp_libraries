#include <iostream>
#include "greet.hpp"

using namespace std;

int main() {
    string name = "World";
    string greetings = greet(name);
    cout << greetings << endl;
    return 0;
}

