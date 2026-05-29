#include <bits/stdc++.h>
using namespace std;

int main()
{

    int max = 1000000;
    int res = 0;

    for (int q = 1; q <= max; ++q)
    {
        int n = 3 * q - 1;
        if (n % 7 == 0)
            res = n / 7;
    }

    cout << res << endl;

    return 0;
}