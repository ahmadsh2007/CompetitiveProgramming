#include <iostream>
#include <vector>

int main(){
    int t; std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n; std::cin >> n;

        std::string a;
        std::cin >> a;

        bool allOnes = true;
        for (char c : a) {
            if (c == '0') {
                allOnes = false;
                break;
            }
        }

        int groups = 0;

        for (int leftIndex = 0; leftIndex < n;) {
            bool zeroDetected = 0;

            if (a[leftIndex] == '0') {
                leftIndex++;
                continue;
            }
            
            for (int rightIndex = leftIndex; rightIndex < n;){
                if (a[rightIndex] == '1') rightIndex++;
                else if (a[rightIndex] == '0' && !zeroDetected) {
                    zeroDetected = 1;
                    rightIndex++;
                } else {
                    groups += 1;
                    leftIndex = rightIndex;
                    break;
                }

                if (rightIndex == n){
                    leftIndex = n;
                    groups += allOnes ? 2 : 1;
                    break;

                }
            }

            if (leftIndex < n && a[leftIndex] == '1') {
                groups += allOnes ? 2 : 1;
                leftIndex = n;
            }

        }
        std::cout << groups << '\n';
    }
}