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

void initial_ssTable(SSTable *table, int tableSize){
    table->data = malloc(sizeof (DataType) * tableSize);
    table->length = tableSize;
}

void insertRandomNums(int *Nums, int tableSize){
    srand((unsigned int) time(NULL));
    for(int term = 0; term < tableSize; term++){
        Nums[term] = rand()%(100-10+1)+10;
    }
}

void maopaoSort(SSTable *ssTable, int tableSize) {
    int temp = 0;
    for (int i = 0; i < tableSize - 1; i++) { // 修正这里的循环终止条件
        for (int j = 0; j < tableSize - i - 1; j++) {
            if (ssTable->data[j] > ssTable->data[j + 1]) {
                // 如果前一个元素大于后一个元素，交换它们
                temp = ssTable->data[j];
                ssTable->data[j] = ssTable->data[j + 1];
                ssTable->data[j + 1] = temp;
            }
        }
    }
}

void insertSort(SSTable *ssTable, int tableSize){
    int i, j, k;
    for(i=1; i<10; i++){
        k = ssTable->data[i];
        j = i - 1;
        while (ssTable->data[j] > k && ssTable->data[j] > 0) {
            ssTable->data[j + 1] = ssTable->data[j];
            j--;
        }
        ssTable->data[j + 1] = k;
    }
}


int SqSearch(SSTable *ssTable, DataType key ,int tableSize){
    int index = 0;
    for(int i = 0; i < tableSize; i++){
        if(ssTable->data[i] == key)
            return i;
    }
    return -1;
}

int binSearch(SSTable *ssTable, DataType key, int tableSize) {
    int low = 0;
    int high = tableSize - 1;

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