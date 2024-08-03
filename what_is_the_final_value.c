#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int i,x,y;
    i=x=y=0;

    do
    {
        ++i;

        if(i%2 != 0)
            x = x + i++;
        y = y+i++;

    } while (i<=7);

    printf("%d %d\n", x, y); // ans: x = 1; y = 20
}
