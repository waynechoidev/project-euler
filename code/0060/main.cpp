#include <bits/stdc++.h>
using namespace std;

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int len(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
}

int concatInt(int a, int b)
{
    int t = b;
    int mul = 1;
    while (t)
    {
        mul *= 10;
        t /= 10;
    }
    return a * mul + b;
}

bool isValid(int i, int j)
{
    return isPrime(concatInt(i, j)) && isPrime(concatInt(j, i));
}

vector<int> vertices;
vector<vector<bool>> edges;
int N;
int lowestSum = INT_MAX;
vector<int> bestSet;
vector<int> cur;

void track(int idx, int curSum)
{
    if (cur.size() == 5)
    {
        if (curSum < lowestSum)
        {
            lowestSum = curSum;
            bestSet = cur;
        }
        return;
    }

    for (int i = idx; i < N; ++i)
    {
        bool ok = true;
        for (int u : cur)
        {
            if (!edges[u][i])
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            continue;

        cur.push_back(i);
        track(i + 1, curSum + vertices[i]);
        cur.pop_back();
    }
}

int main()
{
    int max = 10000;
    for (int i = 2; i <= max; ++i)
        if (isPrime(i))
            vertices.push_back(i);
    N = vertices.size();
    edges.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (isValid(vertices[i], vertices[j]))
            {
                edges[i][j] = true;
                edges[j][i] = true;
            }

    track(0, 0);

    cout << lowestSum << endl;

    return 0;
}