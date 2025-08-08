#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getNumOfDivisors(int n)
{
    int limit = sqrt(n) + 1;
    int *arr = (int *)calloc(limit + 1, sizeof(int));

    int num = n;
    for (int i = 2; i <= limit && num > 1; ++i)
        while (num % i == 0)
        {
            num /= i;
            arr[i]++;
        }

    int res = 1;
    for (int i = 0; i <= limit; ++i)
        res *= arr[i] + 1;

    if (num > 1)
        res *= 2;

    free(arr);
    return res;
}

int main()
{
    int target = 500;
    int last = 1;
    int i = 2;

    while (getNumOfDivisors(last) < target)
    {
        int cur = last + i;
        last = cur;
        i++;
    }

    printf("%d", last);

    return 0;
}