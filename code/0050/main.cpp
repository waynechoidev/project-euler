#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int limit = 1000000;
    vector<int> p;

    for (int i = 2; i <= limit; ++i)
        if (isPrime(i))
            p.push_back(i);

    int size = p.size();

    int maxCount = 0;
    int maxSum = 0;

    for (int i = 0; i < size; ++i)
    {
        int count = 0;
        int sum = 0;
        int idx = i;
        while (idx < size && sum + p[idx] < limit)
        {
            count++;
            sum += p[idx];
            idx++;
        }
        if (isPrime(sum) && maxCount < count)
        {
            maxCount = count;
            maxSum = sum;
        }
    }

    cout << maxSum << endl;

    return 0;
}