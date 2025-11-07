#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int flag = 0;
    char name, ch;
    printf("Enter a first and last name: ");

    // 先跳过名字前面的空格
    while((ch = getchar()) == ' ' || ch == '\t');
    // 然后获取大写的姓名
    name = ch;

    while ((ch = getchar()) != '\n')
    {
        if (flag)
        {
            if(ch == ' ' || ch == '\t')
            {
                break;
            }
            printf("%c", ch);
        }

        // 跳过了姓氏之前的所有字母
        if ('A' <= ch && ch <= 'Z')
        {
            printf("%c", ch);
            flag = 1;
        }
    }

    printf(", %c.\n", name);

    return 0;
}