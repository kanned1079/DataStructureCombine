//
// Created by kanna on 2023/11/13.
//

#ifndef DATASTRUCT_LINKLIST_H
#define DATASTRUCT_LINKLIST_H

#endif //DATASTRUCT_LINKLIST_H


#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define DataType int

typedef struct LinkList {
    DataType data;
    struct LinkList *next;
} LNode;

LNode *initial_HeadNode(){
    LNode *L;
    L = (LNode *) malloc(sizeof (LNode));
    L->data = 0;
    L->next  = NULL;
    return L;
}

//尾插法输入数据
void append_Node(LNode *L){
    printf("Input value, -1 as END: ");
    LNode *p = L, *newNode = NULL;
    DataType value;
    while (true){
        scanf("%d", &value);
        if(value == -1)
            break;
        newNode = (LNode *) malloc(sizeof (LNode));
        newNode->data = value;
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
}

//遍历单向链表
void traverse_Node(LNode *L){
    LNode *p = L->next;
    while (p){
        printf("\033[1;32m%d\033[0m", p->data);
        printf(" -> ");
        p = p->next;
    }
    printf("\033[1;32mnull\033[0m\n");
}

//合并两个有序单向链表
void *mergeTwoLinkList(LNode *L1, LNode *L2){
    LNode *p1 = L1->next, *p2 = L2->next, *p3, *p3Head;
    p3Head = p3 = (LNode *) malloc(sizeof (LNode));
    while (p1 && p2){
        if(p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;
        } else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    if(p1){
        p3->next = p1;
    }
    if(p2){
        p3->next = p2;
    }
    return p3Head;
}

//逆置单向链表
LNode *reverseLinkList(LNode *L){
    //如果链表中没有节点或只有一个节点
    if(L->next == NULL || L->next->next == NULL)
        return L;
    LNode *p = L->next, *q = p->next;
    while (q){
        p->next = q->next;
        q->next = L->next;
        L->next = q;
        q = p->next;
    }
    return L;
}
