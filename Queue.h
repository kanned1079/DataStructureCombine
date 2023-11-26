  //
// Created by kanna on 2023/11/17.
//

#ifndef DATASTRUCT_QUEUE_H
#define DATASTRUCT_QUEUE_H

#endif //DATASTRUCT_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DataType int
#define QUEUE_SIZE 200

typedef struct SqQueue {
    DataType *base;
    int front, rear;
} SqQueue;

//SqQueue *initial() {
//  SqQueue *Q = (SqQueue *)malloc(sizeof(SqQueue));
//  Q->base = (DataType*)malloc(sizeof(DataType) * QUEUE_SIZE);
//  Q->front = Q->rear = 0;
//  return Q;
//}

//初始化队列
void initial_Queue(SqQueue *Q){
    //Q = (SqQueue *)malloc(sizeof(SqQueue));
    Q->base = (DataType *)malloc(sizeof(DataType) * QUEUE_SIZE);
    Q->front = Q->rear = 0;
}

//队列满
bool isFull(SqQueue *Q) {
    return (Q->front == (Q->rear + 1) % QUEUE_SIZE);
}

//队列空
bool isEmpty(SqQueue *Q) {
    return (Q->front == Q->rear);
}

//入队列
void SqQueue_En(SqQueue *Q, DataType value) {
    if(isFull(Q)) {
        printf("Queue is full.\n");
        return;
    }
    //printf("%d", value);
    *(Q->base + Q->rear) = value;
    Q->rear = (Q->rear + 1) % QUEUE_SIZE;
}

//出队列
DataType SqQueue_De(SqQueue *Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        //return;
    }
    //*Data = *(Q->base + Q->front);
    DataType res = *(Q->base + Q->front);
    Q->front = (Q->front + 1) % QUEUE_SIZE;
    return res;
}

//生成杨辉三角
void generate_YanghuiTriangle(SqQueue *Q, int line, int *result){
    int i, j, t, elem1, elem2;
    int length = 0;
    SqQueue_En(Q, 0);
    SqQueue_En(Q, 1);
    SqQueue_En(Q, 1);
    elem1 = SqQueue_De(Q);
    elem2 = SqQueue_De(Q);
    for(i = 1; i <= line; i++){
        SqQueue_En(Q, 0);
        for(j = 1; j <= i + 2; j++){
            //printf("%d %d \n", elem1, elem2);
            SqQueue_En(Q, elem1 + elem2);
            {
                result[length] = elem1 + elem2;
                length++;
            }
            elem1 = elem2;
            elem2 = SqQueue_De(Q);
        }
    }
    printf("行 1：   1\n");
    Q->front = 0;
    for(i = 1; i <= line; i++){
        printf("行%2d：   ", i+1);
//      for(t = 1; t <= (line - i) * 4 + 1; t++)
//          printf(" ");
        for(j = 1; j <= i + 2; j++){
            int num = SqQueue_De(Q);
            if(num != 0)
                printf("%d "  , num);
        }
        printf("\n");
    }
}
