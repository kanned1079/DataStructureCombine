//
// Created by kanna on 2023/12/5.
//

#ifndef DATASTRUCT_SEARCH_H
#define DATASTRUCT_SEARCH_H

#endif //DATASTRUCT_SEARCH_H


#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include <stdio.h>
#define DataType int

typedef struct ssTable {
    DataType *data;  // 指向存储元素的数组
    int length;      // 静态表的长度
} SSTable;

//初始化
void initial_ssTable(SSTable *table, int tableSize){
    table->data = malloc(sizeof (DataType) * tableSize);
    table->length = tableSize;
}

//生成范围内的随机数
int generateRandomNumber(int start, int end) {
//    srand((unsigned int)time(NULL));
    int randomNumber = rand() % (end - start + 1) + start;
    return randomNumber;
}

//插入随机数
void insertRandomNums(int *Nums, int tableSize, int start, int end){
    for(int term = 0; term < tableSize; term++)
        Nums[term] = generateRandomNumber(start, end);
}

//交换
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//选择排序
void selectSort(SSTable *ssTable) {
    // 外层循环控制待排序序列的起始位置
    for (int i = 0; i < ssTable->length - 1; i++) {
        // 内层循环遍历未排序的部分，找到最小元素的索引
        for (int j = i; j < ssTable->length; j++) {
            // 如果当前位置的元素比最小元素还小，更新最小元素的索引
            if (ssTable->data[i] > ssTable->data[j])
                swap(&ssTable->data[i], &ssTable->data[j]);
                //交换
        }
    }
}

//冒泡排序
void maopaoSort(SSTable *ssTable) {
    // 外层循环控制比较轮数，每轮找到一个最大元素
    for (int i = 0; i < ssTable->length - 1; i++) {
        // 内层循环进行相邻元素的比较和交换
        for (int j = 0; j < ssTable->length - i - 1; j++) {
            // 如果前一个元素大于后一个元素，交换它们
            if (ssTable->data[j] > ssTable->data[j + 1])
                swap(&ssTable->data[j], &ssTable->data[j+1]);
        }
    }
}

//冒泡排序（沉底）
void bubbleSort(SSTable *ssTable) {
    // 外层循环控制比较轮数，每轮将最大元素沉底
    for (int i = 0; i < ssTable->length - 1; i++) {
        // 内层循环进行相邻元素的比较和交换
        for (int j = 0; j < ssTable->length - i - 1; j++) {
            // 如果前一个元素大于后一个元素，交换它们
            if (ssTable->data[j] > ssTable->data[j + 1]) {
                swap(&ssTable->data[j], &ssTable->data[j+1]);
            }
        }
    }
}

//插入排序 fixed
void myInsertSort(SSTable *ssTable) {
    int i, j, k;

    // 从第二个元素开始，依次将元素插入已排序的序列中
    for(i = 1; i < ssTable->length; i++) {
        k = ssTable->data[i];  // 当前待插入的元素
        j = i - 1;

        // 在已排序序列中找到合适的位置插入当前元素
        while (j >= 0 && ssTable->data[j] > k) {
            ssTable->data[j + 1] = ssTable->data[j];  // 元素后移
            j--;
        }

        ssTable->data[j + 1] = k;  // 将当前元素插入到正确的位置
    }
}

//插入排序 上课教的
void insertSort(SSTable *ssTable){
    int i, j, x;
    for(i = 1; i < ssTable->length; i++){
        x = ssTable->data[i];
        for(j = i - 1; j >= 0 && ssTable->data[j] > x; j--)
            ssTable->data[j + 1] = ssTable->data[j];
        ssTable->data[j + 1] = x;
    }
}

// 根据最右侧元素（pivot）将数组划分为两部分，并返回pivot的最终位置
//int partition(int arr[], int low, int high) {
//    int pivot = arr[high];  // 选择最右侧元素作为pivot
//    int i = (low - 1);  // 初始化较小元素的索引
//
//    // 遍历数组，将小于等于pivot的元素放到左侧，大于pivot的元素放到右侧
//    for (int j = low; j < high; j++) {
//        if (arr[j] <= pivot) {
//            i++;
//            swap(&arr[i], &arr[j]);
//        }
//    }
//
//    // 将pivot放到其最终位置
//    swap(&arr[i + 1], &arr[high]);
//    return (i + 1);
//}

