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

    printf("Encrypted message: ");
    for(int i = 0;i < length;i ++)
    {
        if('A' <= message[i] && message[i] <= 'Z')
            message[i] = ((message[i] - 'A') + code) % 26 + 'A';
        else if('a' <= message[i] && message[i] <= 'z')
            message[i] = ((message[i] - 'a') + code) % 26 + 'a';
        printf("%c", message[i]);
    }
    printf("\n");

    return 0;
}