// C program for implementation of counting sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A utility function to get maximum value in arr[]
int findMaximum(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// A utility function to get minimum value in arr[]
int findMinimum(int arr[], int n) {
    int min = arr[0];
    int i;
    for (i = 1; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// 计数排序
void countingSort(int arr[], int n) {
    //使用最大值和最小值的方式是一种优化的计数排序
    //可以兼容负数的情况，同时能减少存储的空间，比如最大数是100，但实际上只有90-100这10个数字，所以仅仅需要10个存储空间即可
    int max = findMaximum(arr, n);
    int min = findMinimum(arr, n);
    int *output = (int *) malloc(sizeof(int) * n);

    int COUNT_LENGTH = max - min + 1;
    int *count = (int *) malloc(sizeof(int) * COUNT_LENGTH);
    memset(count, 0, sizeof(int) * COUNT_LENGTH);

    int i;
    // 统计数组中每个值为 i 的元素出现的次数，存入数组 count 的第 arr[i] 项
    for (i = 0; i < n; i++) {
        //由于优化了 count 数组的存储空间，a[i]-min 能保证 count 数组的第一个元素一定有元素的，min - min = 0
        count[arr[i] - min]++;
    }
    // 为了保持排序稳定，我们需要做一次累加操作
    // 目的，是为了标记出原始数组里面的该元素，前面有几个元素
    // 这个值实际上就是其在原生数组里面的位置，如果有重复的元素，则会先会放置最右边的元素，这样就能保证，排序的稳定性
    for (i = 1; i < COUNT_LENGTH; i++) {
        count[i] += count[i - 1];
    }
    // 从后向前遍历，只有这样出现重复的元素，才会保持顺序的把最后面的重复元素，永远放在最右边，从而保证排序的稳定性
    for (i = n - 1; i >= 0; i--) {
        //由于优化了 count 数组的存储空间，a[i]-min 能保证 count 数组的第一个元素一定有元素的，min - min = 0
        //把最终生成的排序值，放在 outPutArray 数组
        //如果有重复元素，位置需要从右向左放置，所以需要把 count[arr[i] - min] 的值-1
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    // 将数组 outPutArray 复制到数组 arr，所以数组 arr 现在是包含根据当前位数排序好的数字
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
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

// Driver program to test above functions
int main() {
    int arr[] = {3, 4, 3, 2, 1, 9, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting: \n");
    printArray(arr, n);
    countingSort(arr, n);
    printf("\nArray after sorting: \n");
    printArray(arr, n);
    return 0;
}