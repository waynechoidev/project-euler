#include <stdio.h>
#include <math.h>

void find_base_exponent(int n, int *base, int *exp)
{
    *base = n;
    *exp = 1;

    for (int b = 2; b * b <= n; b++)
    {
        int value = b;
        int k = 1;

        while (value < n)
        {
            value *= b;
            k++;
        }

        if (value == n)
        {
            *base = b;
            *exp = k;
            return;
        }
    }
}

int main()
{
    int size = 100;

    int arr[101][1001] = {0};

    for (int a = 2; a <= size; ++a)
    {
        int base, exp;
        find_base_exponent(a, &base, &exp);
        for (int b = 2; b <= size; ++b)
            arr[base][b * exp] = 1;
    }

    int count = 0;

    for (int i = 0; i <= 100; ++i)
        for (int j = 0; j <= 1000; ++j)
            if (arr[i][j])
                count++;

    printf("%d\n", count);

    return 0;
}