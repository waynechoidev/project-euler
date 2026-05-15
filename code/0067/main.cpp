#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream file("triangle.txt");

    vector<vector<int>> tri;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        vector<int> row;
        int num;

        while (ss >> num)
        {
            row.push_back(num);
        }

        tri.push_back(row);
    }

    int height = tri.size();
    vector<vector<int>> dp(height, vector<int>(height));

    dp[0][0] = tri[0][0];
    for (int i = 1; i < height; ++i)
    {
        int rowSize = tri[i].size();
        for (int j = 0; j < rowSize; ++j)
            dp[i][j] = tri[i][j] + max(dp[i - 1][clamp(j - 1, 0, rowSize - 1)], dp[i - 1][clamp(j, 0, rowSize - 1)]);
    }

    int res = 0;
    for (int x : dp[height - 1])
        res = max(x, res);

    cout << res << endl;

    return 0;
}