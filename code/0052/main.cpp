#include <bits/stdc++.h>
using namespace std;

bool isValid(int a, int b)
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

int main()
{
    for (int x = 1;; ++x)
        if (
            isValid(x, 2 * x) &&
            isValid(x, 3 * x) &&
            isValid(x, 4 * x) &&
            isValid(x, 5 * x) &&
            isValid(x, 6 * x))
        {
            cout << x << endl;
            return 0;
        }
}