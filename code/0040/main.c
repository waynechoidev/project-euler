#include <stdio.h>
#include <math.h>
#define MAX 1000000

int len(int n)
{
    int count = 0;
    while (n)
    {
        n /= 10;
        count++;
    }
    return count;
}

int main()
{
    int count = 0;
    int d[MAX + 1] = {0};

    for (int i = 1; count <= MAX; ++i)
    {
        int l = len(i);
        int n = i;
        for (int j = 1; j <= l; ++j)
        {
            int t = (int)pow(10, l - j);
            int k = n / t;
            if (++count > MAX)
                break;
            d[count] = k;
            n -= k * t;
        }
    }

    int res = d[1] * d[10] * d[100] * d[1000] * d[10000] * d[100000] * d[1000000];

    printf("%d\n", res);

    return 0;
}