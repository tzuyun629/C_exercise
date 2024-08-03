#include <stdio.h>
#include <string.h>

// Function to reverse words in a string
void reverseWords(char *str) {
    int len = (int)strlen(str);  // Get the length of the string
    char temp;              // Temporary variable for swapping
    int start = 0;          // Start index for a word
    int end = 0;            // End index for a word

    // First, reverse the entire string
    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    // Then, reverse each word in the reversed string
    while (end <= len) {
        // Look for spaces or end of the string to find words
        if (str[end] == ' ' || str[end] == '\0') {
            // Reverse the found word
            for (int i = start, j = end - 1; i < j; i++, j--) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
            // Move to the next word
            start = end + 1;
        }
        end++;
    }
}

int main() {
    char str[] = "1234 5678";
    printf("Original: %s\n", str);
    reverseWords(str);
    printf("Reversed: %s\n", str);
    return 0;
}
