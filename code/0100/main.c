#include <stdio.h>

int main()
{
    long long b = 15, t = 21;

    long long limit = 1000000000000;

    while (t <= limit)
    {
        long long b_next = 3 * b + 2 * t - 2;
        long long t_next = 4 * b + 3 * t - 3;

        b = b_next;
        t = t_next;
    }

    printf("%lld", b);
}