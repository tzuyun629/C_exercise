#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int a[5] = {1,2,3,4,5};
    int *p = a;

    *(p++)+=123;
    *(++p)+=123;

    for (int i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]); // ans: {124, 2, 126, 4, 5}
    }
}
