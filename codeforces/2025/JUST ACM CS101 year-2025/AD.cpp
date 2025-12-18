#include <iostream>
#include <iomanip> 

int main(){
    int N, a, b, c;
    std::cin >> N >> a >> b >> c;

    float shareValue = (float) N / (a + b + c); 
    float prizeA, prizeB, prizeC;

    prizeA = shareValue * a;
    prizeB = shareValue * b;
    prizeC = shareValue * c;
    printf("%.5f %.5f %.5f", prizeA, prizeB, prizeC);

}