//
// Created by kanna on 2023/11/17.
//

#ifndef DATASTRUCT_BITREE_H
#define DATASTRUCT_BITREE_H

#endif //DATASTRUCT_BITREE_H

#include "stdio.h"
#include "stdlib.h"
#define DataType int

typedef struct BiTNode {
    DataType data;
    struct BiTNode *lchild, *rchild;
} BiTNode;

