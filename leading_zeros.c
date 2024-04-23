#include <stdio.h>

int leading_zeros(unsigned short n){
    int zeros = 0;

    for(int i = 0; i < 8*sizeof(unsigned short); i++ ){ 
        
        if(n & 1)
            zeros = 0;
        else
            zeros++;
        
        n = n >> 1;
    }

    return zeros;

}

int main(){
    
    printf("%d\n", leading_zeros(0xC2A4));

    return 0;
}




