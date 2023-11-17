//
// Created by kanna on 2023/11/13.
//

#ifndef DATASTRUCT_SQLIST_H
#define DATASTRUCT_SQLIST_H

#endif //DATASTRUCT_SQLIST_H


//
// Created by kanna on 2023/11/13.
//

#ifndef DATASTRUCT_SQLIST_H
#define DATASTRUCT_SQLIST_H

#endif //DATASTRUCT_SQLIST_H

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define INITIAL 10
#define INCREASEMENT 1
#define  DataType int


typedef struct SqList {
    int *elem;
    int length;
    int listsize;
} SqList;

void initial_Sqlist(SqList *list){
    list->elem = (int*)malloc(sizeof(DataType)*INITIAL);
    list->length = 0;
    list->listsize = INITIAL;
}

void insertData_SqList(SqList *list){
    int vlaue = 0;
    printf("输入值：");
    while (true) {
        scanf("%d", &vlaue);
        if(vlaue == -1)
            break;
        if(list->listsize <= list->length){
//			list->elem = (int*)realloc(list->elem, sizeof(DataType) * (INCREASEMENT));
            list->elem = (int *)realloc(list->elem, sizeof(DataType) * (list->listsize + INCREASEMENT));
            list->listsize += INCREASEMENT;

        }
        list->elem[list->length] = vlaue;
        list->length++;
    }
}

void traverse_Sqlist(SqList *list){
    for(int term = 0; term < list->length; term++){
        printf("%d ", list->elem[term]);
    }
    printf("\t Length/Capacity: %d/%d\n", list->length, list->listsize);
}

void mergeTwoSqList(SqList *list1, SqList *list2, SqList *list3){
    int *plist1 = list1->elem, *plist2 = list2->elem, *plist3 = NULL;
    int *plist1End = list1->elem + list1->length, *plist2End = list2->elem + list2->length;
    list3->length = list1->length + list2->length;
    if(list3->listsize < list3->length){
        list3->elem = (int*)realloc(list3->elem, sizeof(DataType)*(list3->listsize + list3->length));
        list3->listsize = list3->length;
    }
    list3->length = list1->length + list2->length;
    //list3->listsize = list3->length;
    plist3 = list3->elem;
    while (plist1 < plist1End && plist2 < plist2End) {
        if(*plist1 < *plist2){
            *plist3 = *plist1;
            plist3++;
            plist1++;
        }
        else {
            *plist3 = *plist2;
            plist3++;
            plist2++;
        }
    }
    while (plist1 < plist1End) {
        *plist3 = *plist1;
        plist3++;
        plist1++;
    }
    while (plist2 < plist2End) {
        *plist3 = *plist2;
        plist3++;
        plist2++;
    }
}
