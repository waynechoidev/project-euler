#include <bits/stdc++.h>
using namespace std;

int main()
{

    int count = 0;
    int n = 1;

    while (true)
    {
        int temp = 0;
        for (int a = 1; a <= 9; ++a)
            if (floor(n * log10(a)) + 1 == n)
                temp++;

        if (temp)
            count += temp;
        else
            break;

        n++;
    }
    cout << count << endl;

    return 0;
}