#include <bits/stdc++.h>
using namespace std;

vector<int> mul(int n)
{
    vector<int> res(10);
    res[9] = 1;
    for (int i = 0; i < n; ++i)
    {
        int carry = 0;
        for (int j = 9; j >= 0; --j)
        {
            int t = carry + n * res[j];
            res[j] = t % 10;
            carry = t / 10;
        }
    }

    return res;
}

void add(vector<int> &target, const vector<int> &n)
{
    int carry = 0;
    for (int i = 9; i >= 0; --i)
    {
        int t = carry + target[i] + n[i];
        target[i] = t % 10;
        carry = t / 10;
    }
}

int main()
{
    int max = 1000;
    vector<int> res(10);

    for (int i = 1; i <= max; ++i)
        add(res, mul(i));

    for (int n : res)
        cout << n;
    cout << endl;

    return 0;
}