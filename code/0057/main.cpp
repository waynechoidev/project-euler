#include <bits/stdc++.h>
using namespace std;

vector<int> add(const vector<int> &a, const vector<int> &b)
{
    vector<int> res;
    int carry = 0;
    int n = max(a.size(), b.size());

    for (int i = 0; i < n; ++i)
    {
        int x = (i < a.size()) ? a[i] : 0;
        int y = (i < b.size()) ? b[i] : 0;
        int s = x + y + carry;

        res.push_back(s % 10);
        carry = s / 10;
    }

    if (carry)
        res.push_back(carry);

    return res;
}

vector<int> mulByDigit(const vector<int> &a, int k)
{
    vector<int> res;
    int carry = 0;

    for (int i = 0; i < a.size(); ++i)
    {
        int v = a[i] * k + carry;
        res.push_back(v % 10);
        carry = v / 10;
    }

    while (carry)
    {
        res.push_back(carry % 10);
        carry /= 10;
    }

    return res;
}

int main()
{
    vector<int> p = {3};
    vector<int> q = {2};

    int count = 0;

    for (int i = 2; i <= 1000; ++i)
    {
        auto nextP = add(p, mulByDigit(q, 2));
        auto nextQ = add(p, q);

        p = nextP;
        q = nextQ;

        if (p.size() > q.size())
            count++;
    }

    cout << count << endl;

    return 0;
}