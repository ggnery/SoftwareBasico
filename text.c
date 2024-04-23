#include <stdio.h>

int main(){
    char a = 48;
    char b = 13;
    char c = 67;
    char d = 24;

    printf("a: 0x%.2x, b: 0x%.2x, c: 0x%.2x, d: 0x%.2x\n", a, b, c, d);

    printf("%d\n", (a ^ b) & (c | d));
    return 0;
}