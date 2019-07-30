// C program for implementation of heap sort
#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 堆化，n 代表树多少个结点，i 代表对哪一个结点进行 heapify 操作
void heapify(int tree[], int n, int i) {
    // 递归出口(非必要存在)
    if (i >= n) {
        return;
    }
    // 左孩子的下标值
    int leftChild = 2 * i + 1;
    // 右孩子的下标值
    int rightChild = 2 * i + 2;
    // 先假设最大值的下标值 max 为 i
    int maxPos = i;
    // 比较左孩子值是否大于最大结点值，如果大于就将 leftChild 赋给 max
    if (leftChild < n && tree[leftChild] > tree[maxPos]) {
        maxPos = leftChild;
    }
    // 比较右孩子值是否大于最大结点值，如果大于就将 rightChild 赋给 max
    if (rightChild < n && tree[rightChild] > tree[maxPos]) {
        maxPos = rightChild;
    }
    // 如果最大值的下标值 max 不等于 i，则交换下标 max 与 i 的值
    if (maxPos != i) {
        swap(tree, maxPos, i);
        // 从最大值的下标值 max 位置结点递归
        heapify(tree, n, maxPos);
    }
}

// Build heap (rearrange array)
void buildHeap(int tree[], int n) {
    // 最后一个结点的下标
    int lastNode = n - 1;
    // 最后一个结点的双亲结点的下标
    int lastParentNode = (lastNode - 1) / 2;
    // 从最后一个结点的双亲结点开始从下往上的结点开始 heapify
    int i;
    for (i = lastParentNode; i >= 0; i--) {
        heapify(tree, n, i);
    }
}

// main function to do heap sort
void heapSort(int tree[], int n) {
    // 建立一个堆
    buildHeap(tree, n);
    // 从最后一个结点出发，从下往上的结点开始,将根结点的值放在最后的位置上
    int i;
    for (i = n - 1; i >= 0; i--) {
        // 将根结点交换至最后一个结点
        swap(tree, i, 0);
        //因为将最后一个结点的值与根结点进行了交换，所以需要进行 heapify 一次（参数 i 目的去掉最后一个结点）
        heapify(tree, i, 0);
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
    int tree[] = {2, 5, 3, 1, 10, 4};
    int n = sizeof(tree) / sizeof(tree[0]);
    printf("Array before sorting: \n");
    printArray(tree, n);

    heapSort(tree, n);
    printf("\nArray after sorting: \n");
    printArray(tree, n);
    return 0;
}