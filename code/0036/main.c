#include <stdio.h>

int a[20];

int isPalindrom(int n, int base)
{
    int k = n;
    int count = 0;
    while (k)
    {
        a[count++] = k % base;
        k /= base;
    }
    for (int i = 0; i < count / 2; ++i)
    {
        if (a[i] != a[count - i - 1])
            return 0;
    }
    return 1;
}

int main()
{
    int sum = 0;

    for (int i = 1; i < 1000000; ++i)
    {
        if (isPalindrom(i, 10) && isPalindrom(i, 2))
            sum += i;
    }

    printf("%d\n", sum);

    return 0;
}