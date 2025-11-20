#include <bits/stdc++.h>
using namespace std;

vector<long long> fac(101);

int countOverMillion(int n)
{
    double cur = n;
    int r_min = -1;
    for (int r = 2; n >= r; ++r)
    {
        cur *= (double)(n - r + 1) / r;
        if (cur > 1000000.0)
        {
            r_min = r;
            break;
        }
    }

    if (r_min == -1)
        return 0;
    return n - (r_min * 2) + 1;
}

int main()
{
    int count = 0;

    for (int i = 1; i <= 100; ++i)
        count += countOverMillion(i);

    cout << count << endl;
    return 0;
}