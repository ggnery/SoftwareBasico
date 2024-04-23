
#include <stdio.h>

unsigned int convertB2L(unsigned int x) {
    unsigned int temp1, temp2, temp3, temp4;
    
    temp1 = x & 0x000000FF;
    temp2 = x & 0x0000FF00;
    temp3 = x & 0x00FF0000;
    temp4 = x & 0xFF000000;

    return (temp1 << 24) | (temp2 << 8) | (temp3 >> 8) | (temp4 >> 24);

}


int main() {

  unsigned int b = 0x12AB34CD;

  unsigned int l = convertB2L(b);


  printf("b = 0x%08X\n", b);

  printf("l = 0x%08X\n", l);


  return 0;

}