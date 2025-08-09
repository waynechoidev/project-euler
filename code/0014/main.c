#include <stdio.h>
#include <stdlib.h>

int main()
{
    int limit = 1000000;
    int *dp = calloc(limit + 1, sizeof(int));

    int max = 0;
    int res = 0;
    for (int i = 1; i < limit; ++i)
    {
        long long n = i;
        int count = 1;
        while (n != 1)
        {
            if (n <= limit && dp[n])
            {
                count += dp[n];
                break;
            }
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                n = 3 * n + 1;
            }
            count++;
        }

        dp[i] = count;

        if (count > max)
        {
            max = count;
            res = i;
        }
    }

    printf("%d", res);

    return 0;
}