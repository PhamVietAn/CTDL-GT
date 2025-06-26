#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool Palindrome(char str[], int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    Palindrome(str, (start + 1), (end - 1));
}

int main(void) {
    char string[20];

    printf("Enter a string: ");
    fgets(string, 20, stdin);
    string[strcspn(string, "\n")] = 0;

    int length = strlen(string);

    if (Palindrome(string, 0, length - 1)) {
        printf("La chuoi doi xung\n");
    } else {
        printf("khong phai chuoi doi xứng\n");
    }

    return 0;
}