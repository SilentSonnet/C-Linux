#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    double temperature_readings[30][24], sum = 0.0;

    srand(time(NULL));

    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            temperature_readings[i][j] = (rand() % 51) - 10;
            sum += temperature_readings[i][j];
        }
    }

    printf("Sum of all temperature readings: %.2f°C\n", sum / (30 * 24));

    return 0;
}
