#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"
#include "DuNode.h"
#include "SqList.h"
#include "Stack.h"
#include "Strings.h"
#include "Queue.h"
#include "GList.h"
#include "BiTree.h"
#include "HuffmanTree.h"
#include "Graph.h"
#include "Search.h"
#include "HuffEncodeDecode.h"

int main(int argc, char *argv[]) {
    void operate_LinkList();
    void operate_DuLinkList();
    void operate_SqList();
    void operate_Stack();
    void operate_Strings();
    void operate_Queue();
    void operate_BiTree();
    void operate_GList();
    void fileCompressWithHuffman();
    void operate_Graph();
    void operate_Search();
    void operate_EnDecode();

    outset:
    printf("数据结构： \n"
           " ├──顺序表 [0]\n"
           " │  └─合并两个顺序表\n"
           " ├──单链表 [1]\n"
           " │  ├─合并链表\n"
           " │  ├─逆序链表\n"
           " │  └─获取链表中的节点数\n"
           " ├──双向链表 [2]\n"
           " │  └─插入节点\n"
           " ├──棧 [3]\n"
           " │  └─进制转换\n"
           " ├──串 [4]\n"
           " │  ├─求串长度\n"
           " │  ├─串比大小\n"
           " │  ├─串连接\n"
           " │  └─模式匹配\n"
           " │    ├─BF算法\n"
           " │    └─KMP算法\n"
           " ├──队列 [5]\n"
           " │  └─杨辉三角形\n"
           " ├──广义表 [6]\n"
           " │  ├─求广义表长度\n"
           " │  ├─求广义表深度\n"
           " │  └─遍历广义表\n"
           " ├──树 [7]\n"
           " │  ├─创建树\n"
           " │  │  ├─根据先序序列和中序序列生成二叉树\n"
           " │  │  └─带空指针的先序序列生成一棵二叉树\n"
           " │  └─遍历\n"
           " │    ├─先序遍历\n"
           " │    ├─中序遍历\n"
           " │    ├─后序遍历\n"
           " │    └─使用队列进行层次遍历\n"
           " ├──哈曼夫树 [8]\n"
           " │  └─压缩txt\n"
           " ├──图 [9]\n"
           " │  ├─创建图\n"
           " │  │  ├─插入数据\n"
           " │  │  └─插入边\n"
           " │  ├─遍历\n"
           " │  │  ├─使用递归的优先深度搜索\n"
           " │  │  ├─非递归深度优先搜索遍历图\n"
           " │  │  └─广度优先搜索\n"
           " │  └─最短路径\n"
           " ├──查找 [10]\n"
           " │  ├─排序\n"
           " │  │  ├─不排序\n"
           " │  │  ├─选择排序\n"
           " │  │  ├─冒泡排序\n"
           " │  │  ├─插入排序\n"
           " │  │  └─堆排序\n"
           " │  └─查询方式\n"
           " │     ├─顺序查找\n"
           " │     └─折半查找\n"
           " │  \n"
           " └─未完待续\n");
    int tag;
    restart:
    printf("\033[1;35m选择使用的数据结构：\033[0m");
    scanf("%d", &tag);
    switch (tag) {
        case 0: operate_SqList();
            break;
        case 1: operate_LinkList();
            break;
        case 2: operate_DuLinkList();
            break;
        case 3: operate_Stack();
            break;
        case 4: operate_Strings();
            break;
        case 5: operate_Queue();
            break;
        case 6: operate_GList();
            break;
        case 7: operate_BiTree();
            break;
        case 8: fileCompressWithHuffman();
            break;
        case 9: operate_Graph();
            break;
        case 10: operate_Search();
            break;
        case 11: operate_EnDecode();
            break;
        default:
            printf("\033[1;31mERROR\n\033[0m");
            goto restart;
            break;
    }

    printf("----------------------\n"
           "返回一级菜单(1) 结束程序(0)：");
    int maintag = 1;
    scanf("%d", &maintag);
    if(maintag == 1)
        goto outset;
    else
        return 0;
    //return 0;
}

