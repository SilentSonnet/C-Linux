#include<stdio.h>
#include<ctype.h>

int main(void)
{
    char message[999], ch;
    int i = 0;

    printf("Enter message: ");
    while((ch = getchar()) != '\n')
    {
        ch = toupper(ch);

        // （A→4、B→8、E→3、I→1、O→0、S→5）
        if(ch == 'A')
            ch = '4';
        else if(ch == 'B')
            ch = '8';
        else if(ch == 'E')
            ch = '3';
        else if(ch == 'I')
            ch = '1';
        else if(ch == 'O')
            ch = '0';
        else if(ch == 'S')
            ch = '5';
        message[i++] = ch;
    }

    printf("In B1FF-speak: ");
    for(int j = 0;j <= i;j ++)
        putchar(message[j]);
    printf("!!!!!!!!!!\n");

    return 0;
}