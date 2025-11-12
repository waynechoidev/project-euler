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

int len(int n)
{
    int count = 0;
    while (n)
    {
        n /= 10;
        count++;
    }
    return count;
}

int isPandigital(int n)
{
    int arr[10] = {0};
    int count = 0;
    int l = len(n);

    while (n)
    {
        int d = n % 10;
        if (d == 0 || arr[d])
            return 0;
        arr[d] = 1;
        count++;
        n /= 10;
    }

    for (int i = 1; i <= l; ++i)
    {
        if (arr[i] != 1)
            return 0;
    }

    return 1;
}

int main()
{
    for (int i = 7654321; i > 1; --i)
    {
        if (isPrime(i) && isPandigital(i))
        {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}