// C program for implementation of radix sort
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

// 计数排序，radix 是基的个数
void countingSort(int arr[], int n, int radix) {
    int *output= (int *) malloc(sizeof(int) * n);
    int *count = (int *) malloc(sizeof(int) * 10);
    memset(count, 0, sizeof(int) * 10);
    int i;

    // 存储发生次数在数组 count 中
    for (i = 0; i < n; i++) {
        count[(arr[i] / radix) % 10]++;
    }
    // 为了保持排序稳定，我们需要做一次累加操作
    // 目的，是为了标记出原始数组里面的该元素，前面有几个元素
    // 这个值实际上就是其在原生数组里面的位置，如果有重复的元素，则会先会放置最右边的元素，这样就能保证，排序的稳定性
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    // 从后向前遍历，只有这样出现重复的元素，才会保持顺序的把最后面的重复元素，永远放在最右边，从而保证排序的稳定性
    for (i = n - 1; i >= 0; i--) {
        //把最终生成的排序值，放在 outPutArray 数组
        //如果有重复元素，位置需要从右向左放置，所以需要把 count[(arr[i] / radix) % 10] 的值-1
        output[count[(arr[i] / radix) % 10] - 1] = arr[i];
        count[(arr[i] / radix) % 10]--;
    }
    // 将数组 output Array 复制到数组 arr，所以数组 arr 现在是包含根据当前位数排序好的数字
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    // Find the maximum number to know number of digits
    int max = findMaximum(arr, n);
    // 对每个数字进行计数排序，radix 是基的个数,等于 10^d，d 是当前的位数
    int raix;
    for (raix = 1; max / raix > 0; raix *= 10) {
        countingSort(arr, n, raix);
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
    int arr[] = {170, 45, 75, 90, 90, 24, 2, 66, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: \n");
    printArray(arr, n);

    radixSort(arr, n);
    printf("\nArray after sorting: \n");
    printArray(arr, n);
    return 0;
}