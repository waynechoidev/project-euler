#include <bits/stdc++.h>
#define MAX 3000
using namespace std;

bool isPent(long long x)
{
    double n = (1 + sqrt(1 + 24 * x)) / 6;
    return n == (long long)n;
}

long long pent(long long n)
{
    return n * (3 * n - 1) / 2;
}

int main()
{
    long long res = LLONG_MAX;

    for (long long i = 1; i <= MAX; ++i)
    {
        long long a = pent(i);
        for (long long j = 1; j < i; ++j)
        {
            long long b = pent(j);
            long long s = a + b;
            long long d = a - b;
            if (isPent(s) && isPent(d))
                res = min(res, d);
        }
    }

    cout << res;

    return 0;
}