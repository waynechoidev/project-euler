#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max = 2000000;
    int *arr = (int *)malloc(max * sizeof(int));

    for (int i = 0; i < max; ++i)
        arr[i] = 1;
    arr[0] = arr[1] = 0;

    long long sum = 0;

    for (int i = 2; i * i < max; ++i)
    {
        if (arr[i])
            for (int j = i * i; j <= max; j += i)
                arr[j] = 0;
    }

    for (int i = 0; i < max; ++i)
    {
        if (arr[i])
            sum += i;
    }

    printf("%lld", sum);

    free(arr);
    return 0;
}