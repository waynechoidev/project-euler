#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeFactors(int n)
{
    vector<int> factors;

    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            factors.push_back(i);
            while (n % i == 0)
                n /= i;
        }

    if (n > 1)
        factors.push_back(n);

    return factors;
}

int main()
{

    long long res = 0;
    double maxRatio = 0.0;

    for (int i = 2; i <= 1000000; ++i)
    {
        long long phi = i;

        for (int f : getPrimeFactors(i))
        {
            phi *= f - 1;
            phi /= f;
        }

        double ratio = (double)i / phi;

        if (ratio > maxRatio)
        {
            maxRatio = ratio;
            res = i;
        }
    }

    cout << res << endl;

    return 0;
}