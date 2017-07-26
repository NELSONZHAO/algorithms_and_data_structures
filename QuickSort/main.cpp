#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"

using namespace std;


// 对arr[l...r]部分进行partition操作
// 返回p，使得arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r){

    // 基准元素
    swap(arr[l], arr[rand()%(r-l+1)+l]); // 生成随机标定
    T v = arr[l];

    // arr[l+1...j] < v; arr[j+1...i) > v;
    int j = l;
    for( int i = l + 1; i <= r; i ++ ){
        if(arr[i] < v) // arr[i] < v 时，交换j+1位置元素与i位置的元素
            swap( arr[++j], arr[i] );
    }

    swap( arr[l], arr[j] );

    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r){

    // 对递归到底的情况进行处理
    if(l >= r)
        return;

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}



template <typename T>
// 快速排序
void quickSort(T arr[], int n) {

    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}

int main() {

//    int n = 1000000;
    for(int n = 10000; n <= 10000000; n *= 10) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        SortTestHelper::testSort("QuickSort", quickSort, arr, n);

        delete[] arr;
    }
    return 0;
}