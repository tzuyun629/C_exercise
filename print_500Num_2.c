#include <stdio.h>

void printExcludedRange(int a[], int size, int b) {
    int index = 0; // 用於追蹤陣列 a[] 的索引
    int start = b * 100; // 計算範圍的起始值
    int end = start + 99; // 計算範圍的結束值
    
    for (int i = start; i <= end; i++) {
        // 如果當前數字與陣列元素相同，則跳過該數字
        while (index < size && a[index] < i) {
            index++;
        }
        if (index < size && i == a[index]) {
            continue; // 跳過 a[] 中的元素
        }
        // 輸出不在陣列中的數字
        printf("%d ", i);
    }
    printf("\n\n"); // 換行
}

int main() {
    int a[20] = {5, 18, 25, 32, 45, 67, 89, 101, 134, 167, 200, 250, 300, 350, 400, 420, 450, 470, 480, 500};
    int size = 20;
    
    // 測試不同區間的輸出
    for (int b = 0; b <= 4; b++) {
        printf("Range for b = %d: ", b);
        printExcludedRange(a, size, b);
    }
    
    return 0;
}