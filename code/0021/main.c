#include <stdio.h>
#include <math.h>
#define MAX 10000

int d(int n)
{
    int sum = 0;

    for (int i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            sum += i;

            int pair = n / i;
            if (pair != i && pair != n)
                sum += pair;
        }
    }

    return sum;
}

int dp[MAX * 3];

int main()
{
    int sum = 0;

    for (int i = 1; i < MAX; ++i)
    {
        int j = d(i);
        if (dp[j] == i)
        {
            sum += i;
            sum += j;
        }
        else
        {
            dp[i] = j;
        }
    }

    printf("%d", sum);

    return 0;
}