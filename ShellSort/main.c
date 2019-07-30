// C program for implementation of shell sort

#include <stdio.h>

// n 为第几个元素，gap 为当前间隔增量
void insert(int arr[], int n, int gap) {
    int key = arr[n];
    int i = n;
    // 如果该组元素中，前几个元素都比 a[i] 大，则执行后移，把比 a[i] 大的都移动到 a[i] 后面
    while (i > 0 && arr[i - gap] > key) {
        arr[i] = arr[i - gap];
        i = i - gap;
        // 当 i - gap 后比 gap 小，说明已经排好序，这时退出循环
        if (i < gap) {
            break;
        }
    }
    arr[i] = key;
}

// n 为列表中元素个数，gap 为当前间隔增量
void insertionSort(int arr[], int n, int gap) {
    int i;
    // 进行插入排序，从每个分组的第 gap 个元素开始，而不是从它的第 1 个元素开始
    for (i = gap; i < n; i++) {
        insert(arr, i, gap);
    }
}

void shellSort(int arr[], int n) {
    int gap = 1;
    // Knuth增量序列递推式：h(1) = 1, h(i) = 3 * h(i-1) + 1
    while (gap < n) {
        gap = gap * 3 + 1;
    }
    // 间隔增量 gap 每次变小，直到为 1
    while (gap > 0) {
        // 进行插入排序，从每个分组的第 gap 个元素开始，而不是从它的第 1 个元素开始
        insertionSort(arr, n, gap);
        gap = (gap - 1) / 3;
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

int main() {
    int arr[] = {14, 18, 19, 37, 23, 40, 29, 30, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting: \n");
    printArray(arr, n);
    shellSort(arr, n);
    printf("\nArray after sorting: \n");
    printArray(arr, n);
    return 0;
}

// function to sort arr using shellSort
void shellSort2(int arr[], int n) {
    int i, j, gap, key;
    // 外循环：增量 gap 每次变小，直到为 1
    for (gap = n / 2; gap > 0; gap /= 2) {
        // 内循环：进行插入排序，从每个分组的第 gap 个元素开始，而不是从它的第一个元素开始
        for (i = gap; i < n; i++) {
            // 如果小于前一个元素，进行交换，把小的换到前面来
            if (arr[i] < arr[i - gap]) {
                // 保存小的元素
                key = arr[i];
                // 记录前一个比它大的角标
                j = i - gap;
                // 如果该组元素中，前几个元素都比 arr[i] 大，则执行后移，把比 arr[i] 大的都移动到 arr[i] 后面
                while (j >= 0 && arr[j] > key) {
                    arr[j + gap] = arr[j];
                    j -= gap;
                }
                // 此时 arr[j] < arr[i], arr[i] 放到 arr[j] 右边
                arr[j + gap] = key;
            }
        }
    }
}