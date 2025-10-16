#include<stdio.h>
int main(void)
{
    int prefix, group, code, number, digit;
    printf("Enter ISBN:");
    scanf("%d-%d-%d-%d-%d", &prefix, &group, &code, &number, &digit);
    printf("GS1 prefix: %d\n", prefix);
    printf("Group identifier: %d\n", group);
    printf("Publisher code: %d\n", code);
    printf("Item number: %d\n", number);
    printf("Check digit: %d\n", digit);

    return 0;
}

