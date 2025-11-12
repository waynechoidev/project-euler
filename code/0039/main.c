#include <stdio.h>

int main()
{
    int max = 0;
    int res = 0;
    for (int p = 1; p <= 1000; ++p)
    {
        int count = 0;
        for (int a = 1; a < p / 3; ++a)
        {
            int k = p * p - 2 * a * p;
            int d = 2 * (p - a);
            if (k % d != 0)
                continue;
            int b = k / d;
            int c = p - a - b;
            if (a < b && b < c)
                count++;
        }
        if (max < count)
        {
            max = count;
            res = p;
        }
    }

    printf("%d\n", res);

    return 0;
}