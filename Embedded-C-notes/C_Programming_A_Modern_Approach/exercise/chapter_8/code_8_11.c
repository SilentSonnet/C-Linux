#include <stdio.h>
int main(void)
{
    int i = 0;
    char number[11], ch;
    printf("Enter phone number: ");
    while ((ch = getchar()) != '\n')
    {
        if (ch != '-')
        {
            // 直接根据字符区间来给数字赋值
            if ('A' <= ch && ch <= 'C')
                ch = '2';
            else if ('D' <= ch && ch <= 'F')
                ch = '3';
            else if ('G' <= ch && ch <= 'I')
                ch = '4';
            else if ('J' <= ch && ch <= 'L')
                ch = '5';
            else if ('M' <= ch && ch <= 'O')
                ch = '6';
            else if ('P' <= ch && ch <= 'S')
                ch = '7';
            else if ('T' <= ch && ch <= 'V')
                ch = '8';
            else if ('W' <= ch && ch <= 'Z')
                ch = '9';
            number[i++] = ch;
        }
    }

    for(int i = 0;i < 11;i ++)
    {
        printf("%c", number[i]);
        if(i == 0 || i == 3 || i == 6)
            printf("-");
    }
    printf("\n");
    
    return 0;
}