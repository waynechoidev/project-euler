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

bool isValid(int n)
{
    for (int i = 1; n > 2 * i * i; ++i)
    {
        int diff = n - 2 * i * i;
        if (isPrime(diff))
            return true;
    }
    return false;
}

int main()
{
    int i = 3;
    while (true)
    {
        if (!isPrime(i))
            if (!isValid(i))
            {
                cout << i << endl;
                break;
            }
        i += 2;
    }

    return 0;
}