#include <stdio.h>

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int dp[201] = {0};
    dp[0] = 1;
    for (int i = 0; i < 8; ++i)
    {
        int coin = coins[i];

        for (int n = coin; n <= 200; ++n)
        {
            dp[n] += dp[n - coin];
        }
    }

    printf("%d\n", dp[200]);

    return 0;
}