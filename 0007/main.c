#include <stdio.h>

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int maxCount = 10001;
    int n = 2;
    int count = 0;
    int res = 0;

    while (count < maxCount)
    {
        if (isPrime(n))
        {
            count++;
            res = n;
        }
        n++;
    }

    printf("%d\n", res);

    return 0;
}