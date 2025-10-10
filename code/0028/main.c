#include <stdio.h>

int main()
{
    int target = 1001;

    int res = 1;
    int carry = res;

    for (int i = 3; i <= target; i += 2)
    {
        int temp = 0;
        for (int j = 1; j <= 4; ++j)
        {
            temp = (i - 1) * j + carry;
            res += temp;
        }
        carry = temp;
    }

    printf("%d\n", res);

    return 0;
}