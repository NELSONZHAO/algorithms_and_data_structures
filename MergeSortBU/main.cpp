#include <iostream>
#include "mergeSort.h"
#include "SortTestHelper.h"

using namespace std;

template <typename T>
void mergeSortBU(T arr[], int n){
    // 自底向上的归并排序

    for(int sz = 1; sz <= n; sz *= 2) { // 归并的元素个数
        for (int i = 0; i + sz < n; i += sz + sz) {
            // 对arr[i, i+sz-1]与arr[i+sz,i+2*sz-1]进行归并
            if (arr[i + sz - 1] > arr[i + sz])
                __merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
        }
    }
}


int main() {

    int n = 50000;

    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("MergeSortBU", mergeSortBU, arr, n);
    return 0;
}