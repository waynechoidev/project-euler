#include <stdio.h>
#define DIGITS 1000
int num[DIGITS];
int last[DIGITS];

int main()
{
    num[0] = 2;
    last[0] = 1;
    int p = 0;
    int idx = 3;
    while (1)
    {
        int carry = 0;
        for (int i = 0; i <= p; ++i)
        {
            int n = num[i] + last[i] + carry;
            last[i] = num[i];
            num[i] = n % 10;
            carry = n / 10;
        }
        if (carry)
            num[++p] = carry;

        idx++;

        if (num[DIGITS - 1] > 0)
            break;
    }

    printf("%d\n", idx);

    // for (int i = DIGITS - 1; i >= 0; --i)
    // printf("%d", num[i]);

    return 0;
}