#include <ctype.h>

#include <stdio.h>

int string2num(char *s, int b) {

    int a = 0;

    for (; *s; s++) {
        
        if(isalpha(*s)){
            a = a * b + (*s -'a' + 10);
        }else{
            a = a * b + (*s - '0');
        }
    }

    return a;
}

int main() {

    printf("==> %d\n", string2num("a09b", 16));

    printf("==> %d\n", string2num("k09b", 36) );

    //printf("==> %d\n", string2num("1234", 10) + string2num("1",10));

    return 0;
}
