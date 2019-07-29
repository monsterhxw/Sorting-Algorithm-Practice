#include <stdio.h>

// n 为第几个元素
void insert(int arr[], int n) {
    int key = arr[n];
    int i = n;
    while (i > 0 && arr[i - 1] > key) {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[i] = key;
}

void insertionSort(int arr[], int n) {
    int i;
    // 认为第一个元素是在已排序子列表中，从第二个元素开始，将元素插入到已排序子列表中
    for (i = 1; i < n; i++) {
        insert(arr, i);
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program to test insertion sort
int main() {
    int arr[] = {7, 6, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting: \n");
    printArray(arr, n);
    insertionSort(arr, n);
    printf("\nArray after sorting: \n");
    printArray(arr, n);
    return 0;
}