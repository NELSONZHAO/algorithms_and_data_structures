#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void insertSort(T arr[], int n){

    for ( int i = 1; i < n; i ++ ) {


        // 寻找元素arr[i]合适的插入位置
        T e = arr[i];
        int j; // j保存元素e应该插入的位置
        for (j = i ; j > 0; j --){
            if (e < arr[j - 1]) {
                arr[j] = arr[j - 1];
            }
            else
                break;
        }
        arr[j] = e;
    }
}

int main() {

    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
//    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    insertSort(arr, n);
    SortTestHelper::testSort("Insertion Sort", insertSort, arr, n);

    return 0;
}