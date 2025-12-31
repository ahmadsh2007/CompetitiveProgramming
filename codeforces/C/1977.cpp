#include <iostream>

int main(){
    int t; std::cin >> t;

    while(t--){
        int n; std::cin >> n;

        std::string s; std::cin >> s;

        long long cost = 0, balance = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '(') {
                balance++;
                cost -= (i + 1);
            } else if (s[i] == ')'){
                balance -= 1;
                cost += (i + 1);
            } else {
                if (balance > 0){
                    balance -= 1;
                    cost += (i + 1);
                } else {
                    balance += 1;
                    cost -= (i + 1);
                }
            }
        }

        std::cout << cost << '\n';
    }
}