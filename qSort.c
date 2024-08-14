#include <stdio.h>

// 交換兩個整數指針指向的值
void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// 快速排序函數
void QuickSort(int *array, int left, int right) {
    if (left < right) {
        int i = left - 1;
        int j = right + 1;
        int mid = array[(left + right) / 2]; // 使用中間值作為樞軸

        while (1) {
            // 遞減排序
            while (array[++i] > mid); // 這裡是大於號，保證遞減
            while (array[--j] < mid); // 這裡是小於號，保證遞減

            if (i >= j)
                break;

            // 交換元素
            swap(&array[i], &array[j]);
        }

        // 遞迴調用快速排序
        QuickSort(array, left, i - 1);
        QuickSort(array, j + 1, right);
    }
}

int main() {
    int array[] = {34, 7, 23, 32, 5, 62, 32, 14};
    int n = sizeof(array) / sizeof(array[0]);

    printf("原始陣列: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // 呼叫快速排序
    QuickSort(array, 0, n - 1);

    printf("排序後的陣列: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
