#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100
#define VertexType int

typedef int VRType;
typedef int InfoType;

// 数组表示法的图结构
typedef struct ArcCell {
    VRType adj;
    InfoType *info;
} ArcCell;

typedef struct {
    VertexType vexs[MAX_VERTEX];
    ArcCell arcs[MAX_VERTEX][MAX_VERTEX];
    int vexnum, arcnum;
} MGraph;

// 邻接表表示法的图结构
typedef struct ArcNode {
    int adjvex;
    InfoType *info;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VexNode {
    VertexType data;
    ArcNode *firstarc;
} VexNode;

typedef struct {
    VexNode *vertexes;
    int vexnum, arcnum;
} ALGraph;

// 初始化邻接表图
void ALGraph_Init(ALGraph *G, VertexType data[], int n) {
    G->vexnum = n;
    G->arcnum = 0;
    G->vertexes = (VexNode *)malloc(n * sizeof(VexNode));

    for (int i = 0; i < n; i++) {
        G->vertexes[i].data = data[i];
        G->vertexes[i].firstarc = NULL;
    }
}

// 插入边到邻接表图
void ALGraph_Insert(ALGraph *G, int v1, int v2) {
    ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = v2;
    p->nextarc = G->vertexes[v1].firstarc;
    G->vertexes[v1].firstarc = p;
    G->arcnum++;
}

// 深度优先搜索遍历图
void DFS(ALGraph *G, int v, int visited[]) {
    printf("%d ", G->vertexes[v].data);
    visited[v] = 1;

    ArcNode *p = G->vertexes[v].firstarc;
    while (p != NULL) {
        if (!visited[p->adjvex]) {
            DFS(G, p->adjvex, visited);
        }
        p = p->nextarc;
    }
}

// 非递归深度优先搜索遍历图
void DFS_NonRecursive(ALGraph *G, int start, int visited[]) {
    int stack[MAX_VERTEX];
    int top = -1;

    stack[++top] = start;
    visited[start] = 1;

    while (top != -1) {
        int current = stack[top--];
        printf("%d ", G->vertexes[current].data);

        ArcNode *p = G->vertexes[current].firstarc;
        while (p != NULL) {
            if (!visited[p->adjvex]) {
                stack[++top] = p->adjvex;
                visited[p->adjvex] = 1;
            }
            p = p->nextarc;
        }
    }

    printf("\n");
}

// 广度优先搜索遍历图
void BFS(ALGraph *G, int start, int visited[]) {
    int queue[MAX_VERTEX];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front != rear) {
        int current = queue[front++];
        printf("%d ", G->vertexes[current].data);

        ArcNode *p = G->vertexes[current].firstarc;
        while (p != NULL) {
            if (!visited[p->adjvex]) {
                queue[rear++] = p->adjvex;
                visited[p->adjvex] = 1;
            }
            p = p->nextarc;
        }
    }

    printf("\n");
}
