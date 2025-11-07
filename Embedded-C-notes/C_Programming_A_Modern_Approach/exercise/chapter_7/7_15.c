#include<stdio.h>
#include<stdint.h>
typedef int8_t Int8;
typedef int16_t Int16;
typedef int32_t Int32;
int main(void)
{
    Int8 a = -128;  
    Int16 b = 32767; 
    Int32 c = 2147483647; 


    printf("Int8: %d\n", a);
    printf("Int16: %d\n", b);
    printf("Int32: %d\n", c);

    return 0;
}