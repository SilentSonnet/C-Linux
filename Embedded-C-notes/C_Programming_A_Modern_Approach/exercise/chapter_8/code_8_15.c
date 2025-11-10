#include <stdio.h>
#include <ctype.h>


int main(void)
{
    int length = 0, code;
    char ch, message[80];

    printf("Enter message to be encrypted: ");
    while ((ch = getchar()) != '\n')
    {
        message[length ++] = ch;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &code);

    code %= 26;

    printf("Encrypted message: ");
    for(int i = 0;i < length;i ++)
    {
        if('A' <= toupper(message[i]) && toupper(message[i]) <= 'Z')
        {
            if(toupper(message[i]) + code > 'Z')
                message[i] = message[i] - 'Z' + 'A' - 1 + code ;
            else
                message[i] += code;
        }
        printf("%c", message[i]);
    }
    printf("\n");

    return 0;
}