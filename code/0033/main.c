#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int numerators = 1;
    int denominators = 1;

    for (int i = 10; i < 100; ++i)        // numerator
        for (int j = i + 1; j < 100; ++j) // denominator
        {
            if (i % 10 == 0 || j % 10 == 0)
                continue;
            int n1 = i / 10;
            int n2 = i % 10;
            int d1 = j / 10;
            int d2 = j % 10;
            int n = 1;
            int d = 1;
            if (n1 == d1)
            {
                n = n2;
                d = d2;
            }
            else if (n2 == d2)
            {
                n = n1;
                d = d1;
            }
            else if (n1 == d2)
            {
                n = n2;
                d = d1;
            }
            else if (n2 == d1)
            {
                n = n1;
                d = d2;
            }

            if (n * j == d * i)
            {
                numerators *= i;
                denominators *= j;
            }
        }

    int g = gcd(numerators, denominators);
    int res = denominators / g;

    printf("%d\n", res);

    return 0;
}