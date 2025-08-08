#include <stdio.h>

int main()
{
    long long n = 600851475143;
    long long largest = 0;

    for (long long i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            largest = i;
            n /= i;
        }
    }

    if (n > 1)
        largest = n;

    printf("%lld\n", largest);
    return 0;
}