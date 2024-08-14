#include <stdio.h>

inline int power2(int num) {
    return num * num;
}

inline int power(int n,int p) {
    int r = 1;
    for(int i = 0; i < p; i++) {
            r *= n;
    }

    return r;
}

int power2(int);
int power(int, int);

int main(void) {
    int num = 0;
    int p = 0;

    printf("Input value：");
    scanf("%d", &num);

    printf("輸入平方：");
    scanf("%d", &p);

    printf("%d 平方：%d\n", num, power2(num));
    printf("%d 的 %d 次方 %d\n", num, p, power(num, p));

    return 0;
}