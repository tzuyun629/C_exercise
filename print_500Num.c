#include <stdio.h>

void function(int *a, int size) {
    int index = 0;

    for (int i = 0; i <= 500; i++) {
        // if (i == a[i])
        if (index < size && i == a[index])
            index++;
        else
            printf("%d\n", i);
    }

}

int main() {

    int a[20] = {0};
    for (int i = 1; i < 21; i++)
        a[i] = i;

    printf("Print Numbers:\n");
    function(a, 20);
}