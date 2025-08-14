#include <stdio.h>

int main()
{
    int count = 0;
    int day = 0; // 0 ~ 6 : Mon ~ Sun

    for (int y = 1900; y <= 2000; ++y)
        for (int m = 1; m <= 12; ++m)
        {
            int numOfDays = 30;
            switch (m)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                numOfDays++;
                break;
            case 2:
                if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                    numOfDays--;
                else
                    numOfDays -= 2;
                break;
            }
            for (int d = 1; d <= numOfDays; ++d)
            {
                if (day == 6)
                {
                    if (y >= 1901 && d == 1)
                        count++;
                    day = 0;
                }
                else
                    day++;
            }
        }

    printf("%d", count);

    return 0;
}