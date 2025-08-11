#include <stdio.h>

int main()
{
    int exponent = 1000;
    int num[305] = {0};

    num[0] = 2;
    int cur = 0;

    for (int i = 2; i <= exponent; ++i)
    {
        int carry = 0;
        for (int j = 0; j <= cur; ++j)
        {
            int n = num[j] * 2 + carry;
            num[j] = n % 10;
            carry = n / 10;
        }

        if (carry > 0)
            num[++cur] = carry;
    }

    long long sum = 0;
    for (int i = 0; i <= cur; ++i)
        sum += num[i];

    printf("%lld", sum);

    return 0;
}