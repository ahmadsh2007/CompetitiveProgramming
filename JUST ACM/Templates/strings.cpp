#include <iostream>
#include <string>

using namespace std;

int main(){
    string name = "Ahmad Shatnawi";

    name.size();
    name.length();

    // returns index of first char
    name.find("Ahmad");


    int position = 0;
    int length = 0;
    name.substr(position, length);

    char x = '.';
    name.push_back(x);
    name.pop_back();

    string str = " The Goat.";
    name.insert(position, str);

    name.replace(position, length, str);
}