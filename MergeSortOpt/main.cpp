#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "InsertSort.h"

using namespace std;

// 对arr[l, mid], arr[mid+1, r]两个数组进行合并
template<typename T>
void __merge(T arr[], int l, int mid, int r){

    // 辅助数组
    T aux[r-l+1];
    for(int i = l; i <= r; i ++ ){
        aux[i-l] = arr[i];
    }

    // 归并
    int i = l, j = mid + 1;
    for( int k = l; k <= r; k ++ ){
        if(i > mid) {
            arr[k] = aux[j-l];
            j ++ ;
        }
        else if(j > r){
            arr[k] = aux[i-l];
            i ++ ;
        }
        else if(aux[i-l] < aux[j-l]){
            arr[k] = aux[i-l];
            i ++ ;
        }
        else{
            arr[k] = aux[j-l];
            j ++ ;
        }
    }
}


template<typename T>

void __mergeSort(T arr[], int l, int r){ // 对arr[l, r]闭区间内数组归并排序

//    if ( l >= r )
//        return;

    if ( r - l <= 8 ){ // 改进2：对于近乎有序的数组采用插入排序替代
        insertSort(arr, l, r);
        return;
    }

    int mid = l + (r-l) / 2;
    __mergeSort(arr, l, mid); // 左数组递归
    __mergeSort(arr, mid+1, r); // 右数组递归
    if (arr[mid] > arr[mid+1]) //改进1：对于有序的左右数组省去了归并的一步
        __merge(arr, l, mid, r); // 合并
}

template <typename T>
void mergeSort(T arr[], int n){
    __mergeSort(arr, 0, n-1);
}

int main() {
    int n = 10000;

    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("MergeSort", mergeSort, arr, n);

    delete[] arr;
    return 0;
}