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


int leading_zeros(unsigned int n){
    int zeros = 0;

    while(n != 1){
        zeros++;
        n = n >> 1;
    }

    return zeros;

}

float int2float(int i) {
    U aux;

    if(i == 0 ){
        aux.i = makefloat(0,0,0);
        return aux.f;
    }

    unsigned int sinal  = i < 0; 
    if(sinal) i = -i;

    unsigned int expoente = leading_zeros(i) + 127;
    unsigned int mantissa; 

    if(expoente == 23)
        mantissa = i;
    else if( expoente < 23 ){
        mantissa = i << (23 - expoente);
    }else{
        mantissa = i >> (expoente - 23);
    }

    aux.i = makefloat(sinal, expoente, mantissa);
    return aux.f;

}


int main() {

   int i;


   printf("\n******** int2float ****************\n");


   i = 0;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));


   i = 1;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));


   i = -1;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));


   i = 12345;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));


   i = -12345;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));


   i = 13631488;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));


   i = 1879048192;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));


   i = 0x7fffffff;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));


   i = -i;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));


   return 0;

}