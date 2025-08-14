#include <stdio.h>

int main()
{
    int n = 100;

    int num[200] = {0};
    num[0] = 1;

    int cur = 0;
    while (n)
    {
        int carry = 0;
        for (int i = 0; i <= cur; ++i)
        {
            num[i] *= n;
            num[i] += carry;
            carry = num[i] / 10;
            num[i] = num[i] % 10;
        }

        while (carry > 0)
        {
            num[++cur] = carry % 10;
            carry /= 10;
        }

        n--;
    }

    int sum = 0;
    for (int i = 0; i <= cur; ++i)
        sum += num[i];

    printf("%d", sum);

    return 0;
}