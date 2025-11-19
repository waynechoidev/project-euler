#include <bits/stdc++.h>
using namespace std;

bool isPent(long long x)
{
    double n = (1 + sqrt(1 + 24 * x)) / 6;
    return n == (long long)n;
}

long long hex(long long n)
{
    return n * (2 * n - 1);
}

long long hexIndex(long long x)
{
    return (1 + sqrt(1 + 8 * x)) / 4;
}

int main()
{
    int start = hexIndex(40755) + 1;

    for (int n = start;; ++n)
    {
        long long x = hex(n);
        if (isPent(x))
        {
            cout << x << endl;
            break;
        }
    }

    return 0;
}