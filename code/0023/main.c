#include <stdio.h>
#include <math.h>
#define MAX 28123

int abundants[MAX];
int canBeWritten[MAX];

int isAbundant(int n)
{
    int sum = 0;
    for (int i = 1; i <= sqrt(n); ++i)
        if (n % i == 0)
        {
            sum += i;

            int pair = n / i;
            if (pair != i && pair != n)
                sum += pair;
        }

    if (sum <= n)
        return 0;
    return 1;
}

int main()
{
    for (int i = 12; i < MAX; ++i)
        if (isAbundant(i))
            abundants[i] = 1;

    for (int i = 12; i < MAX; ++i)
        if (abundants[i])
            for (int j = 12; j < MAX; ++j)
                if (abundants[j] && i + j < MAX)
                    canBeWritten[i + j] = 1;

    long long sum = 0;
    for (int i = 1; i < MAX; ++i)
        if (!canBeWritten[i])
            sum += i;

    printf("%lld\n", sum);

    return 0;
}