// ! I really had fun with this PSet
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

// I finally used it for something real
// Note: I found that there is a std::sort function :|

/*
* Note, I ran through `Runtime error on test 1`. I checked ChatGPT for fix so I'm not using it anymore (I'm not a cheater to use ChatGPT code xD)
void merge(std::vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    }

    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

* The ChatGPT'd function, I didn't test it so I don't know
void mergeSort(std::vector<int> &arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printArray(const std::vector<int> &arr) {
    for (int x : arr) printf("%d ", x);
    std::cout << '\n';
}
*/

int main(){
    // std::vector<int> a = {70, 50, 30, 10, 20, 40, 60}; // for testing
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    // mergeSort(a, 0, 7 - 1);
    // printArray(a);
    std::sort(a.begin(), a.end());

    int maxTeam = 1;

    // 2 pointer method is here to clutch `Time limit exceeded on test 16`
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && a[j] - a[i] <= 5) {
            j++;
        }
        maxTeam = std::max(maxTeam, j - i);
    }

    std::cout << maxTeam;
    
    return 0;
}