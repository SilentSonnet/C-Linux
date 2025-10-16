#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    float amount = 0.0f, tax_rate = 1.05f;

	printf("Enter an amount:");
	scanf("%f", &amount);

    printf("With tax added:%.2f$\n", amount * tax_rate);

    return 0;
}

