#include <stdio.h>

int main()
{
    int n = 4000000;
    int a = 1, b = 2;
    int sum = 0;
    while (b <= n)
    {
        if (b % 2 == 0)
            sum += b;
        int next = a + b;
        a = b;
        b = next;
    }
    printf("%d\n", sum);
    return 0;
}