#include <iostream>
#include <string>

using namespace std;

string greet(const string&);

int main() {
    string name = "World";
    string greetings = greet(name);
    cout << greetings << endl;
    return 0;
}

string greet(const string& name) {
    return "Hello " + name + "!";
}