void operate_SqList(){
    printf("----------------------\n"
           "合并两个顺序表\n");
    SqList sq1, sq2, sq3;
    initial_Sqlist(&sq1);
    initial_Sqlist(&sq2);
    initial_Sqlist(&sq3);
    printf("初始化sq1, sq2, sq3完成\n"
           "----------------------\n"
           "插入sq1, sq2的数据：\n");
    printf("sq1: ");
    insertData_SqList(&sq1);
    printf("sq2: ");
    insertData_SqList(&sq2);
    printf("----------------------\n");
    traverse_Sqlist(&sq1);
    traverse_Sqlist(&sq2);
    printf("----------------------\n");
    mergeTwoSqList(&sq1, &sq2, &sq3);
    printf("合并后的顺序表：");
    traverse_Sqlist(&sq3);

    free(sq1.elem);
    free(sq2.elem);
    free(sq3.elem);
}

void operate_LinkList(){
    printf("----------------------\n"
           "链表操作\n"
           " ├─合并链表 [0]\n"
           " ├─逆序链表 [1] \n"
           " └─获取链表中节点数 [2]\n");
    int choose;
    printf("\033[1;35m选择子项目：\033[0m");
    scanf("%d", &choose);
    switch (choose) {
        case 0: {
            LNode *L1, *L2, *L3;
            printf("----------------------\n"
                   "创建了三个链表\n");
            L1 = initial_HeadNode();
            L2 = initial_HeadNode();
            L2 = initial_HeadNode();
            printf("初始化完成\n----------------------\n");
            printf("L1插入数据：");
            append_Node(L1);
            printf("L2插入数据：");
            append_Node(L2);
            printf("----------------------\n"
                   "L1数据： ");
            traverse_Node(L1);
            printf("L2数据： ");
            traverse_Node(L2);
            printf("----------------------\n"
                   "L1, L2合并到L3：");
            L3 = mergeTwoLinkList(L1, L2);
            traverse_Node(L3);
            printf("L3中有%d个10\n", searchLinklistNodes(L3, 10));
        }
        case 1: {
            LNode *L;
            printf("创建了一个链表\n----------------------\n");
            L = initial_HeadNode();
            printf("L 插入数据：");
            append_Node(L);
            printf("----------------------\n"
                   "L 原数据：");
            traverse_Node(L);
            printf("----------------------\n"
                   "L 逆序后：");
            L = reverseLinkList(L);
            traverse_Node(L);
        }
        case 2: {
            LNode *L;
            printf("创建了一个链表\n----------------------\n");
            L = initial_HeadNode();
            printf("L 插入数据：");
            append_Node(L);
            printf("----------------------\n"
                   "L 原数据：");
            traverse_Node(L);
            printf("----------------------\n"
                   "L 中的节点数：%d 个\n", countLNodeNums(L));
        }
    }
}

