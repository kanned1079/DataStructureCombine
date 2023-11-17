//
// Created by kanna on 2023/11/17.
//

#ifndef DATASTRUCT_BITREE_H
#define DATASTRUCT_BITREE_H

#endif //DATASTRUCT_BITREE_H

#include "stdio.h"
#include "stdlib.h"
//#include "Queue.h"
#define DataType int
#define MAX_QUEUE_SIZE 100

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
        InOrder(root->lchild);
        printf("%d ", root->data);
        InOrder(root->rchild);
    }
}

//后序遍历二叉树
void PosOrder(BiTNode *root){
    if(root){
        PosOrder(root->lchild);
        PosOrder(root->rchild);
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

//以下是AI写的层次遍历二叉树 有逻辑错误
//包含一个专用队列和层次遍历函数

// 简单队列结构
typedef struct {
    BiTNode *array[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// 初始化队列
void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// 判断队列是否为空
int queueIsEmpty(Queue *queue) {
    return (queue->front == -1);
}

// 入队
void enqueue(Queue *queue, BiTNode *node) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }

    // 队列为空时，需要更新front
    if (queue->front == -1)
        queue->front = 0;

    // 入队
    queue->array[++queue->rear] = node;
}

// 出队
BiTNode* dequeue(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return NULL;
    }

    // 出队
    BiTNode *node = queue->array[queue->front++];

    // 队列为空时，重置front和rear
    if (queue->front > queue->rear)
        initQueue(queue);

    return node;
}


// 层次遍历二叉树
void LevelOrder(BiTNode *root) {
    if (root == NULL)
        return;

    // 创建一个队列，用于存储待访问的节点
    Queue queue;
    initQueue(&queue);

    // 将根节点入队
    enqueue(&queue, root);

    // 循环处理队列中的节点，直到队列为空
    while (!queueIsEmpty(&queue)) {
        // 出队并访问当前节点
        BiTNode *current = dequeue(&queue);
        printf("%d ", current->data);

        // 将左右子节点入队
        if (current->lchild != NULL)
            enqueue(&queue, current->lchild);
        if (current->rchild != NULL)
            enqueue(&queue, current->rchild);
    }
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