#include <stdio.h>
#include <string.h>
int main()
{
    char str1[64], str2[64];
    gets(str1);
    gets(str2);
    const unsigned long len1 = strlen(str1), len2 = strlen(str2);

    _Bool flag = 0;
    for(int i = 0;i < len1;++i)
    {
        for(int j = 0;j < len2;++j)
        {
            if(str1[i + j] != str2[j])
            {
                flag = 1;
                break;
            }
        }
    }
    puts(flag ? "include" : "not include");

    return 0;
}
