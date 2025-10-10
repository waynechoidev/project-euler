#include <stdio.h>
#include <string.h>

static int cycle_len(int d)
{
    int seen[2000];
    for (int i = 0; i < 2000; ++i)
        seen[i] = -1;
    int rem = 1 % d;
    int pos = 0;
    while (rem != 0 && seen[rem] == -1)
    {
        seen[rem] = pos;
        rem = (rem * 10) % d;
        pos++;
    }
    if (rem == 0)
        return 0;
    return pos - seen[rem];
}

int main(void)
{
    int best_d = 0, best_len = -1;
    for (int d = 2; d < 1000; ++d)
    {

        if (d % 2 == 0 || d % 5 == 0)
            continue;
        int len = cycle_len(d);
        if (len > best_len)
        {
            best_len = len;
            best_d = d;
        }
    }
    printf("%d\n", best_d);
    return 0;
}
