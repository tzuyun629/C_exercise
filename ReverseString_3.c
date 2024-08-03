#include <stdio.h>
#include <string.h>

void reverseString(char* str) {
    int length = (int)strlen(str);
    int j = length-1;

    for (int i = 0; i < length/2; i++) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
}

int main() {
    char str[] = "hello!emma!20240803";
    reverseString(str);
    printf("%s\n", str);
    return 0;
}