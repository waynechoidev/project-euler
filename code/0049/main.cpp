#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPermuation(int a, int b)
{
    vector<int> A(10);
    vector<int> B(10);
    while (a)
    {
        A[a % 10]++;
        a /= 10;
    }
    while (b)
    {
        B[b % 10]++;
        b /= 10;
    }
    return A == B;
}

bool isValid(int n, int a)
{
    if (!isPrime(n))
        return false;
    bool nums[10] = {0};

    int t = n;
    for (int i = 3; i >= 0; --i)
    {
        nums[t % 10] = true;
        t /= 10;
    }

    for (int i = 1; i <= 2; ++i)
    {
        t = n + a * i;
        if (!isPrime(t) || !isPermuation(n, t))
            return false;
    }

    return true;
}

int main()
{
    for (int n = 1000; n <= 3330; ++n)
        for (int i = 1000; i < 10000 - 2 * n; ++i)
        {
            if (isValid(i, n))
            {
                for (int j = 0; j <= 2; ++j)
                    cout << i + j * n;
                cout << endl;
            }
        }

    return 0;
}