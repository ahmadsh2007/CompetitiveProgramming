#include <iostream>
#include <string>

int main(){
    std::string s; std::cin >> s;
    int t; std::cin >> t;
    
    for (int i = 0; i < t; i++){
        int op; std::cin >> op;
        if (op == 1){
            std::string string2append; std::cin >> string2append;
            s += string2append;
        } else if(op == 2) {
            int eraseLast; std::cin >> eraseLast;
            s.erase(s.size() - eraseLast);
        } else if(op == 3) std::cout << s << '\n';
    }
}