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

typedef struct ssTable{
    DataType *data;
    int length;
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

//选择排序
void selectSort(SSTable *ssTable) {
    int temp = 0;
    for (int i = 0; i < ssTable->length - 1; i++){
        for (int j = i; j < ssTable->length; j++) {
            if (ssTable->data[i] > ssTable->data[j]) {
                //交换
                temp = ssTable->data[i];
                ssTable->data[i] = ssTable->data[j];
                ssTable->data[j] = temp;
            }
        }
    }
}

//冒泡排序
void maopaoSort(SSTable *ssTable) {
    int temp = 0;
    for (int i = 0; i < ssTable->length - 1; i++) { // 修正这里的循环终止条件
        for (int j = 0; j < ssTable->length - i - 1; j++) {
            if (ssTable->data[j] > ssTable->data[j + 1]) {
                // 如果前一个元素大于后一个元素，交换它们
                temp = ssTable->data[j];
                ssTable->data[j] = ssTable->data[j + 1];
                ssTable->data[j + 1] = temp;
            }
        }
    }
}

//插入排序
void insertSort(SSTable *ssTable){
    int i, j, k;
    for(i = 1; i < ssTable->length; i++){
        k = ssTable->data[i];
        j = i - 1;
        while (ssTable->data[j] > k && ssTable->data[j] > 0) {
            ssTable->data[j + 1] = ssTable->data[j];
            j--;
        }
        ssTable->data[j + 1] = k;
    }
}

//交换
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

    while (low <= high) {
        int mid = (low + high) / 2;
        if (ssTable->data[mid] == key) {
            return mid;
        } else if (ssTable->data[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

//遍历
void treverseTable(SSTable *ssTable, int length){
    int lines = 0;
    for(int i = 0; i < length; i++){
        printf("%-6d", ssTable->data[i]);
        lines++;
        if(lines % 20 == 0){
            printf("\n");
        }
    }
    printf("\n");
}