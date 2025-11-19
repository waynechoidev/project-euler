#include <bits/stdc++.h>
using namespace std;

int isValid(int n)
{
    int count = 0;

    for (int i = 2; n > 1; ++i)
    {
        while (n % i == 0)
        {
            count++;
            while (n % i == 0)
                n /= i;
        }
    }

    return count;
}

int main()
{
    int count = 0;

    for (int i = 1;; ++i)
    {
        if (isValid(i) == 4)
            count++;
        else
            count = 0;
        if (count == 4)
        {
            cout << i - 3 << endl;
            return 0;
        }
    }
}