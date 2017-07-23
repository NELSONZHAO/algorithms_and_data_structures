#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"

using namespace std;

// 对arr[l...mid]和arr[mid+1, r]两部分进行归并
template <typename T>
void __merge(T arr[], int l, int mid, int r) {

    T aux[r-l+1]; // 辅助空间
    for( int i = l; i <= r; i ++ )
        aux[i-l] = arr[i];

    int i = l, j = mid + 1; // 两个子数组指针
    for( int k = l; k <= r; k ++ ){

        if( i > mid ){ // 此时代表左数组已经遍历结束
            arr[k] = aux[j-l];
            j++;
        }
        else if(j > r) { // 此时代表右数组已经遍历结束
            arr[k] = aux[i-l];
            i++;
        }
        else if( aux[i-l] < aux[j-l] ) {
            arr[k] = aux[i - l];
            i++;
        }else{
            arr[k] = aux[j-l];
            j++;
        }
    }
}
// 递归使用归并排序，对arr[l...r]的范围进行排序
template <typename T>
void __mergeSort(T arr[], int l, int r){

    if( l >= r ) // 递归停止条件
        return;

    int mid = l + (r-l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    __merge(arr, l, mid, r);
}


template <typename T>

void mergeSort(T arr[], int n){

    __mergeSort(arr, 0, n-1);
}

int main() {
    int n = 50000;
    for(int n = 1000; n <= 10000000; n *= 10) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);

        delete[] arr;
        cout << endl;
    }
//    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//    mergeSort(a, 10);
    return 0;
}