#include <stdio.h>

void dump(void *p, size_t n){
    unsigned char* aux =(unsigned char*) p;
    printf("Tamanho: %ld\n", n);
    for(int i = 0; i< n; i++){
        printf("%p :0x%02X\n", aux, *aux);
        aux++;
    }
    printf("======================\n" );
}

struct X1 {

   char c1;

   int i;

   char c2;

};

struct X2 {

   long l;

   char c;

};

struct X3 {

   int i;

   char c1;

   char c2;

};

struct X4 {

   struct X2 x;

   char c;

};

struct X5 {

   short s1;

   int i;

   int c[2][3];

   short s2;

};


union U1 {

   int i;

   char c[5];

};

union U2 {

   short s;

   char c[5];

};

union U3 {

   struct X3 x;

   union U2 u;

};

int main(){
    struct X1 x1 = {.c1 = 0xAA, .i = 0xBBBBBBBB, .c2 = 0xCC};
    struct X2 x2 = {.l = 0xAAAAAAAAAAAAAAAA, .c = 0xBB }; 
    struct X3 x3 = {.i = 0xAAAAAAAA, .c1 = 0xBB, .c2 = 0xCC};
    struct X4 x4 = {.x = x2, .c = 0xCC};
    struct X5 x5 = {.s1 = 0xAAAA, .i = 0xBBBBBBBB, .s2 = 0xDDDD};

    union U1 u1 = {.c = 0xAA, .c[1] = 0xAA, .c[4] = 0xAA};
    union U2 u2;
    union U3 u3;

    dump(&x1, sizeof(x1));
    dump(&x2, sizeof(x2));
    dump(&x3, sizeof(x3));
    dump(&x4, sizeof(x4));
    dump(&x5, sizeof(x5));

    dump(&u1, sizeof(u1));
    dump(&u2, sizeof(u2));
    dump(&u3, sizeof(u3));


    return 0;
}