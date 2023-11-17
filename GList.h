//
// Created by kanna on 2023/11/17.
//

#ifndef DATASTRUCT_GLIST_H
#define DATASTRUCT_GLIST_H

#endif //DATASTRUCT_GLIST_H

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define Atomtype int

//广义表结构定义
typedef enum {ATOM, LIST} ElemTag;
typedef struct GLNode {
    ElemTag tag;
    union {
        Atomtype atom;
        struct GLNode *child;
    };
    struct GLNode *next;
} GLNode;

//创建广义表的算法
/*
 不会
*/

/*
有错
//求广义表长度
int GetGListLength(GLNode *L){
    GLNode *p;
    int length = 0;
    for(p = L->UNION.child; p; p = p->next)
        length++;
    return length;
}

//求广义表深度
int GetGListDeepth(GLNode *L){
    GLNode *p;
    int depth, max = 0;
    if(L->tag == ATOM)
        return 0;
    for(p = L->UNION.child; p; p = p->next){
        depth = GetGListDeepth(p);
        if(depth > max)
            max = depth;
    }
    return max+1;
}

//遍历广义表
void TraverseGList(GLNode *L){
    GLNode *p;
    for(p = L; p != NULL; p = p->next){
        if(p->tag == ATOM){
            printf("%c ", p->UNION.child);
        } else{
            putchar('(');
            TraverseGList(p->UNION.child);
            putchar(')');
        }
    }
}


*/

