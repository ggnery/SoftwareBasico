#include <stdio.h>

#include <stdio.h>

#include <math.h>

#define getsig(i)        ((i)>>31 & 1)

#define getexp(i)        ((i)>>23 & 0xff)

#define getfrac(i)       ((i) & 0x7fffff)

#define makefloat(s,e,f) ( (((s) & 1) << 31) | (((e) & 0xff) << 23) | ((f) & 0x7fffff) )


typedef union {

  float f;

  unsigned int i;

} U;


float float2(float value){
    U aux = {.f = value};

    unsigned int sinal = getsig(aux.i);
    unsigned int expoent = getexp(aux.i) + 1;
    unsigned int frac = getfrac(aux.i);  

    aux.i = makefloat(sinal, expoent, frac);

    return aux.f;

}


int main(){
    float f = 0.13;
    
    printf("%f", float2(f));


    return 0;
}