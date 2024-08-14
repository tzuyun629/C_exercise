#include <stdio.h>

struct ListStruct {
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
};

struct ListStruct ListArray[1000];
#define NULL 0xFFFF
unsigned int ListHead = 0;

void findAndPrint(unsigned int DATA_A, unsigned int DATA_B) {
    int found = 0; // 用於追蹤是否找到匹配項目

    for (int i = 0; i < 1000; i++) {
        // 計算 Entry1 的值
        unsigned int entry1Value = (ListArray[i].DataH << 16) + ListArray[i].DataL;

        // 印出當前迴圈中 ListArray 的資料
        printf("索引 %d:\n", i);
        printf("  DataH: %u\n", ListArray[i].DataH);
        printf("  DataL: %u\n", ListArray[i].DataL);
        printf("  NextPtr: %u\n", ListArray[i].NextPtr);

        // 檢查是否有符合條件一和條件二的項目
        if (ListArray[i].DataH == DATA_A && ListArray[i].DataL == DATA_B) {
            unsigned int nextIndex = ListArray[i].NextPtr;
            if (nextIndex != NULL && nextIndex < 1000) {
                unsigned int entry2Value = (ListArray[nextIndex].DataH << 16) + ListArray[nextIndex].DataL;
                if (entry2Value > entry1Value) {
                    printf("符合條件的項目於索引 %d:\n", i);
                    printf("  DataH: %u\n", ListArray[i].DataH);
                    printf("  DataL: %u\n", ListArray[i].DataL);
                    printf("  NextPtr: %u\n", ListArray[i].NextPtr);
                    printf("  下一個索引 %d 的值: %u\n", nextIndex, entry2Value);
                    found = 1;
                    break; // 找到匹配項目後結束迴圈
                }
            }
        }
    }

    if (!found) {
        printf("沒有找到符合的項目。\n");
    }
}

int main() {
    // 初始化 ListArray 中的部分資料以供測試
    ListArray[0].DataH = 0x1234;
    ListArray[0].DataL = 0x5678;
    ListArray[0].NextPtr = 1;

    ListArray[1].DataH = 0x9ABC;
    ListArray[1].DataL = 0xDEF0;
    ListArray[1].NextPtr = NULL;

    // 測試函數，應該找到的範例
    findAndPrint(0x1234, 0x5678);

    // 測試函數，應該找不到的範例
    findAndPrint(0x1111, 0x2222);

    return 0;
}
