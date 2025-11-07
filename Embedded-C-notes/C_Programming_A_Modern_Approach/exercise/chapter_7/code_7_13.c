#include <stdio.h>
int main(void)
{
    char ch;
    int w_num = 1, c_num = 0;
    double ave;
    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n')
    {
        if (ch == ' ')
            w_num++;
        else if (ch != ' ' && ch != '.')
            c_num++;
    }
    printf("%d,%d",c_num, w_num);
    printf("Average word length: %.1f\n", c_num * 1.0f / w_num);
    
    return 0;
}