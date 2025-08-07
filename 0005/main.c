#include <stdio.h>

int main()
{
    int range = 20;
    int n = 11;
    while (1)
    {
        int isValid = 1;

        for (int i = 1; i <= range; ++i)
        {
            if (n % i != 0)
            {
                isValid = 0;
                break;
            }
        }

        if (isValid)
        {
            break;
        }
        n++;
    }

    printf("%d", n);

    return 0;
}