#include <stdio.h>
#include <ctype.h>

void encrypt(char *message, int shift);

int main(void)
{
    int length = 0, shift;
    char ch, message[80];

    printf("Enter message to be encrypted: ");
    while ((ch = getchar()) != '\n')
        message[length ++] = ch;
    message[length] = '\0';

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    encrypt(message, shift % 26);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int shift)
{
    char *p = message;
    while(*p)
    {
        if(isupper(*p))
            *p = ((*p - 'A') + shift) % 26 + 'A';
        else if(islower(*p))
            *p = ((*p - 'a') + shift) % 26 + 'a';
        p ++;
    }
}