#include <iostream>
#include "SortTestHelper.h"

using namespace std;



template <typename T>
int __partition2(T arr[], int l, int r){

    swap(arr[l], arr[rand()%(r-l+1)+l]);

    T v = arr[l];

    // arr[l+1...i) <= v; arr(j...r]>=v
    int i = l + 1, j = r;
    while( true ){
        while( i <= r && arr[i] < v) i++ ;
        while( j >= l + 1 && arr[j] > v ) j--;
        // 判断循环是否结束
        if(i > j) break;
        swap(arr[i++], arr[j--]);
    }

    swap(arr[l], arr[j]);

    return j;

}

template <typename T>
void __quickSort(T arr[], int l, int r){ // 对arr[l...r]进行快排

    if( l >= r )
        return;

    int p = __partition2(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}


template <typename T>
void quickSort(T arr[], int n){

    __quickSort(arr, 0, n-1);
}

int main() {

    int n = 1000000;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    int* arr2 = SortTestHelper::generateRandomArray(n, 0, n);

    SortTestHelper::testSort("QuickSort2", quickSort, arr1, n);
    SortTestHelper::testSort("QuickSort2", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;
    return 0;
}