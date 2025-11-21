#include <iostream>
// #include <cmath> // import it if you want to run the second solution
 
int main(){
    int matrix[5][5];
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            std::cin >> matrix[i][j];
        }
    }
    
    // for (int i = 0; i < 5; i++){
    //     for (int j = 0; j < 5; j++){
    //         std::cout << matrix[i][j] << " ";
    //     }
    //     std::cout << '\n';
    // }
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (matrix[i][j] == 1){
                int stepsOne = i - 2;
                int stepsTwo = j - 2;
                if (stepsOne < 0){
                    stepsOne = -stepsOne;
                }
                if (stepsTwo < 0){
                    stepsTwo = -stepsTwo;
                }
                std::cout << stepsOne + stepsTwo;
            }
        }
    }

    // BTW, we can ignore saving the whole matrix and focus on 1. In other words we iterate without saving any value until we find 1 as the code below
    /*
    int x, y;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            int val;
            std::cin >> val;
            if (val == 1){
                x = i;
                y = j;
            }
        }
    }
    std::cout << abs(x - 2) + abs(y - 2); // you have to import cmath library first
    */
}