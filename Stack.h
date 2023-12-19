//
// Created by kanna on 2023/11/13.
//

#ifndef DATASTRUCT_STACK_H
#define DATASTRUCT_STACK_H

#endif //DATASTRUCT_STACK_H

#define DataType int
#define INITIAL 10
#define INCREASEMENT 1
#include "stdlib.h"
#include "stdio.h"

typedef struct SqStack {
    DataType *top, *base;
    int stackSize;
} SqStack;

//初始化
SqStack *initial_Stack(){
    SqStack *stack;
    stack = (SqStack *) malloc(sizeof (SqStack));
    stack->base = stack->top = (DataType *) malloc(sizeof (DataType) * INITIAL);
    stack->stackSize = INITIAL;
    return stack;
}

//栈满
bool stackIsFull(SqStack *stack){
    return stack->top - stack->base == stack->stackSize;
}

//栈空
bool stackIsEmpty(SqStack *stack){
    return stack->top == stack->base;
}

//入棧操作
void push_SqStack(SqStack *stack, DataType value){
    if(stack->top - stack->base >= stack->stackSize){
        stack->base = (DataType *) realloc(stack->base, sizeof (DataType) * INCREASEMENT);
        stack->top  = stack->base + stack->stackSize;
        stack->stackSize += INCREASEMENT;
    }
    *(stack->top) = value;
    stack->top++;
}

//出棧操作
DataType pop_SqStack(SqStack *stack) {
    if(stack->base == stack->top){
        printf("Stack is Empty.\n");
        return (EXIT_FAILURE);
    }
    stack->top--;
    return *(stack->top);
}

//进制转换
//BaseNumber为基数
void decimal_To_Hexadecimal(SqStack *stack, int val, int BaseNumber){
    while (val){
        int remainder = val % BaseNumber;
        push_SqStack(stack, remainder);
        val /= BaseNumber;
    }
}

//输出转换后的数值
void print_Hexadecimal(SqStack *stack, int BaseNumber){
    printf("转换后的%d进制数为：", BaseNumber);
    if(BaseNumber == 16)
        printf("0x");
    int elem;
    while (stack->top != stack->base){
        elem = pop_SqStack(stack);
        if(elem < 10)
            printf("%d", elem);
        else
            printf("%c", 'a' + elem - 10);
    }
    printf("\n");
}