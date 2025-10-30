#include <stdio.h>

int len(long long n)
{
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
}

int isPandigital(long long a, long long b, long long c)
{
    int arr[10] = {0};
    int count = 0;
    long long n;

    for (int t = 0; t < 3; t++)
    {
        n = (t == 0 ? a : (t == 1 ? b : c));
        while (n)
        {
            int d = n % 10;
            if (d == 0 || arr[d])
                return 0;
            arr[d] = 1;
            count++;
            n /= 10;
        }
    }

    return count == 9;
}

int main()
{
    int found[100000] = {0};
    int sum = 0;

    for (long long i = 1; i < 10000; ++i)
        for (long long j = 1; j < 10000; ++j)
        {
            int m = i * j;
            if ((len(i) + len(j) + len(m)) != 9)
                continue;
            if (isPandigital(i, j, m))
            {
                if (found[m])
                    continue;
                found[m] = 1;
                sum += m;
            }
        }

    printf("%d\n", sum);

    return 0;
}