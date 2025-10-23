#include <stdio.h>

int main(void)
{
    float stock, number;
    float commission, competitor_comission, value;

    printf("Enter value of trade: ");
    //scanf("%f", &value);
    scanf("%f %f", &stock, &number);
    value = stock * number;

    if (value < 2500.00f)
        commission = 30.00f + .017f * value;
    else if (value < 6250.00f)
        commission = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        commission = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission = 155.00f + .0011f * value;
    else
        commission = 255.00f + .0009f * value;

    if (commission < 39.00f)
        commission = 39.00f;

    if(stock < 2000)
        competitor_comission = stock * 0.03 + 33;
    else 
        competitor_comission = stock * 0.02 + 33;
    

    printf("Commission: $%.2f\t", commission);
    printf("Competitor: $%.2f\n", competitor_comission);

    return 0;
}