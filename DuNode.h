//
// Created by kanna on 2023/11/20.
//

#ifndef DATASTRUCT_DUNODE_H
#define DATASTRUCT_DUNODE_H

#endif //DATASTRUCT_DUNODE_H

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct DualLinkList {
    int data;  // 假设数据类型为整数
    struct LinkList* prev;
    struct LinkList* next;
} DuNode;

void insertNodeBetween(DuNode* p, DuNode* q, int newData) {
    // 创建新节点newNode并为其分配内存空间
    DuNode* newNode = (DuNode*)malloc(sizeof(DuNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // 设置新节点newNode的数据
    newNode->data = newData;

    // 插入新节点newNode在节点p和节点q之间
    newNode->prev = p;
    newNode->next = q;
    p->next = newNode;
    q->prev = newNode;
}