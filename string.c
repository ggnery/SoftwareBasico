#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char * string = (char *) malloc(6*sizeof(char));
    strcpy(string, "teste\0");
   
    printf("%s\n", string);
    
    string[2] = 0x00;
    
    printf("%s\n", string);

   //  wwwwwW oi todo 
    free(string);
    return 0;
}