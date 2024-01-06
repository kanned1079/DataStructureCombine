//
// Created by kanna on 2023/11/17.
//

// ////////////////////////////////////////////////

#ifndef DATASTRUCT_GLIST_H
#define DATASTRUCT_GLIST_H

#endif //DATASTRUCT_GLIST_H

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define Atomtype int

//广义表结构定义
typedef enum {ATOM, LIST} ElemTag;
typedef enum {END, LP, RP, ATOMFLAG } ElemFlag;
typedef struct GLNode {
    ElemTag tag;
    union {
        Atomtype atom;
        struct GLNode *child;
    } UNION;
    struct GLNode *next;
} GLNode;

//创建广义表的算法
ElemFlag GetElem(char str[], int *pi, Atomtype *pe){
    while (str[*pi] == ' ')
        (*pi)++;
    if(str[*pi] == '\0')
        return (END);
    if(str[*pi] == '('){
        (*pi)++;
        return (LP);
    }
    if(str[*pi] == ')'){
        (*pi)++;
        return (RP);
    }
    *pe = str[*pi];
    (*pi)++;
    return ATOMFLAG;
}

GLNode *Glist_Create(char str[], int *pi){
    GLNode *p;
    Atomtype e;
    switch (GetElem(str, pi, &e)){
        case ATOMFLAG:{
            p = (GLNode *) malloc(sizeof (GLNode));
            p->tag = ATOM;
            p->UNION.atom = e;
            p->next = Glist_Create(str, pi);
            return p;
        }
        case LP:{
            p = (GLNode *) malloc(sizeof (GLNode));
            p->tag = LIST;
            p->UNION.child = Glist_Create(str, pi);
            p->next = Glist_Create(str, pi);
            return p;
        }
        case RP: return NULL;
        case END: return NULL;
    }
}

//求广义表长度
int GetGListLength(GLNode *L){
    GLNode *p;
    int length = 0;
    if(L->tag == LIST)
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

// 释放广义表内存
void FreeGList(GLNode *L) {
    if (L != NULL) {
        FreeGList(L->UNION.child);
        FreeGList(L->next);
        free(L);
    }
}

