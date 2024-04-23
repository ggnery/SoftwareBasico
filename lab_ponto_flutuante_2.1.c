#include <stdio.h>

#include <math.h>

#include <limits.h>

#define getsig(x) ((x) >> 31 & 1)

#define getexp(x) ((x) >> 23 & 0xff)

#define getfrac(x) ((x)&0x7fffff)

#define makefloat(s, e, f) ((s & 1) << 31 | (((e)&0xff) << 23) | ((f)&0x7fffff))

typedef union {

    float f;

    unsigned int i;

} U;

int float2int(float value) {
    U aux = {.f = value};
    unsigned int s = getsig(aux.i);
    unsigned int e =  getexp(aux.i);
    unsigned int f = getfrac(aux.i);

    int E = (int)e - 127;

    if(e == 0 && f == 0) return 0;
    
    int ans = 0;
    if ( E < 0 ) return 0;
    else if (E < 23){
        ans = f | (1 << 23);
        ans = ans >> (23 - E);
    }
    

    if(s == 1)  ans = -ans;
    
    return ans;
}

int main() {

    float f;

    printf("\n******** float2int ****************\n");

    f = 0.0;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = -0.0;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = 0.5;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = -0.5;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = 0.125;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = -0.125;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = 1.0;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = -1.0;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = 1.5;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = -1.5;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = 2.5;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = -2.5;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = 5.4;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = -5.4;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = 12345.0;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = -12345.0;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = 14690064.0;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = -14690064.0;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = 167788544.0;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = -167788544.0;

    printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

    f = (float)pow(2, 31);

    printf(" %+10.4f (2^31) = overflow -> %d %d\n", f, (int)f, float2int(f));

    f = -f;

    printf(" %+10.4f (-2^31) -> %d %d\n", f, (int)f, float2int(f));

    f = -((float)pow(2, 32));

    printf(" %+10.4f (-2^32 = overflow) -> %d %d\n", f, (int)f, float2int(f));

    return 0;
}