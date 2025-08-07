#include <stdio.h>

int main()
{
    int n = 100;
    int sumOfSquares = 0;
    int sum = 0;

    for (int i = 0; i <= n; ++i)
    {
        sumOfSquares += i * i;
        sum += i;
    }
    int squareOfSum = sum * sum;

    int difference = squareOfSum - sumOfSquares;
    printf("%d", difference);

    return 0;
}