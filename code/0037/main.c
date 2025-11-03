#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    if (n < 2)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0)
        return 0;

    int limit = (int)sqrt(n);
    for (int i = 3; i <= limit; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int len(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
}

int isTruncatablePrime(int n)
{
    if (!isPrime(n))
        return 0;

    int d = (int)pow(10, len(n) - 1);
    int k = n % d;
    while (d > 1)
    {
        if (!isPrime(k))
            return 0;
        d /= 10;
        k %= d;
    }

    k = n / 10;
    while (k)
    {
        if (!isPrime(k))
            return 0;
        k /= 10;
    }

    return 1;
}

int main()
{
    int count = 0;
    int sum = 0;
    for (int i = 11; count < 11; ++i)
    {
        if (isTruncatablePrime(i))
        {
            count++;
            sum += i;
        }
    }

    printf("%d\n", sum);

    return 0;
}