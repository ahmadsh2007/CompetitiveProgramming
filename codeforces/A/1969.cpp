#include <iostream>
#include <vector>

int main(){
    int t; std::cin >> t;

    while(t--){
        int n; std::cin >> n;

        std::vector<int> p(n * 2);
        for (int i = 1; i < n + 1; i++) std::cin >> p[i];

        bool bestFriendOfBestFriend = 0;
        for (int i = 1; i <= n; i++){
            if (p[p[i]] == i){
                bestFriendOfBestFriend = 1;
                break;
            }
        }

        if (bestFriendOfBestFriend) std::cout << 2 << '\n';
        else std::cout << 3 << '\n';
    }
}