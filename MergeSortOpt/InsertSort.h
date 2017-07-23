#include <iostream>


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

//对数组arr[l,r]范围内元素进行插入排序
template<typename T>
void insertSort(T arr[], int l, int r){

    for(int i = l; i <= r; i ++ ){

        T e = arr[i];
        int j; // 元素e应该插入的位置
        for( j = i; j > l && arr[j-1] > e; j -- ){
                arr[j] = arr[j-1];
        }
        arr[j] = e;
    }

}