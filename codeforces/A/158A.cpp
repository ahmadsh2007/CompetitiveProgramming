#include <iostream>
 
int main() {
    int n, k;
    std::cin >> n >> k;
    int counter = 0;
    int scores[n];
    
    for (int i = 0; i < n; ++i) {
        std::cin >> scores[i];
    }
    
    for (int i = 0; i < n; ++i) {
        if (scores[i] >= scores[k - 1] && scores[i] > 0){
            counter += 1;
        } else {
            break;
        }
    }
    
    std::cout << counter;
    
    return 0;
}
