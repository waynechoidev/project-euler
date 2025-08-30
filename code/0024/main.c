#include <stdio.h>
#define MAX 9
#define ORDER 1000000

int digits[MAX + 1];
int res[MAX + 1];
int factorial[MAX + 1];

int getDigit(int n)
{
    for (int i = 0; i <= MAX; ++i)
        if (digits[i] == 0)
        {
            if (n == 0)
                return i;
            n--;
        }
    return -1;
}

int main()
{
    factorial[0] = 1;
    for (int i = 1; i <= MAX; ++i)
        factorial[i] = factorial[i - 1] * i;

    int n = ORDER - 1;
    for (int i = 0; i <= MAX && n > 0; ++i)
    {
        int nums = factorial[MAX - i];
        int idx = n / nums;
        n = n % nums;
        int digit = getDigit(idx);
        digits[digit] = 1;
        res[i] = digit;
    }

    for (int i = 0; i <= MAX; ++i)
        printf("%d", res[i]);
    printf("\n");

    return 0;
}
