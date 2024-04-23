#include <stdio.h>


// Atualizar as macros para 'double'
#define getsig(i) ((i)>>63 & 1)

#define getexp(i) ((i)>>52 & 0x7ff)

#define getfrac(i) ((i) & 0xfffffffffffff)

#define makefloat(s,e,f) ((s & 1)<<63 | (((e) & 0x7ff) << 52) | ((f) & 0xfffffffffffff))

// Definir a union para 'double'
typedef union {
    double d;
    unsigned long l;
} U ;

double maxdouble(double a, double b)
{
    U auxA = {.d = a};
    U auxB = {.d = b};

    unsigned long sigA = getsig(auxA.l);
    unsigned long expA = getexp(auxA.l);
    unsigned long fracA = getfrac(auxA.l);

    unsigned long sigB = getsig(auxB.l);
    unsigned long expB = getexp(auxB.l);
    unsigned long fracB = getfrac(auxB.l);
    
    // printf("%lX, %lX\n", auxA.l, auxB.l);
    // printf("sigA: %lX, expA: %lX, fracA: %lX\n", sigA, expA, fracA);
    // printf("sigB: %lX, expB: %lX, fracB: %lX\n", sigB, expB, fracB);

    if(sigA == sigB){
        
        if(expA == expB)
            return fracA > fracB ? a: b;
        else
            return expA > expB ? a: b;
    }else
        return sigA > sigB ? b : a;
    
    
}


int main()

{

   double a,b;


   a = 1.0;

   b = 2.0;

   printf("maior de %f %f = %f\n", a, b, maxdouble(a, b));


   a = -1.0;

   b = -2.0;

   printf("maior de %f %f = %f\n", a, b, maxdouble(a, b));


   a = 1.0;

   b = -2.0;

   printf("maior de %f %f = %f\n", a, b, maxdouble(a, b));


   a = 1.751;

   b = 1.75;

   printf("maior de %f %f = %f\n", a, b, maxdouble(a, b));


   a = -1.5;

   b = -1.75;

   printf("maior de %f %f = %f\n", a, b, maxdouble(a, b));


   a = -1.5;

   b = -2.5;

   printf("maior de %f %f = %f\n", a, b, maxdouble(a, b));


   a = 1.5;

   b = -1.75;

   printf("maior de %f %f = %f\n", a, b, maxdouble(a, b));


   return 0;

}