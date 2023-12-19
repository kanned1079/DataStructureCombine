//
// Created by kanna on 2023/11/13.
//

#ifndef DATASTRUCT_STRINGS_H
#define DATASTRUCT_STRINGS_H

#endif //DATASTRUCT_STRINGS_H

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define MAXSIZE 100

typedef char String[MAXSIZE];

//获取串长度
int myStrlen(String string){
    int length = 0;
    while (string[length] != '\0'){
        length++;
    }
    return length;
}

//连接两个串
void myConcat(String string1, String string2){
    int str1_length = myStrlen(string1), str2_length = myStrlen(string2);
    int sq;
    for(sq = 0; sq < str2_length; sq++){
        string1[str1_length + sq]  = string2[sq];
    }
    string1[str1_length + str2_length] = '\0';
}

//比较两个串
int myStrcmp(String string1, String string2){
    int i = 0;
    while (string1[i] && string2[i]){
        if(string1[i] != string2[i]) {
            return string1[i] - string2[i];
        }
        i++;
    }
    return 0;
}

//生成next数组
int getNextArray(char *pattern, int *next, int patternLength) {
    int len = 0;
    int i = 1;
    next[0] = -1;
    next[1] = 0;

    while (i < patternLength) {
        if (pattern[i] == pattern[len]) {
            len++;
            next[i + 1] = len;
            i++;
        } else {
            if (len != 0) {
                len = next[len];
            } else {
                next[i + 1] = 0;
                i++;
            }
        }
    }
//  printf("%d\n", i);
    return i;
}

//暴力查找 必考
int BF_Search(String string, String target){
    int i = 0, j = 0;
    while(string[i] && target[j]){
        if(string[i] == target[j]){
            i++;
            j++;
        }else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(target[j] == '\0')
        return i - j;
    else
        return -1;
}

//KMP查找 必考45
int KMP_Search(String string, String target, int *next){
    int i = 0, j = 0;
    while(string[i] && target[j]){
        if(string[i] == target[j] || j == -1){
            i++;
            j++;
        }else{
            //i = i - j + 1;
            j = next[j];
            //j = 0;
            i++;
        }
    }
    if(target[j] == '\0')
        return i - j;
    else
        return -1;
}

//int getNextArray2(char *pattern, int *next, int patternLength) {
//    int len = 0;
//    int i = 1;
//    next[0] = -1;
//
//    while (i < patternLength) {
//        if (pattern[i] == pattern[len]) {
//            len++;
//            next[i] = len;
//            i++;
//        } else {
//            if (len != 0) {
//                len = next[len - 1];
//            } else {
//                next[i] = 0;
//                i++;
//            }
//        }
//    }
//    return i; // 返回 pattern 的长度
//}
