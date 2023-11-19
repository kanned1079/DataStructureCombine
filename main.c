#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"
#include "SqList.h"
#include "Stack.h"
#include "Strings.h"
#include "Queue.h"
#include "GList.h"
#include "BiTree.h"

int main(int argc, char *argv[]) {
    void operate_LinkList();
    void operate_SqList();
    void operate_Stack();
    void operate_Strings();
    void operate_Queue();
    void operate_BiTree();
    void operate_GList();
    outset:
    printf("数据结构： \n"
           " ├──顺序表 [0]\n"
           " │  └─合并两个顺序表\n"
           " ├──单链表 [1]\n"
           " │  ├─合并链表\n"
           " │  └─逆序链表\n"
           " ├──双向链表 [2]\n"
           " │  └─插入节点\n"
           " ├──棧 [3]\n"
           " │  └─进制转换\n"
           " ├──串 [4]\n"
           " │  ├─求串长度\n"
           " │  ├─串比大小\n"
           " │  ├─BF算法模式匹配\n"
           " │  └─KMP算法模式匹配\n"
           " ├──队列 [5]\n"
           " │  └─杨辉三角形\n"
           " ├──广义表 [6]\n"
           " ├──树 [7]\n"
           " │  ├─根据先序序列和中序序列生成二叉树\n"
           " │  ├─带空指针的先序序列生成一棵二叉树\n"
           " │  ├─先序遍历\n"
           " │  ├─中序遍历\n"
           " │  ├─后序遍历\n"
           " │  └─使用队列进行层次遍历\n"
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
        case 2:
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
        default:
            printf("\033[1;31mERROR\n\033[0m");
            goto restart;
            break;
    }
    printf("----------------------\n"
           "返回主菜单吗(1/0)：");
    int maintag = 0;
    scanf("%d", &maintag);
    if(maintag == 0)
        return 0;
    else
        goto outset;

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
           " └─逆序链表 [1] \n");
    int choose;
    printf("\033[1;35m选择子项目：\033[0m");
    scanf("%d", &choose);
    if(choose == 0){
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
    } else{
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
    scanf("%s", &string1);
    printf("输入串2数据：");
    //String string2;
    String string2 = "ADABBADADA";
    scanf("%s", &string2);
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
//            int target_len = myStrlen(string2);
//            int *next = (int *) malloc(sizeof (int) * target_len);
//            int next_length = getNextArray2(string2, next, target_len);
//
//            for(int i = 0; i < 20; i++){
//                printf("%d ", next[i]);
//            }
//            printf("在源字符串的第%d下标处找到了子串\n", KMP_Search(string1, string2, next));
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
    GLNode *Glist;

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
           " └─所有操作 [5]\n"
           "----------------------\n");
    choose2:
    printf("选取操作：");
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
        case 5:{
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
        }
            break;
        default:
            goto choose2;
    }
    printf("\n");

    // 释放二叉树内存
    freeBiTree(root);
}

