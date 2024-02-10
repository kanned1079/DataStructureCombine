#include <stdio.h>

#define SIZE 8

int board[SIZE]; // 存储皇后的位置
int solutions = 0;

// 检查是否可以在指定行放置皇后
int is_safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // 检查是否在同一列或同一对角线
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return 0;
        }
    }
    return 1;
}

// 打印棋盘
void print_board() {
    printf("Solution %d:\n", ++solutions);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i] == j) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// 递归放置皇后
void place_queens(int row) {
    if (row == SIZE) {
        // 找到一个解，打印棋盘
        print_board();
        return;
    }

    for (int col = 0; col < SIZE; col++) {
        if (is_safe(row, col)) {
            board[row] = col;
            place_queens(row + 1);
        }
    }
}

int main() {
    // 开始放置皇后
    place_queens(0);
    return 0;
}
