#include <bits/stdc++.h>
using namespace std;

string getKey(long long n)
{
    string s = to_string(n);
    sort(s.begin(), s.end());
    return s;
}

int main()
{
    unordered_map<string, vector<long long>> m;

    for (long long i = 1;; ++i)
    {
        long long cube = i * i * i;
        string key = getKey(cube);
        m[key].push_back(cube);
        if (m[key].size() == 5)
        {
            cout << m[key][0] << endl;
            return 0;
        }
    }
}