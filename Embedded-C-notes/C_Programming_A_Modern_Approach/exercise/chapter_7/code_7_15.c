#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    /* short */
    {
        short v = 1;
        int n = 1;
        while (v <= SHRT_MAX / (n + 1))
        {
            n++;
            v = (short)(v * n);
        }
        printf("short  : 最大 n = %d,  n! = %hd,  首次溢出阶乘 = %d!（超过 SHRT_MAX=%d）\n",
               n, v, n + 1, SHRT_MAX);
    }

    /* int */
    {
        int v = 1;
        int n = 1;
        while (v <= INT_MAX / (n + 1))
        {
            n++;
            v = v * n;
        }
        printf("int    : 最大 n = %d,  n! = %d,   首次溢出阶乘 = %d!（超过 INT_MAX=%d）\n",
               n, v, n + 1, INT_MAX);
    }

    /* long */
    {
        long v = 1;
        int n = 1;
        while (v <= LONG_MAX / (n + 1))
        {
            n++;
            v = v * (long)n;
        }
        printf("long   : 最大 n = %d,  n! = %ld,  首次溢出阶乘 = %d!（超过 LONG_MAX=%ld）\n",
               n, v, n + 1, LONG_MAX);
    }

    /* long long */
    {
        long long v = 1;
        int n = 1;
        while (v <= LLONG_MAX / (n + 1))
        {
            n++;
            v = v * (long long)n;
        }
        printf("long long: 最大 n = %d,  n! = %lld, 首次溢出阶乘 = %d!（超过 LLONG_MAX=%lld）\n",
               n, v, n + 1, LLONG_MAX);
    }

    /* float（近似） */
    {
        float v = 1.0f;
        int n = 1;
        while (v <= FLT_MAX / (float)(n + 1))
        {
            n++;
            v = v * (float)n;
        }
        printf("float  : 最大 n = %d,  n! ≈ %.0e, 首次溢出阶乘 = %d!（超过 FLT_MAX=%.0e）\n",
               n, (double)v, n + 1, (double)FLT_MAX);
    }

    /* double（近似） */
    {
        double v = 1.0;
        int n = 1;
        while (v <= DBL_MAX / (double)(n + 1))
        {
            n++;
            v = v * (double)n;
        }
        printf("double : 最大 n = %d,  n! ≈ %.0e, 首次溢出阶乘 = %d!（超过 DBL_MAX=%.0e）\n",
               n, v, n + 1, DBL_MAX);
    }

    /* long double（近似，取决于平台位宽） */
    {
        long double v = 1.0L;
        int n = 1;
        while (v <= LDBL_MAX / (long double)(n + 1))
        {
            n++;
            v = v * (long double)n;
        }
        /* 使用科学计数法，减少巨大的长数字输出 */
        printf("long double: 最大 n = %d,  n! ≈ %.0Le, 首次溢出阶乘 = %d!（超过 LDBL_MAX=%.0Le）\n",
               n, v, n + 1, LDBL_MAX);
    }

    return 0;
}
