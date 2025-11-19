#include <bits/stdc++.h>
using namespace std;

int isDivisible(const std::vector<int> &v)
{
    if ((v[1] * 100 + v[2] * 10 + v[3]) % 2 != 0)
        return 0;
    if ((v[2] * 100 + v[3] * 10 + v[4]) % 3 != 0)
        return 0;
    if ((v[3] * 100 + v[4] * 10 + v[5]) % 5 != 0)
        return 0;
    if ((v[4] * 100 + v[5] * 10 + v[6]) % 7 != 0)
        return 0;
    if ((v[5] * 100 + v[6] * 10 + v[7]) % 11 != 0)
        return 0;
    if ((v[6] * 100 + v[7] * 10 + v[8]) % 13 != 0)
        return 0;
    if ((v[7] * 100 + v[8] * 10 + v[9]) % 17 != 0)
        return 0;

    return 1;
}

long long toNumber(const vector<int> &v)
{
    long long x = 0;
    for (int i = 0; i < 10; ++i)
        x = x * 10 + v[i];
    return x;
}

int main()
{
    vector<int> a(10);
    for (int i = 0; i < 10; ++i)
        a[i] = i;

    long long sum = 0;

    do
    {
        if (isDivisible(a))
            sum += toNumber(a);
    } while (next_permutation(a.begin(), a.end()));

    cout << sum << endl;

    return 0;
}