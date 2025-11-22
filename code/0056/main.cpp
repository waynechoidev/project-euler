#include <bits/stdc++.h>
using namespace std;

vector<int> vec(int n)
{
    vector<int> v;
    while (n)
    {
        int t = n % 10;
        v.push_back(t);
        n /= 10;
    }
    return v;
}

vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
    vector<int> res(a.size() + b.size(), 0);

    for (size_t i = 0; i < a.size(); ++i)
    {
        int carry = 0;
        for (size_t j = 0; j < b.size(); ++j)
        {
            int n = res[i + j] + a[i] * b[j] + carry;
            res[i + j] = n % 10;
            carry = n / 10;
        }
        if (carry)
            res[i + b.size()] += carry;
    }

    while (res.size() > 1 && res.back() == 0)
        res.pop_back();

    return res;
}

int digitSum(int a, int b)
{
    vector<int> v = vec(a);
    vector<int> res = vec(1);
    for (int i = 0; i < b; ++i)
        res = multiply(res, v);

    int sum = 0;
    for (int x : res)
        sum += x;

    return sum;
}

int main()
{
    int res = 0;
    for (int a = 1; a < 100; ++a)
        for (int b = 1; b < 100; ++b)
            res = max(res, digitSum(a, b));

    cout << res << endl;

    return 0;
}