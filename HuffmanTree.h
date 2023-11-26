//
// Created by kanna on 2023/11/21.
//

#ifndef DATASTRUCT_HUFFMANTREE_H
#define DATASTRUCT_HUFFMANTREE_H

#endif //DATASTRUCT_HUFFMANTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256
#define MAX_CODE_LENGTH 256

typedef struct HuffmanNode {
    char data;
    unsigned freq;
    struct HuffmanNode *left, *right;
} HuffmanNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    HuffmanNode** array;
} MinHeap;

HuffmanNode* createNode(char data, unsigned freq) {
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (HuffmanNode**)malloc(capacity * sizeof(HuffmanNode*));
    return minHeap;
}

void swapNodes(HuffmanNode** a, HuffmanNode** b) {
    HuffmanNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

MinHeap* buildMinHeap(char data[], unsigned freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(data[i], freq[i]);

    minHeap->size = size;
    for (int i = (size - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);

    return minHeap;
}

HuffmanNode* extractMin(MinHeap* minHeap) {
    HuffmanNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, HuffmanNode* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

int isLeaf(HuffmanNode* root) {
    return !(root->left) && !(root->right);
}

HuffmanNode* buildHuffmanTree(char data[], unsigned freq[], int size) {
    HuffmanNode *left, *right, *top;
    MinHeap* minHeap = buildMinHeap(data, freq, size);

    while (minHeap->size > 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void storeCodes(HuffmanNode* root, char codes[MAX_CODE_LENGTH], int top, char huffmanCodes[MAX_TREE_NODES][MAX_CODE_LENGTH]) {
    if (root->left) {
        codes[top] = '0';
        storeCodes(root->left, codes, top + 1, huffmanCodes);
    }

    if (root->right) {
        codes[top] = '1';
        storeCodes(root->right, codes, top + 1, huffmanCodes);
    }

    if (isLeaf(root)) {
        codes[top] = '\0';
        strcpy(huffmanCodes[root->data], codes);
    }
}

void huffmanCodes(char data[], unsigned freq[], int size) {
    HuffmanNode* root = buildHuffmanTree(data, freq, size);

    char codes[MAX_CODE_LENGTH];
    char huffmanCodes[MAX_TREE_NODES][MAX_CODE_LENGTH];
    storeCodes(root, codes, 0, huffmanCodes);

    printf("Huffman Codes:\n");
    for (int i = 0; i < size; ++i)
        printf("%c: %s\n", data[i], huffmanCodes[data[i]]);
}

