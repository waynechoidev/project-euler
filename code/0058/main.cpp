#include <bits/stdc++.h>
using namespace std;

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int t = 1;
    int p = 0;

    int cur = 1;
    for (int i = 1;; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cur += (2 * i);
            t++;
            if (isPrime(cur))
                p++;
        }
        if (p * 10 < t)
        {
            cout << 2 * i + 1 << endl;
            return 0;
        }
    }
}