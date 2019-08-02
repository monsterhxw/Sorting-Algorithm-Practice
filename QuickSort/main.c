// add C program for implementation of quick sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// generates a pivot index after partitioning
int partition(int arr[], int left, int right) {
    srand(time(0));
    //generates a random number as a pivot
    int pivotPos = rand() % (right - left + 1) + left;
    // pivot 作为基准值
    int pivot = arr[pivotPos];
    // 把 pivot 与 right 置换元素（即将 pivot 放置数组的最后一个位置）
    swap(arr, pivotPos, right);
    // 保存 pivot 的位置的下标值
    pivotPos = right;
    // 因 pivot 放置数组的最后一个位置，所以 right 的值需要减一
    right--;
    //当 left == right 时，right 和 right 同时指向的元素还没有与中轴元素判断
    while (left <= right) {
        // 当前元素的值大于 pivot 基准值
        if (arr[left] > pivot) {
            // 将当前大于 pivot 基准值的元素与位置为 right 的元素值，进行置换
            swap(arr, left, right);
            // right 继续向左，扫描下一个
            right--;
        } else {
            // 从序列的左边开始往右边遍历
            left++;
        }
    }
    // 将 pivot 置换到 left 位置上
    swap(arr, left, pivotPos);
    // 返回 pivot 的位置
    pivotPos = left;
    return pivotPos;
}

void quickSort(int arr[], int left, int right) {
    //递归终止条件，少于等于一个元素的数组已有序
    if (left >= right) {
        return;
    }
    // generates a pivot index after partitioning
    int pivotPos = partition(arr, left, right);
    //分割两个序列继续进行快排操作
    quickSort(arr, left, pivotPos - 1);
    quickSort(arr, pivotPos + 1, right);
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
    int arr[] = {890, 60, 50, 79, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);
    printf("\nArray after sorting: \n");
    printArray(arr, n);
    return 0;
}