void operate_DuLinkList(){
    // 创建双向链表节点p和q
    DuNode *p = (DuNode *)malloc(sizeof(DuNode));
    DuNode *q = (DuNode *)malloc(sizeof(DuNode));
    if (p == NULL || q == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    p->data = 1;
    q->data = 3;

    printf("----------------------\n在节点p和节点q之间插入新节点\n");
    // 在节点p和节点q之间插入新节点
    insertNodeBetween(p, q, 2);

    // 打印链表
    printf("Linked list: %d <-> %d <-> %d\n", p->data, p->next->data, p->next->next->data);

    // 释放内存
    free(p->next);
    free(p);
    free(q);
}

void operate_Stack(){
    SqStack *stack = initial_Stack();
    printf("进制转换\n----------------------\n");
    int decimal = 0, basenumber = 10;
    printf("输入一个10进制数：");
    scanf("%d", &decimal);
    printf("输入转换的进制：");
    scanf("%d", &basenumber);
    decimal_To_Hexadecimal(stack, decimal, basenumber);
    printf("----------------------\n");
    print_Hexadecimal(stack,basenumber);
}

void operate_Strings(){
    //printf("串的操作\n----------------------\n");
    printf("输入串1数据：");
    String string1;
    //String string1 = "ADBADABBAABADABBADADA";
    scanf("%s", string1);
    printf("输入串2数据：");
    //String string2;
    String string2 = "ADABBADADA";
    scanf("%s", string2);
    printf("----------------------\n");
    printf("串的操作\n"
           " ├─获取长度 [0]\n"
           " ├─比较大小 [1]\n"
           " ├─串连接 [2]\n"
           " ├─BF模式匹配 [3]\n"
           " └─KMP模式匹配 [4]\n");
    int tag;
    printf("\033[1;35m选择子项目：\033[0m");
    scanf("%d", &tag);
    printf("----------------------\n");
    switch (tag) {
        case 0:
            printf("串1长度：%d\n", myStrlen(string1));
            printf("串2长度：%d\n", myStrlen(string1));
            break;
        case 1: {
            int cmp = myStrcmp(string1, string2);
            printf("比较大小：%d\t%s\n", cmp, cmp>0?"串1 > 串2":"串1 < 串2");
        }
            break;
        case 2:{
            myConcat(string1, string2);
            printf("将S2连接到S1后：%s\n", string1);
        }
            break;
        case 3:{
            int res = BF_Search(string1, string2);
            printf("BF查询结果：");
            if(res == -1)
                printf("在源字符串中未找到子串\n");
            else
                printf("在源字符串的第%d下标处找到了子串\n", res);
        }
            break;
        case 4:{
            int *next = (int *) malloc(sizeof (int) * myStrlen(string2));
            int len = getNextArray(string2, next, myStrlen(string2));
            {
                printf("Next[%d]: ", len);
                for(int i = 0; i < len; i++)
                    printf("%d ", next[i]);
                printf("\n");
            }
            int res = KMP_Search(string1, string2, next);
            if(res == -1)
                printf("在源字符串中未找到子串\n");
            else
                printf("在源字符串的第%d下标处找到了子串\n", res);

        }
            break;
    }
}

void operate_Queue(){
    printf("----------------------\n");
    SqQueue *queue=(SqQueue *)malloc(sizeof(SqQueue));
    initial_Queue(queue);
    printf("输入三角的行数：");

    int lines = 0;
    scanf("%d", &lines);
    DataType result[QUEUE_SIZE];
    printf("----------------------\n");
    generate_YanghuiTriangle(queue, lines-1, result);
    free(queue->base);
    free(queue);
}

void operate_GList(){
    char input[] = "((1 2) (3 4 (5 6)) 7)";
    int index = 0;
    printf("----------------------\n"
           "创建广义表：%s\n"
           "----------------------\n", input);
    GLNode *root = Glist_Create(input, &index);

    // 输出广义表
    printf("广义表长度: %d\n", GetGListLength(root));
    printf("广义表深度: %d\n", GetGListDeepth(root));
    printf("遍历广义表: ");
    TraverseGList(root);
    putchar('\n');

    // 释放广义表内存
    FreeGList(root);

}

void operate_BiTree(){
    printf("----------------------\n"
           "创建二叉树的方法\n"
           " ├─根据先序序列和中序序列生成二叉树 [0]\n"
           " └─带空指针的先序序列生成一棵二叉树 [1]\n");
    int tag;

    printf("----------------------\n");
    chooseL1:
    printf("\033[1;35m选择创建方法：\033[0m");
    scanf("%d", &tag);
    printf("----------------------\n");
    char preorder[] = "ABDECF";
    char inorder[] = "DBEACF";
    char Npreorder[] = "AB*D**C**";
    BiTNode *root;
    switch (tag) {
        case 0:{
            // 提供先序和中序遍历序列
            printf("使用的先序序列：%s\n", preorder);
            printf("输入中序序列：%s\n", inorder);
            // 定义索引变量
            int preIndex = 0;
            // 创建二叉树
            root = premid(preorder, inorder, 0, 0, 6, &preIndex);
        }
            break;
        case 1:
        {
            printf("使用的先序序列：%s\n", Npreorder);
            // 定义索引变量
            int preIndex = 0;
            // 创建二叉树
            root = BiT_Create(Npreorder, &preIndex);
        }
            break;
        default:
            goto chooseL1;
    }
    printf("----------------------\n"
           "二叉树操作\n"
           " ├─四种输出 [0]\n"
           " ├─统计节点个数 [1]\n"
           " ├─统计叶子节点个数 [2]\n"
           " ├─获取二叉树深度 [3]\n"
           " ├─释放空间 [4]\n"
           " ├─交换左右子树 [5]\n"
           " └─操作所有 [6]\n"
           "----------------------\n");
    choose2:
    printf("\033[1;35m选取操作：\033[0m");
    scanf("%d", &tag);
    printf("----------------------\n");
    switch (tag) {
        case 0:{
            printf("先序遍历结果: ");
            PreOrder(root);
            printf("\n中序遍历结果: ");
            InOrder(root);
            printf("\n后序遍历结果: ");
            PosOrder(root);
            printf("\n层次遍历结果: ");
            LevelOrder(root);
        }
            break;
        case 1:
            printf("节点个数: %d\n", CountBiTreeNode(root));
            break;
        case 2:
            printf("叶子节点个数: %d\n", CountLeafNode(root));
            break;
        case 3:
            printf("二叉树深度: %d\n", GetDeepth(root));
            break;
        case 4:{
            freeBiTree(root);
            printf("Done.\n");
        }
            break;
        case 5: {
//            printf("源二叉树层次遍历结果: ");
//            LevelOrder(root);
//            ExchangeOffspringTrees(root);
//            printf("\n交换后二叉树层次遍历结果: ");
//            LevelOrder(root);
            showExchange(root);
        }
            break;
        case 6: {
            printf("先序遍历结果: ");
            PreOrder(root);
            printf("\n中序遍历结果: ");
            InOrder(root);
            printf("\n后序遍历结果: ");
            PosOrder(root);
            printf("\n层次遍历结果: ");
            LevelOrder(root);

            printf("\n节点个数: %d\n", CountBiTreeNode(root));

            printf("叶子节点个数: %d\n", CountLeafNode(root));

            printf("二叉树深度: %d\n", GetDeepth(root));
            showExchange(root);
        }
            break;
        default:
            goto choose2;
    }
    printf("\n");

    // 释放二叉树内存
    freeBiTree(root);
}

void fileCompressWithHuffman(){
    printf("----------------------\n");
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    unsigned freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    huffmanCodes(data, freq, size);
}

void operate_Graph(){
    printf("----------------------\n");
    VertexType vertices[] = {1, 2, 3, 4, 5};
    printf("插入的数据：");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", vertices[i]);
    }
    printf("\n----------------------\n");
    ALGraph graph;
    ALGraph_Init(&graph, vertices, 5);
    // 插入边
    ALGraph_Insert(&graph, 0, 1);
    ALGraph_Insert(&graph, 0, 3);
    ALGraph_Insert(&graph, 1, 2);
    ALGraph_Insert(&graph, 1, 4);
    ALGraph_Insert(&graph, 3, 2);
    ALGraph_Insert(&graph, 4, 3);

    printf("选择遍历的方法\n"
           " ├─使用递归的优先深度搜索 [0]\n"
           " ├─不使用递归的优先深度搜索 [1]\n"
           " └─广度优先搜索 [2]\n");
    int tag;
    printf("\033[1;35m选择遍历方法：\033[0m");
    scanf("%d", &tag);
    printf("----------------------\n");
    switch (tag) {
        case 0:{
            // 遍历图 - 深度优先搜索
            int visited_dfs[5] = {0};
            printf("使用递归的优先深度搜索： ");
            for (int i = 0; i < graph.vexnum; i++) {
                if (!visited_dfs[i]) {
                    DFS(&graph, i, visited_dfs);
                }
            }
            printf("\n");
        }
            break;
        case 1:{
            // 非递归深度优先搜索遍历图
            int visited_non_recursive[5] = {0};
            printf("不使用递归的优先深度搜索： ");
            DFS_NonRecursive(&graph, 0, visited_non_recursive);
        }
            break;
        case 2:{
            // 遍历图 - 广度优先搜索
            printf("广度优先搜索： ");
            int visited_bfs[5] = {0};
            BFS(&graph, 0, visited_bfs);
        }
            break;
    }
    free(graph.vertexes);  // 释放动态分配的内存
}

