//
// Created by kanna on 2023/11/17.
//

#ifndef DATASTRUCT_BITREE_H
#define DATASTRUCT_BITREE_H

#endif //DATASTRUCT_BITREE_H

#include "stdio.h"
#include "stdlib.h"
#include "Queue.h"
#define DataType int
#define QUEUE_SIZE_BiT 100


//结构定义
typedef struct BiTNode {
    DataType data;
    struct BiTNode *lchild, *rchild;
} BiTNode;

//带空指针的先序序列生成一棵二叉树
BiTNode * BiT_Create(char str[], int *pi){
    BiTNode *root;
    char ch;
    ch = str[*pi];
    (*pi)++;
    if(ch == '*')
        return NULL;
    root = (BiTNode *) malloc(sizeof (BiTNode));
    root->data = ch;
    root->lchild = BiT_Create(str, pi);
    root->rchild = BiT_Create(str, pi);
    return root;
}

//根据先序序列和中序序列生成二叉树
BiTNode *premid(char pre[], char mid[], int pre_i, int mid_i, int n){
    int i = 0;
    BiTNode *root;
    if(n < 0)
        return NULL;
    while (i < n && pre[pre_i] != mid[mid_i + i])
        i++;
    root = (BiTNode *) malloc(sizeof (BiTNode));
    root->data = pre[pre_i];
    root->lchild = premid(pre, mid, pre_i + 1, mid_i, i);
    root->rchild = premid(pre, mid, pre_i + i + 1, mid_i + i + 1, n - i - 1);
    return root;
}

//先序遍历二叉树
void PreOrder(BiTNode *root){
    if(root){
        printf("%d ", root->data);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

//中序遍历二叉树
void InOrder(BiTNode *root){
    if(root){
        PreOrder(root->lchild);
        printf("%d ", root->data);
        PreOrder(root->rchild);
    }
}

//后序遍历二叉树
void PosOrder(BiTNode *root){
    if(root){
        PreOrder(root->lchild);
        PreOrder(root->rchild);
        printf("%d ", root->data);
    }
}

//释放二叉树中所有节点空间
void freeBiTree(BiTNode *root){
    if(root){
        freeBiTree(root->lchild);
        freeBiTree(root->rchild);
        free(root);
    }
}

//统计二叉树中的节点个数
int CountBiTreeNode(BiTNode *root){
    if(root == NULL)
        return 0;
    int leftCount = 0, rightCount = 0;
    leftCount = CountBiTreeNode(root->lchild);
    rightCount = CountBiTreeNode(root->rchild);
    return (leftCount + rightCount + 1);
}

//统计二叉树中叶子节点个数
int CountLeafNode(BiTNode *root){
    if(root == NULL)
        return 0;
    if(root->lchild == NULL && root->rchild == NULL)
        return 1;
    return (CountLeafNode(root->lchild) + CountBiTreeNode(root->rchild));
}

//求二叉树深度
int GetDeepth(BiTNode *root){
    int left = 0, right = 0;
    if(root == NULL)
        return 0;
    left = GetDeepth(root->lchild);
    right = GetDeepth(root->rchild);
    if(left > right)
        return left + 1;
    else
        return right + 1;
}


////层次遍历二叉树
//void layerTraverseBiTree(BiTNode *root){
//    BiTNode *p;
//    SqQueue *queue;
//    queue = (BiTNode *) malloc(sizeof (BiTNode) * QUEUE_SIZE_BiT);
//    initial_Queue(queue);
//    SqQueue_En(queue, root);
//    while ((p = SqQueue_De(queue) != NULL)){
//        printf("%c", p->data);
//        if(p->lchild)
//            SqQueue_En(queue, p->lchild);
//        if(p->rchild)
//            SqQueue_En(queue, p->rchild);
//    }
//}
//

////供二叉树层次遍历使用的队列数据操作
//void initial_Queue_With_BiTNode(SqQueue *Q){
//    //Q = ( *)malloc(sizeof(SqQueue));
//    Q->base = (BiTNode *)malloc(sizeof(BiTNode) * QUEUE_SIZE_BiT);
//    Q->front = Q->rear = 0;
//}
//
//void SqQueue_En_With_BiTNode(SqQueue *Q, BiTNode value) {
//    if(isFull(Q)) {
//        printf("Queue is full.\n");
//        return;
//    }
//    //printf("%d", value);
//    *(Q->base + Q->rear) = value;
//    Q->rear = (Q->rear + 1) % QUEUE_SIZE;
//}
//BiTNode *SqQueue_De_With_BiTNode(SqQueue *Q) {
//    if (isEmpty(Q)) {
//        printf("Queue is empty.\n");
//        //return;
//    }
//    //*Data = *(Q->base + Q->front);
//    DataType res = *(Q->base + Q->front);
//    Q->front = (Q->front + 1) % QUEUE_SIZE;
//    return res;
//}