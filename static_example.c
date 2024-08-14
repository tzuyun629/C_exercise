#include <stdio.h>

// static 局部變數示例
void count() {
    static int counter = 0; // 靜態變數
    counter++;
    printf("Counter: %d\n", counter);
}

// static 全域變數示例
static int globalStaticVar = 10; // 僅本檔案可見

int main() {
    for (int i = 0; i < 3; i++) {
        count();
    }
    return 0;
}