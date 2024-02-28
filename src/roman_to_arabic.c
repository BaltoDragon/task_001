#include <stdio.h>

#define MAX_LENGTH 16

int roman_to_arabic(char *str);

int main(void) {
    char input[MAX_LENGTH];
    int output;

    fgets(input, sizeof(input), stdin);

    output = roman_to_arabic(input);

    printf("%d", output);

    return 0;
}

int roman_to_arabic(char *str) {
    int result = 0, i = 0;
    while (str[i] != '\0') {
        if (str[i] == 'M') {
            result += 1000;
            if (str[i - 1] == 'C') result -= 100;
        }
        if (str[i] == 'D') {
            result += 500;
            if (str[i + 1] == 'C') {
                while (str[i + 1] == 'C') {
                    result += 100;
                    i++;
                }
            }
            if (str[i - 1] == 'C') result -= 100;
        }
        if (str[i] == 'C' && str[i + 1] != 'M' && str[i + 1] != 'D') {
            result += 100;
            if (str[i - 1] == 'X') result -= 10;
        }
        if (str[i] == 'L') {
            result += 50;
            if (str[i + 1] == 'X') {
                while (str[i + 1] == 'X') {
                    result += 10;
                    i++;
                }
            }
            if (str[i - 1] == 'X') result -= 10;
        }
        if (str[i] == 'X' && str[i + 1] != 'L' && str[i + 1] != 'C') {
            result += 10;
            if (str[i - 1] == 'I') result -= 1;
        }
        if (str[i] == 'V') {
            result += 5;
            if (str[i + 1] == 'I') {
                while (str[i + 1] == 'I' && str[i + 1] == '\0') {
                    result += 1;
                    i++;
                }
            }
            if (str[i - 1] == 'I') result -= 1;
        }
        if (str[i] == 'I' && str[i + 1] != 'V' && str[i + 1] != 'X') result += 1;
        i++;
    }
    return result;
}