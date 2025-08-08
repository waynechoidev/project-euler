#include <stdio.h>

int isPalindrome(int n)
{
    int original = n, reversed = 0;
    while (original > 0)
    {
        reversed *= 10;
        reversed += (original % 10);
        original /= 10;
    }
    return n == reversed;
}

int main()
{
    int n = 999;
    int max = 0;

    for (int i = n; i > 0; --i)
        for (int j = i; j > 0; --j)
        {
            int key = i * j;
            if (isPalindrome(key))
            {
                if (key > max)
                    max = key;
            }
        }

    printf("%d", max);

    return 0;
}