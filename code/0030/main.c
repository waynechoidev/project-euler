#include <stdio.h>
#include <math.h>

int main()
{
    int len = 5;
    int res = 0;

    for (int i = 2; i < pow(10, len + 1); ++i)
    {
        int n = i;
        int sum = 0;

        while (n > 0)
        {
            int digit = n % 10;
            n /= 10;
            sum += pow(digit, 5);
        }

        if (i == sum)
            res += sum;
    }

    printf("%d", res);

    return 0;
}