//调整堆，使其满足最大堆性质
void heapify(int arr[], int n, int i) {
    int largest = i;    // 初始化父节点为最大值
    int left = 2 * i + 1;    // 左子节点
    int right = 2 * i + 2;   // 右子节点

    // 如果左子节点比父节点大，则更新最大值索引
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点比父节点大，则更新最大值索引
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是父节点，则交换父节点和最大值，并递归调整子树
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

//堆排序
void heapSort(SSTable *ssTable) {
    // 构建最大堆（从最后一个非叶子节点开始）
    for (int i = ssTable->length / 2 - 1; i >= 0; i--)
        heapify(ssTable->data, ssTable->length, i);

    // 一个一个从堆顶取出元素
    for (int i = ssTable->length - 1; i > 0; i--) {
        // 将当前堆顶元素与堆尾元素交换
        swap(&ssTable->data[0], &ssTable->data[i]);

        // 调整剩余堆，使其满足最大堆性质
        heapify(ssTable->data, i, 0);
    }
}

//快速排序
void quickSort(SSTable *ssTable, int low, int high) {
    if (low < high) {
        int pivot = ssTable->data[low];
        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (i <= j && ssTable->data[i] < pivot)
                i++;
            while (j >= i && ssTable->data[j] > pivot)
                j--;

            if (i <= j) {
                swap(&ssTable->data[i], &ssTable->data[j]);
                i++;
                j--;
            }
        }

        swap(&ssTable->data[low], &ssTable->data[j]);

        // Recursively sort the sub-arrays
        quickSort(ssTable, low, j - 1);
        quickSort(ssTable, j + 1, high);
    }
}

//顺序查询
int SqSearch(SSTable *ssTable, DataType key){
    for(int i = 0; i < ssTable->length; i++){
        if(ssTable->data[i] == key)
            return i;
    }
    return -1;
}

//二分查找
int binSearch(SSTable *ssTable, DataType key) {
    int low = 0;
    int high = ssTable->length - 1;

    // 使用二分查找算法，循环终止条件为low大于high
    while (low <= high) {
        int mid = (low + high) / 2;

        // 如果中间元素等于目标元素，返回中间元素的索引
        if (ssTable->data[mid] == key) {
            return mid;
        }
            // 如果中间元素小于目标元素，说明目标元素在右半部分
        else if (ssTable->data[mid] < key) {
            low = mid + 1;  // 更新low，缩小查找范围为右半部分
        }
            // 如果中间元素大于目标元素，说明目标元素在左半部分
        else {
            high = mid - 1;  // 更新high，缩小查找范围为左半部分
        }
    }

    // 若循环结束仍未找到目标元素，返回-1表示未找到
    return -1;
}

//插值查找
int interpolationSearch(SSTable *ssTable, DataType key) {
    int low = 0, high = ssTable->length - 1;

    // 使用插值查找算法，循环终止条件为low小于等于high且key在查找范围内
    while (low <= high && key >= ssTable->data[low] && key <= ssTable->data[high]) {
        // 计算插值公式，pos表示估计的目标元素位置
        int pos = low + ((key - ssTable->data[low]) * (high - low)) / (ssTable->data[high] - ssTable->data[low]);

        // 如果估计位置的元素等于目标元素，返回估计位置
        if (ssTable->data[pos] == key)
            return pos;

        // 如果估计位置的元素小于目标元素，说明目标元素在右半部分
        if (ssTable->data[pos] < key)
            low = pos + 1;  // 更新low，缩小查找范围为右半部分
            // 如果估计位置的元素大于目标元素，说明目标元素在左半部分
        else
            high = pos - 1;  // 更新high，缩小查找范围为左半部分
    }

    // 若循环结束仍未找到目标元素，返回-1表示未找到
    return -1;
}

//遍历
void traverseTable(SSTable *ssTable){
    int lines = 0;
    for(int i = 0; i < ssTable->length; i++){
        printf("%-6d", ssTable->data[i]);
        lines++;
        if(lines % 20 == 0){
            printf("\n");
        }
    }
    printf("\n");
}