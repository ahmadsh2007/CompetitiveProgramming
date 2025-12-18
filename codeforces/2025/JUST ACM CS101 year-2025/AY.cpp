#include <iostream>
#include <string>

int main(){
    std::string name;
    getline(std::cin, name);
    std::cout << "Hello, " << name;
}