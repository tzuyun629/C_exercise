#include <stdio.h>
#include <string.h>

// 字串反轉：AB CD => DC BA
int reverse(char *str){
        int i, j;
        char temp;

        j=(int)strlen(str) - 1;
        for(i=0; i<j; i++){
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
                j--;
        }
        return 0;
}

int main(){
        char myString[] = "I am Emma\n\n";
        printf("before: %s\n", myString);
        reverse(myString);
        printf("after: %s\n", myString);

        return 0;
}