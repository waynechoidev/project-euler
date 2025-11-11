#include <stdio.h>
#include <math.h>

int getPandigital(int n)
{
    int dp[10] = {0};
    int len = 0;
    int concat = 0;

    for (int k = 1; len < 9; ++k)
    {
        int x = n * k;
        int l = 0;
        while (x)
        {
            int d = x % 10;
            if (dp[d] || d == 0)
                return -1;
            l++;
            dp[d]++;
            x /= 10;
        }
        len += l;

        concat *= (int)pow(10, l);
        concat += n * k;
    }

    if (len -= 9)
        return -1;

    return concat;
}

int main()
{
    int max = 0;

    for (int n = 1; n < 10000; ++n)
    {
        int x = getPandigital(n);
        if (x > max)
            max = x;
    }

    printf("%d\n", max);

    return 0;
}