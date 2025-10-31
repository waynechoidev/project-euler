#include <stdio.h>

int fac(int n)
{
    if (n <= 1)
        return 1;
    return n * fac(n - 1);
}

int main()
{
    int facs[10];
    for (int i = 0; i <= 9; ++i)
    {
        facs[i] = fac(i);
    }
    int max = facs[9] * 7;
    int sum = 0;

    for (int i = 10; i <= max; ++i)
    {
        int n = i;
        int t = 0;
        while (n)
        {
            int k = n % 10;
            t += facs[k];
            n /= 10;
        }
        if (t == i)
            sum += t;
    }

    printf("%d\n", sum);

    return 0;
}