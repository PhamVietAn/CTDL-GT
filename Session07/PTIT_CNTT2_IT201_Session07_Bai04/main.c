#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sortChar(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main(void) {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("mang truoc khi sap xep: %s", str);

    sortChar(str);
    printf("\nmang sau khi sap xep: %s", str);


    return 0;
}