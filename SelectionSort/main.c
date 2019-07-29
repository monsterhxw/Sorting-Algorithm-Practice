#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Find the maximum element position in unsorted array
int findMaximumPos(int arr[], int n) {
    int max = arr[0];
    int pos = 0;
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            pos = i;
        }
    }
    return pos;
}

void selectionSort(int arr[], int n) {
    // 从右到左循环遍历 n - 1 次数组
    while (n > 1) {
        int pos = findMaximumPos(arr, n);
        swap(arr, pos, n - 1);
        n--;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectSort2(int arr[], int n) {
    int i, j, minIndex, temp;
    // 外循环规定遍历次数，最后只剩一个元素则不需再遍历
    // 所以外循环遍历 n - 1 次数组
    for (i = 0; i < n - 1; ++i) {
        // 当前遍历数组最小元素的角标，初始时令其等于 i
        minIndex = i;
        // 将剩余未排序元素当成新的数组，与该数组首位元素比较
        // 比较后记录最小元素的角标
        for (j = i + 1; j < n; j++) {
            //比较
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // 根据最小元素的角标，将其放到当前数组的首位
        if (minIndex != i) {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

// Driver program to test above functions
int main() {
    int arr[] = {7, 6, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting: \n");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("\nArray after sorting: \n");
    printArray(arr, n);
    return 0;
}