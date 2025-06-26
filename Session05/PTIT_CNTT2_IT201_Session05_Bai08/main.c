#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int strToInt(char *str, int n) {
    if (n==1) {
        return (str[0] - '0');
    }
    int lastDigit = str[n-1]-'0';
    return strToInt(str,n-1)*10+lastDigit;
}

bool isValidNumStr(char *str) {
    int len = strlen(str);
    if (len==0) {
        return false;
    }

    int startIndex = 0;
    if (str[0] == '-') {
        if (len == 1) {
            return false;
        }
        startIndex = 1;
    }

    for (int i = startIndex; i < len; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int main(void) {
     char inputString[50];
    printf("Nhap vao chuoi ky tu so: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = '\0';

    if (isValidNumStr(inputString)) {
        bool isNegative = false;
        char *numPart = inputString;
        int len = strlen(inputString);

        if (inputString[0] == '-') {
            isNegative = true;
            numPart = inputString+1;
            len--;
        }

        if (len>0) {
            int result = strToInt(numPart, len);
            if (isNegative) {
                result = -result;
            }
            printf("Output: %d\n", result);
        } else {
            printf("Input khong hop le");
        }

    } else {
        printf("Input khong hop le");
    }

    return 0;
}