//
// Created by kanna on 2023/12/18.
//

#ifndef DATASTRUCT_HUFFENCODEDECODE_H
#define DATASTRUCT_HUFFENCODEDECODE_H

#endif //DATASTRUCT_HUFFENCODEDECODE_H

#include <stdio.h>
#include "stdlib.h"

typedef struct charweight{
    char ch;
    int weight;
} charweight;

typedef struct hfnode{
    int weight;
    int parent, lchild, rchild;
} HfmNode;

typedef struct hc{
    char ch;
    int start;
    char link[100];
} HfmCode;

//扫描源文件生成各字符权制表
int readFile(char src[], charweight *flist){
    FILE *fp;
    char ch;
    int j, i;
    fp = fopen(src, "rb");
    for(i = 255; i >= 0; i--)
        flist[i].weight = 0;
    i = 0;
    ch = fgetc(fp);
    while (ch != EOF) {
        for(j = 0; j <i && flist[j].ch != ch; j++);
        if(j == i)
            flist[j].weight++;
        ch = fgetc(fp);
    }
    fclose(fp);
    return i;
}

//建立Huffman树
void initHfmcode(int n, charweight *flist, HfmCode *hfmcode){
    //初始化huffman树中的各叶子节点的编码
    int i, j;
    for(i = 0; i < n; i++){
        hfmcode[i].ch = flist[i].ch;
        hfmcode[i].start = 99;
        for(j = 0; j < 100; j++)
            hfmcode[i].link[j] = '0';
    }
}

void select(int n, int *n1, int *n2, HfmNode *hfmtree){
    int i;
    int minimum = 200000;
    for(i = 0; i < n; i++){
        if(minimum >= hfmtree[i].weight && hfmtree[i].parent == -1){
            minimum = hfmtree[i].weight;
            *n2 = *n1;
            *n1 = i;
            continue;
        }
        if(hfmtree[*n2].weight > hfmtree[i].weight &&hfmtree[i].parent == -1)
            *n2 = i;

    }
}

void createHfm(int n, charweight *flist, HfmNode *hfmtree){
    int n1 = 0, n2 = 0, i = 0;
    for(i = 0; i < n; i++){
        hfmtree[i].weight = flist[i].weight;
        hfmtree[i].parent = hfmtree[i].lchild = hfmtree[i].rchild = -1;
    }
    for(i = n; i < (2*n-1); i++){
        n1 = n2 = i - 1;
        hfmtree[i].parent = hfmtree[i].lchild = hfmtree[i].rchild = -1;
        select(i, &n1, &n2, hfmtree);
        hfmtree[i].weight = hfmtree[n1].weight + hfmtree[n2].weight;
        hfmtree[i].rchild = n1;
        hfmtree[i].lchild = n2;
        hfmtree[n1].parent = hfmtree[n2].parent = i;
    }
}

//生成huffman树中各叶子节点的编码
void createHfmcode(int n, HfmNode *hfmtree, HfmCode *hfmcode){
    int i, node, parent;
    for(i = 0; i < n; i++){
        parent = hfmtree[i].parent;
        node = i;
        while (parent != -1){
            if(hfmtree[parent].lchild == node)
                hfmcode[i].link[hfmcode[i].start] = '0';
            else
                hfmcode[i].link[hfmcode[i].start] = '1';
            hfmcode[i].start--;
            node = parent;
            parent = hfmtree[node].parent;
        }
        hfmcode[i].start++;
    }
}

//生成压缩文件
void writeHead(char *desfile, charweight *flist, int n){
    FILE *fp;
    int i;
    fp = fopen(desfile, "wb");
    fprintf(fp, "%d", n);
    for(i = 0; i < n; i++)
        fprintf(fp, "%c%d ", flist[i].ch, flist[i].weight);
    fprintf(fp, "\n");
    fclose(fp);
}

void translate(char *srcfile, char  *desfile, int n, HfmCode *hfmcode){
    FILE *fp1, *fp2;
    char str[50000], ch, *p, cha;
    int i, j, k, c = 0;
    p = str;
    fp1 = fopen(srcfile, "rb");
    fp2 = fopen(desfile, "ab");
    ch = fgetc(fp1);
    while (ch != EOF){
        for(i = 0; i < n; i++){
            if(ch == hfmcode[i].ch){
                for(j = hfmcode[i].start; j < 100; j++, k++){
                    ch = hfmcode[i].link[j];
                    *p++ = ch;
                }
                break;
            }
        }
        ch = fgetc(fp1);
    }
    *p = '\0';
    p = str;
    k %= 8;
    fprintf(fp2, "%d", k);
    for(i = 1; *p; i++){
        ch = *p++;
        c = (ch - '0') + c * 2;
        if(i == 8){
            cha = c;
            fputc(cha, fp2);
            c = 0;
            i = 0;
        }
    }
    fputc(c, fp2);
    fclose(fp1);
    fclose(fp2);
}

//读取生成的压缩文件
int nreadFile(char *descode, charweight nflist[]){
    FILE *fp;
    int n, i;
    fp = fopen(descode, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++)
        fscanf(fp, " %c%d", &nflist[i].ch, &nflist[i].weight);
    fclose(fp);
    return n;
}

//将压缩文件还原为源文件
void restore(char  *descode, char  *destxt, int n, HfmCode *hfmcode){
    FILE *fp1, *fp2;
    char ch, bit;
    int i, node, current;
    HfmCode *currentCode;

    fp1 = fopen(descode, "rb");
    if (fp1 == NULL) {
        perror("Error opening compressed file");
        exit(EXIT_FAILURE);
    }

    fp2 = fopen(destxt, "wb");
    if (fp2 == NULL) {
        perror("Error creating restored file");
        exit(EXIT_FAILURE);
    }

    fseek(fp1, (n + 1) * sizeof(char) * 5, SEEK_SET);  // Skip header information

    node = 2 * n - 2;  // Start from the root of the Huffman tree
    current = 0;

    while ((ch = fgetc(fp1)) != EOF) {
        for (i = 7; i >= 0; i--) {
            bit = (ch >> i) & 1;
            currentCode = &hfmcode[current];

            if (bit == 0) {
                // Move to the left child
                node = currentCode->start == 99 ? currentCode->link[0] : currentCode->link[currentCode->start + 1];
            } else {
                // Move to the right child
                node = currentCode->start == 99 ? currentCode->link[1] : currentCode->link[currentCode->start + 1] + 1;
            }

            if (node < n) {
                // Leaf node reached, write the character to the output file
                fputc(hfmcode[node].ch, fp2);
                node = 2 * n - 2;  // Reset to the root of the Huffman tree
            }

            current = node;
        }
    }

    fclose(fp1);
    fclose(fp2);
}

//int main(int argc, char *argv[]) {
//
//
//}