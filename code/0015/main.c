#include <stdio.h>
#define SIZE 20
long long dp[SIZE + 1][SIZE + 1];

int main()
{
    for (int i = 0; i <= SIZE; ++i)
        dp[i][0] = dp[0][i] = 1;

    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    printf("%lld", dp[SIZE][SIZE]);

    return 0;
}