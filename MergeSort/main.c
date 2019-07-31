// C program for implementation of merge sort
#include <stdio.h>
#include <stdlib.h>

// L 代表数组从哪个位置开始，M 代表数组的分解点位置，R 代表数组从那个位置结束
void merge(int arr[], int L, int M, int R) {
    // Find sizes of two subarrays to be merged
    int LEFT_SIZE = M - L + 1;
    int RIGHT_SIZE = R - M;
    // Create temp arrays
    int *left = (int *) malloc(sizeof(int) * LEFT_SIZE);
    int *right = (int *) malloc(sizeof(int) * RIGHT_SIZE);;
    int i, j, k;
    // Fill in the left sub array (填满左边子数组)
    for (i = L; i < M + 1; i++) {
        left[i - L] = arr[i];
    }
    // Fill in the right sub array (填满右边子数组)
    for (i = M + 1; i < R + 1; i++) {
        right[i - M - 1] = arr[i];
    }
    // Merge into the original array（重新合并到原数组）
    // i 指向 left 数组的第一个元素位置，j 指向 right 数组的第一个元素位置，k 指向原数组的第一个元素的位置
    i = 0, j = 0, k = L;
    // 直到到达 left 或 right的任一顶端
    while (i < LEFT_SIZE && j < RIGHT_SIZE) {
        // 比较 left 数组和 right 数组中的元素，两者数组比较小的值的数组，将指向位置的那个变量位置的值赋值给原数组，
        // 同时指向该数组元素位置变量加 1 和指向原数组位置变量加 1，如此重复。
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
            k++;
        } else {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    // 如果指向 left 数组的位置变量 i 小于 left 数组的长度 LEFT_SIZE，那么将所有的 left 数组元素依次填入原数组 arr 中
    while (i < LEFT_SIZE) {
        arr[k] = left[i];
        i++;
        k++;
    }
    // 如果指向 right 数组的位置变量 j 小于 right 数组的长度 RIGHT_SIZE，那么将所有的 right 数组元素依次填入原数组 arr 中
    while (j < RIGHT_SIZE) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// 利用递归思想（Recursion）和分治思想（Divide-and-conquer）
// L 代表数组从哪个位置开始，R 代表数组从那个位置结束
void mergerSort(int arr[], int L, int R) {
    // 当分割成两个子序列中只有一个元素都时候，递归结束
    if (L == R) {
        return;
    }
    int M = (L + R) / 2;
    // 递归将 left 数组进行归并排序
    mergerSort(arr, L, M);
    // 递归将 right 数组进行归并排序
    mergerSort(arr, M + 1, R);
    // 合并已经排好序的 left 数组和 right 数组）
    merge(arr, L, M, R);
}

// A utility function to print an array of size n
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6, 8, 10, 9, 4, 5, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int L = 0;
    int R = n - 1;

    printf("Array before sorting: \n");
    printArray(arr, n);

    mergerSort(arr, L, R);
    printf("\nArray after sorting: \n");
    printArray(arr, n);

    return 0;
}