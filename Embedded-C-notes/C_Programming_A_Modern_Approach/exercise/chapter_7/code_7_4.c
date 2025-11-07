#include<stdio.h>

int main(void)
{
    char n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;
    printf("Enter phone number: ");
    scanf("%c-%c%c%c-%c%c%c-%c%c%c%c", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11);

    // 直接根据字符区间来给数字赋值
    if ('A' <= n1 && n1 <= 'C') n1 = '2';
    else if ('D' <= n1 && n1 <= 'F') n1 = '3';
    else if ('G' <= n1 && n1 <= 'I') n1 = '4';
    else if ('J' <= n1 && n1 <= 'L') n1 = '5';
    else if ('M' <= n1 && n1 <= 'O') n1 = '6';
    else if ('P' <= n1 && n1 <= 'S') n1 = '7';
    else if ('T' <= n1 && n1 <= 'V') n1 = '8';
    else if ('W' <= n1 && n1 <= 'Z') n1 = '9';

    if ('A' <= n2 && n2 <= 'C') n2 = '2';
    else if ('D' <= n2 && n2 <= 'F') n2 = '3';
    else if ('G' <= n2 && n2 <= 'I') n2 = '4';
    else if ('J' <= n2 && n2 <= 'L') n2 = '5';
    else if ('M' <= n2 && n2 <= 'O') n2 = '6';
    else if ('P' <= n2 && n2 <= 'S') n2 = '7';
    else if ('T' <= n2 && n2 <= 'V') n2 = '8';
    else if ('W' <= n2 && n2 <= 'Z') n2 = '9';

    if ('A' <= n3 && n3 <= 'C') n3 = '2';
    else if ('D' <= n3 && n3 <= 'F') n3 = '3';
    else if ('G' <= n3 && n3 <= 'I') n3 = '4';
    else if ('J' <= n3 && n3 <= 'L') n3 = '5';
    else if ('M' <= n3 && n3 <= 'O') n3 = '6';
    else if ('P' <= n3 && n3 <= 'S') n3 = '7';
    else if ('T' <= n3 && n3 <= 'V') n3 = '8';
    else if ('W' <= n3 && n3 <= 'Z') n3 = '9';

    if ('A' <= n4 && n4 <= 'C') n4 = '2';
    else if ('D' <= n4 && n4 <= 'F') n4 = '3';
    else if ('G' <= n4 && n4 <= 'I') n4 = '4';
    else if ('J' <= n4 && n4 <= 'L') n4 = '5';
    else if ('M' <= n4 && n4 <= 'O') n4 = '6';
    else if ('P' <= n4 && n4 <= 'S') n4 = '7';
    else if ('T' <= n4 && n4 <= 'V') n4 = '8';
    else if ('W' <= n4 && n4 <= 'Z') n4 = '9';

    if ('A' <= n5 && n5 <= 'C') n5 = '2';
    else if ('D' <= n5 && n5 <= 'F') n5 = '3';
    else if ('G' <= n5 && n5 <= 'I') n5 = '4';
    else if ('J' <= n5 && n5 <= 'L') n5 = '5';
    else if ('M' <= n5 && n5 <= 'O') n5 = '6';
    else if ('P' <= n5 && n5 <= 'S') n5 = '7';
    else if ('T' <= n5 && n5 <= 'V') n5 = '8';
    else if ('W' <= n5 && n5 <= 'Z') n5 = '9';

    if ('A' <= n6 && n6 <= 'C') n6 = '2';
    else if ('D' <= n6 && n6 <= 'F') n6 = '3';
    else if ('G' <= n6 && n6 <= 'I') n6 = '4';
    else if ('J' <= n6 && n6 <= 'L') n6 = '5';
    else if ('M' <= n6 && n6 <= 'O') n6 = '6';
    else if ('P' <= n6 && n6 <= 'S') n6 = '7';
    else if ('T' <= n6 && n6 <= 'V') n6 = '8';
    else if ('W' <= n6 && n6 <= 'Z') n6 = '9';

    if ('A' <= n7 && n7 <= 'C') n7 = '2';
    else if ('D' <= n7 && n7 <= 'F') n7 = '3';
    else if ('G' <= n7 && n7 <= 'I') n7 = '4';
    else if ('J' <= n7 && n7 <= 'L') n7 = '5';
    else if ('M' <= n7 && n7 <= 'O') n7 = '6';
    else if ('P' <= n7 && n7 <= 'S') n7 = '7';
    else if ('T' <= n7 && n7 <= 'V') n7 = '8';
    else if ('W' <= n7 && n7 <= 'Z') n7 = '9';

    if ('A' <= n8 && n8 <= 'C') n8 = '2';
    else if ('D' <= n8 && n8 <= 'F') n8 = '3';
    else if ('G' <= n8 && n8 <= 'I') n8 = '4';
    else if ('J' <= n8 && n8 <= 'L') n8 = '5';
    else if ('M' <= n8 && n8 <= 'O') n8 = '6';
    else if ('P' <= n8 && n8 <= 'S') n8 = '7';
    else if ('T' <= n8 && n8 <= 'V') n8 = '8';
    else if ('W' <= n8 && n8 <= 'Z') n8 = '9';

    if ('A' <= n9 && n9 <= 'C') n9 = '2';
    else if ('D' <= n9 && n9 <= 'F') n9 = '3';
    else if ('G' <= n9 && n9 <= 'I') n9 = '4';
    else if ('J' <= n9 && n9 <= 'L') n9 = '5';
    else if ('M' <= n9 && n9 <= 'O') n9 = '6';
    else if ('P' <= n9 && n9 <= 'S') n9 = '7';
    else if ('T' <= n9 && n9 <= 'V') n9 = '8';
    else if ('W' <= n9 && n9 <= 'Z') n9 = '9';

    if ('A' <= n10 && n10 <= 'C') n10 = '2';
    else if ('D' <= n10 && n10 <= 'F') n10 = '3';
    else if ('G' <= n10 && n10 <= 'I') n10 = '4';
    else if ('J' <= n10 && n10 <= 'L') n10 = '5';
    else if ('M' <= n10 && n10 <= 'O') n10 = '6';
    else if ('P' <= n10 && n10 <= 'S') n10 = '7';
    else if ('T' <= n10 && n10 <= 'V') n10 = '8';
    else if ('W' <= n10 && n10 <= 'Z') n10 = '9';

    if ('A' <= n11 && n11 <= 'C') n11 = '2';
    else if ('D' <= n11 && n11 <= 'F') n11 = '3';
    else if ('G' <= n11 && n11 <= 'I') n11 = '4';
    else if ('J' <= n11 && n11 <= 'L') n11 = '5';
    else if ('M' <= n11 && n11 <= 'O') n11 = '6';
    else if ('P' <= n11 && n11 <= 'S') n11 = '7';
    else if ('T' <= n11 && n11 <= 'V') n11 = '8';
    else if ('W' <= n11 && n11 <= 'Z') n11 = '9';


    printf("The numeric phone number is: %c-%c%c%c-%c%c%c-%c%c%c%c\n", 
            n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);

    return 0;
}
