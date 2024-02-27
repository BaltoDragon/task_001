#include <stdio.h>

#define MAX_LENGTH 15

int main(void) {
    char str[MAX_LENGTH];
    if(scanf("%s", str) != 1) printf("Puck you, Verter!");

    printf("%s", str);
    return 0;
}