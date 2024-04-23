#include <stdio.h>

unsigned char rotate_left(unsigned char x, int n){
    for (int i =0 ; i<n; i++){
        unsigned char aux = x & 0x80;
        aux >>= 7;

        x <<= 1;
        x = x | aux;

    }

    return x;
}

unsigned char easy_rotate_left(unsigned char x, int n){

    return (x >> (8-n) | (x << n));
}

int main(){
    printf("%x\n", rotate_left(0x61, 8));
    printf("%x\n", rotate_left(0x61, 2));
    printf("%x\n", rotate_left(0x61, 7));


    return 0;
}