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

//int main() {
//    VertexType vertices[] = {1, 2, 3, 4, 5};
//    ALGraph graph;
//
//    ALGraph_Init(&graph, vertices, 5);
//
//    // 插入边
//    ALGraph_Insert(&graph, 0, 1);
//    ALGraph_Insert(&graph, 0, 3);
//    ALGraph_Insert(&graph, 1, 2);
//    ALGraph_Insert(&graph, 1, 4);
//    ALGraph_Insert(&graph, 3, 2);
//    ALGraph_Insert(&graph, 4, 3);
//
//    // 遍历图 - 深度优先搜索
//    int visited_dfs[5] = {0};
//    printf("使用递归的优先深度搜索： ");
//    for (int i = 0; i < graph.vexnum; i++) {
//        if (!visited_dfs[i]) {
//            DFS(&graph, i, visited_dfs);
//        }
//    }
//    printf("\n");
//
//    // 非递归深度优先搜索遍历图
//    int visited_non_recursive[5] = {0};
//    printf("不使用递归的优先深度搜索： ");
//    DFS_NonRecursive(&graph, 0, visited_non_recursive);
//
//    // 遍历图 - 广度优先搜索
//    printf("广度优先搜索： ");
//    int visited_bfs[5] = {0};
//    BFS(&graph, 0, visited_bfs);
//
//    free(graph.vertexes);  // 释放动态分配的内存
//
//    return 0;
//}
