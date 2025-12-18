#include <iostream>
#include <stdio.h>
#include <vector>
 
int main(){
    int n, k;
    std::cin >> n >> k;
 
    std::vector<long double> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
 
    long double result = a[0];
    int kCounter = 0;
    for (int i = 1; i < n; i++){
        // Please God, I already suffered enough
        if (a[i] > a[i - 1] || a[i] > result){result = a[i]; kCounter = 0;}
        else kCounter += 1;
        
        if (kCounter > k){
            printf("%.2f", (double) result);
            return 0;
        }
    }
 
    printf("%.2f", (double) result);
    return 0;
}
