#include <stdio.h>
#include <stdlib.h>

#define REDUCE 1
#define ADD 2
#define SUBTRACT 3
#define MULTIPLY 4
#define DIVIDE 5

struct fraction
{
    int numerator, denominator;
};

int cal_gcd(int a, int b)
{
    int temp;

    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

struct fraction reduce_fraction(struct fraction f)
{
    int gcd;
    gcd = cal_gcd(f.numerator, f.denominator);

    f.numerator /= gcd;
    f.denominator /= gcd;

    if (f.denominator < 0)
    {
        f.denominator = -f.denominator;
        f.numerator = -f.numerator;
    }

    return f;
}

struct fraction add_fraction(struct fraction f1, struct fraction f2)
{
    struct fraction f;
    f.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f.denominator = f1.denominator * f2.denominator;

    return reduce_fraction(f);
}

struct fraction subtract_fraction(struct fraction f1, struct fraction f2)
{
    struct fraction f;
    f.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    f.denominator = f1.denominator * f2.denominator;

    return reduce_fraction(f);
}

struct fraction multiply_fraction(struct fraction f1, struct fraction f2)
{
    struct fraction f;
    f.numerator = f1.numerator * f2.numerator;
    f.denominator = f1.denominator * f2.denominator;

    return reduce_fraction(f);
}

struct fraction divide_fraction(struct fraction f1, struct fraction f2)
{
    struct fraction f;
    f.numerator = f1.numerator * f2.denominator;
    f.denominator = f1.denominator * f2.numerator;

    return reduce_fraction(f);
}

int main(void)
{
    struct fraction f, f1, f2;

    for (;;)
    {
        int op;
        printf("Enter the fraction : (a/b)");
        scanf("%d/%d", &f1.numerator, &f1.denominator);

        if (f1.numerator == 0 && f1.denominator == 0)
        {
            printf("Exiting program...\n");
            return 0;
        }

        if (f1.denominator == 0)
        {
            printf("Error: denominator cannot be zero.\n");
            printf("Invalid input. Please try again.\n");
            continue;
        }

        printf("Choose an operation:\n");
        printf("1. Reduce a fraction\n");
        printf("2. Add two fractions\n");
        printf("3. Subtract two fractions\n");
        printf("4. Multiply two fractions\n");
        printf("5. Divide two fractions\n");
        printf("Enter your choice: ");

        scanf("%d", &op);

        if (op > 1)
        {
            printf("Enter the second fraction (c/d): ");
            scanf("%d/%d", &f2.numerator, &f2.denominator);

            if (f2.denominator == 0)
            {
                printf("Error: denominator cannot be zero.\n");
                printf("Invalid input. Please try again.\n");
                continue;
            }
        }

        switch (op)
        {
        case REDUCE:
            f = reduce_fraction(f1);
            break;
        case ADD:
            f = add_fraction(f1, f2);
            break;
        case SUBTRACT:
            f = subtract_fraction(f1, f2);
            break;
        case MULTIPLY:
            f = multiply_fraction(f1, f2);
            break;
        case DIVIDE:
            if (f2.numerator == 0)
            {
                printf("Error: cannot divide by a fraction whose numerator is 0.\n");
                continue;
            }
            f = divide_fraction(f1, f2);
            break;
        default:
            printf("Invalid choice.\n");
            continue;
        }
        printf("The fraction in simplest form is: %d/%d\n", f.numerator, f.denominator);
    }
    return 0;
}