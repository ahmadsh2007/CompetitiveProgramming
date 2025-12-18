#include <iostream>
#include <string>
#include <cmath>

int main(){
    int t; std::cin >> t;

    while(t--){
        std::string s; std::cin >> s;
        
        s = 'R' + s + 'R';
        int result = 1;
        int last = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == 'R') {
                result = std::max(result, i - last);
                last = i;
            }
        }

        std::cout << result << '\n';
    }
}