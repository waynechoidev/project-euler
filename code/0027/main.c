#include <stdio.h>
#include <math.h>
#include <stdbool.h>

static bool is_prime(long long x)
{
    if (x < 2)
        return false;
    if (x % 2 == 0)
        return x == 2;
    for (long long i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main(void)
{
    int bprimes[200], bcnt = 0;
    for (int b = 2; b <= 1000; ++b)
    {
        if (is_prime(b))
            bprimes[bcnt++] = b;
    }

    int best_a = 0, best_b = 0, best_len = -1;

    for (int a = -999; a <= 999; ++a)
    {
        for (int bi = 0; bi < bcnt; ++bi)
        {
            int b = bprimes[bi];

            int n = 0;
            while (1)
            {
                long long val = (long long)n * n + (long long)a * n + b;
                if (!is_prime(val))
                    break;
                n++;
            }
            if (n > best_len)
            {
                best_len = n;
                best_a = a;
                best_b = b;
            }
        }
    }

    long long product = (long long)best_a * best_b;
    printf("%lld\n", product);
    return 0;
}