void operate_Search(){
    srand((unsigned int)time(NULL));
    int length = 0,minR, maxR;
    int term = 0;
    int target = 0;
    printf("----------------------\n");
    printf("\033[1;35m生成的随机数长度：\033[0m");
    scanf("%d", &length);
    printf("\033[1;35m最小：\033[0m");
    scanf("%d", &minR);
    printf("\033[1;35m最大：\033[0m");
    scanf("%d", &maxR);
    SSTable ssTable;
    initial_ssTable(&ssTable, length);
    insertRandomNums(ssTable.data, length, minR, maxR);

    printf("----------------------\n");
    sort:
    printf("排序方式\n"
           " ├─不排序 [0]\n"
           " ├─选择排序 [1]\n"
           " ├─冒泡排序 [2]\n"
           " ├─冒泡排序(沉底) [3]\n"
           " ├─插入排序 [4]\n"
           " ├─堆排序 [5]\n"
           " └─快速排序 [6]\n");
    int sortTag;
    printf("\033[1;35m请选择排序的方法：\033[0m");
    scanf("%d", &sortTag);
    switch (sortTag) {
        case 0:
            printf("跳过了排序\n");
            break;
        case 1:
            selectSort(&ssTable);
            break;
        case 2:
            maopaoSort(&ssTable);
            break;
        case 3:
            bubbleSort(&ssTable);
            break;
        case 4:
            myInsertSort(&ssTable);
            break;
        case 5:
            heapSort(&ssTable);
            break;
        case 6:
            quickSort(&ssTable, 0, ssTable.length - 1);
            break;

    }

    if(term == 0){
        printf("\033[1;35m显示数组内容吗：\033[0m");
        int showTag;
        scanf("%d", &showTag);
        if(showTag == 1){
            traverseTable(&ssTable);
        } else {
            printf("不显示\n");
        }
        printf("\033[1;35m要搜索的目标值：\033[0m");
        scanf("%d", &target);
    }

    printf("----------------------\n");
    int searchResult, searchWay;
    printf("查询方式\n"
           " ├─顺序查找 [0]\n"
           " ├─折半查找 [1]\n"
           " └─差分查找 [2]\n");
    printf("\033[1;35m请选择搜索方法：\033[0m");
    scanf("%d", &searchWay);

    switch (searchWay) {
        case 0:
            searchResult = SqSearch(&ssTable, target);
            break;
        case 1:{
            if(sortTag == 0){
                printf("\033[1;31m折半查找需要排序\n\033[0m");
                term = 1;
                goto sort;
            }
            searchResult = binSearch(&ssTable, target);
        }
            break;
        case 2:{
            if(sortTag == 0){
                printf("\033[1;31m差分查找需要排序\n\033[0m");
                term = 1;
                goto sort;
            }
            searchResult = interpolationSearch(&ssTable, target);
        }
            break;

    }
    //searchResult = binSearch(&ssTable, target, length);
    printf("----------------------\n位置：");
    if(searchResult == -1)
        printf("未找到\n");
    else
        printf("值%d在下标[%d]处\n", target, searchResult);

}

void operate_EnDecode(){
    char srcfile[] = "test.txt";    // 源文件名
    char descode[] = "CODE.txt";    // 编码压缩后的文件名
    char destxt[] = "DECODE.txt";   // 解码还原后的文件名

    charweight flist[256];          // 存储字符权制表
    int n = readFile(srcfile, flist);  // 生成字符权制表并返回字符个数

    HfmNode hfmtree[511];           // 存储Huffman树
    createHfm(n, flist, hfmtree);   // 建立Huffman树

    HfmCode hfmcode[256];           // 存储Huffman编码
    initHfmcode(n, flist, hfmcode); // 初始化Huffman编码
    createHfmcode(n, hfmtree, hfmcode);  // 生成Huffman编码

    writeHead(descode, flist, n);   // 生成压缩文件头部信息
    translate(srcfile, descode, n, hfmcode);  // 生成编码压缩文件

    // 解码还原文件
    restore(descode, destxt, n, hfmcode);

    printf("Huffman编码和解码完成。\n");

//    return 0;
}