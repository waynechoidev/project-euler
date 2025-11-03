#include <stdio.h>
#include <math.h>

#define MAX 1000000
int p[MAX];

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

int isCircularPrime(int n)
{
    if (!p[n])
        return 0;

    int l = (int)pow(10, len(n) - 1);
    int temp = n % 10;
    int k = n / 10 + l * temp;

    while (k != n)
    {
        if (!p[k])
            return 0;
        temp = k % 10;
        k = k / 10 + l * temp;
    }
    return 1;
}

int main()
{
    for (int i = 1; i < MAX; ++i)
    {
        p[i] = isPrime(i);
    }

    int count = 0;
    for (int i = 1; i < MAX; ++i)
    {
        if (isCircularPrime(i))
            count++;
    }

    printf("%d\n", count);

    return 0;
}