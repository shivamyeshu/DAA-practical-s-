// Bitonic Sort
#include <iostream>
#include <vector>
using namespace std;

void compareAndSwap(int &a, int &b, bool ascending) {
    if ((a > b) == ascending) swap(a, b);
}

void bitonicMerge(vector<int>& arr, int low, int count, bool ascending) {
    if (count > 1) {
        int k = count / 2;
        for (int i = low; i < low + k; i++)
            compareAndSwap(arr[i], arr[i + k], ascending);
        bitonicMerge(arr, low, k, ascending);
        bitonicMerge(arr, low + k, k, ascending);
    }
}

void bitonicSort(vector<int>& arr, int low, int count, bool ascending) {
    if (count > 1) {
        int k = count / 2;
        bitonicSort(arr, low, k, true);
        bitonicSort(arr, low + k, k, false);
        bitonicMerge(arr, low, count, ascending);
    }
}

int main() {
    vector<int> arr = {34, 7, 23, 32, 5, 62};
    bitonicSort(arr, 0, arr.size(), true);
    for (int num : arr) cout << num << " ";
    return 0;
}
// Output: 5 7 23 32 34 62