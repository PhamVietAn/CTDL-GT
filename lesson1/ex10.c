#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char str[]) {
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

int isAnagram(char str1[], char str2[]) {
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }
    char temp1[100], temp2[100];
    strcpy(temp1, str1);
    strcpy(temp2, str2);
    sort(temp1);
    sort(temp2);
    return strcmp(temp1, temp2) == 0;
}

/*
 * thời gian: O(n^2)
 * không gian: O(n)
 */