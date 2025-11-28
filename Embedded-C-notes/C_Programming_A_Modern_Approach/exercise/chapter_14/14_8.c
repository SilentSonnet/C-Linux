#include<stdio.h>

#define STR(x) #x
#define STR2(x) STR(x)

#define LINE_FILE "Line " STR2(__LINE__) " of file " __FILE__

#line 9 "foo.c"

const char *str = LINE_FILE;

int main(void)
{
    printf("%s\n", str);
    
    return 0;
}