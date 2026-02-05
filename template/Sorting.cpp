#include <bits/stdc++.h>
using namespace std;

static void printVec(const vector<int>& v) {
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    // 1) Bubble Sort: O(n^2) time, O(1) extra space, stable, in-place.
    // Repeatedly swaps adjacent out-of-order elements; small elements "bubble" left, large right.
    auto bubbleSort = [](vector<int> a) {
        int n = (int)a.size();
        for (int i = 0; i < n; i++) {
            bool swapped = false;
            for (int j = 0; j + 1 < n - i; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break; // already sorted
        }
        return a;
    };

    // 2) Merge Sort: O(n log n) time, O(n) extra space, stable (when merging carefully), not in-place.
    // Divide array into halves, sort each, then merge.
    auto mergeSort = [](vector<int> a) {
        function<void(int,int)> sortRange = [&](int l, int r) {
            if (r - l <= 1) return;
            int m = l + (r - l) / 2;
            sortRange(l, m);
            sortRange(m, r);

            vector<int> tmp;
            tmp.reserve(r - l);
            int i = l, j = m;

            // For stability: if equal, take from left first (<=).
            while (i < m && j < r) {
                if (a[i] <= a[j]) tmp.push_back(a[i++]);
                else tmp.push_back(a[j++]);
            }
            while (i < m) tmp.push_back(a[i++]);
            while (j < r) tmp.push_back(a[j++]);

            for (int k = 0; k < (int)tmp.size(); k++) {
                a[l + k] = tmp[k];
            }
        };

        sortRange(0, (int)a.size());
        return a;
    };

    // 3) Heap Sort: O(n log n) time, O(1) extra space, not stable, in-place.
    // Build a heap, then repeatedly extract max to the end.
    auto heapSort = [](vector<int> a) {
        // Using STL heap utilities (still heap sort).
        make_heap(a.begin(), a.end());   // max-heap
        sort_heap(a.begin(), a.end());   // sorts ascending
        return a;
    };

    // 4) Quick Sort: average O(n log n), worst O(n^2), O(log n) stack typically, not stable, in-place.
    // Partition around a pivot, recursively sort partitions.
    auto quickSort = [](vector<int> a) {
        function<void(int,int)> qs = [&](int l, int r) {
            if (r - l <= 1) return;

            // Pivot choice matters. Midpoint is simple and often fine.
            int pivot = a[l + (r - l) / 2];

            int i = l, j = r - 1;
            while (i <= j) {
                while (a[i] < pivot) i++;
                while (a[j] > pivot) j--;
                if (i <= j) {
                    swap(a[i], a[j]);
                    i++; j--;
                }
            }

            // Now: [l, j] <= pivot, [i, r) >= pivot (approximately)
            qs(l, j + 1);
            qs(i, r);
        };

        qs(0, (int)a.size());
        return a;
    };

    // Test vectors (one for each algorithm)
    vector<int> vBubble = {5, 1, 4, 2, 8, 0, 2};
    vector<int> vMerge  = {9, 7, 5, 3, 1, 2, 4, 6, 8};
    vector<int> vHeap   = {10, -1, 3, 3, 2, 100, 50, 0};
    vector<int> vQuick  = {4, 2, 7, 1, 3, 6, 5, 2};

    cout << "Original Bubble vector: "; printVec(vBubble);
    cout << "Bubble sorted:          "; printVec(bubbleSort(vBubble));
    cout << "\n";

    cout << "Original Merge vector:  "; printVec(vMerge);
    cout << "Merge sorted:           "; printVec(mergeSort(vMerge));
    cout << "\n";

    cout << "Original Heap vector:   "; printVec(vHeap);
    cout << "Heap sorted:            "; printVec(heapSort(vHeap));
    cout << "\n";

    cout << "Original Quick vector:  "; printVec(vQuick);
    cout << "Quick sorted:           "; printVec(quickSort(vQuick));
    cout << "\n";

    return 0;
}


/*
void bubbleSort(vector<int>& arr, int type) {
    int n = arr.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                ans.push_back({type, j + 1});
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
      
        if (!swapped)
            break;
    }
}
*/