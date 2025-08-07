#include <stdio.h>

int main()
{
    int n = 1000;
    int res = 0;
    for (int i = 1; i < n; ++i)
        if (i % 3 == 0 || i % 5 == 0)
            res += i;
    printf("%d\n", res);
    return 0;
}