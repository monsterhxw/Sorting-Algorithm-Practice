#include <stdio.h>

// Optimized bubble sort in C
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // The variable "swapped" is introduced for optimization.
    int swapped = 1;
    // 外循环规定了排序次数，从第 1 次到第 n - 1 次
    for (i = 0; i < n - 1 && swapped; i++) {
        swapped = 0;
        // 内循环规定了剩余未排序元素,j 是从前往后循环
        for (j = 0; j < n - i - 1; j++) {
            // 前一个大于后一个，则交换
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
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

// Driver program to test above functions
int main() {
    int arr[] = {-2, 45, 0, 11, -9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting: \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("\nArray after sorting: \n");
    printArray(arr, n);
    return 0;
}