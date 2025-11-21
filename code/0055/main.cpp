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

bool isPalindromic(const vector<int> &v)
{
    vector<int> r = v;
    reverse(r.begin(), r.end());
    return v == r;
}

vector<int> step(const vector<int> &v)
{
    vector<int> res;
    vector<int> r = v;
    reverse(r.begin(), r.end());
    int carry = 0;
    for (int i = 0; i < r.size(); ++i)
    {
        int t = carry + v[i] + r[i];
        res.push_back(t % 10);
        carry = t / 10;
    }
    if (carry)
        res.push_back(carry);
    return res;
}

bool isLychrel(int n)
{
    vector<int> cur = vec(n);

    for (int i = 0; i < 50; ++i)
    {
        cur = step(cur);
        if (isPalindromic(cur))
            return false;
    }

    return true;
}

int main()
{
    int count = 0;

    for (int i = 1; i < 10000; ++i)
        if (isLychrel(i))
            count++;

    cout << count << endl;

    return 0;
}