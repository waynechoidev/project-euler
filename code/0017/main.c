#include <stdio.h>

int main()
{
    static int lengths[] = {
        0, //
        3, //"one"
        3, //"two"
        5, //"three"
        4, //"four"
        4, //"five"
        3, //"six"
        5, //"seven"
        5, //"eight"
        4, //"nine"
        3, //"ten"
        6, //"eleven"
        6, //"twelve"
        8, //"thirteen"
        8, //"fourteen"
        7, //"fifteen"
        7, //"sixteen"
        9, //"seventeen"
        8, //"eighteen"
        8  //"nineteen"
    };

    static int lengthsOfTens[] = {
        0, //
        0, //
        6, // twenty
        6, // thirty
        5, // forty
        5, // fifty
        5, // sixty
        7, // seventy
        6, // eighty
        6  // ninety
    };

    int oneToNineteen = 0;
    for (int i = 1; i <= 19; ++i)
        oneToNineteen += lengths[i];

    int oneToNinetyNine = 0;
    oneToNinetyNine += oneToNineteen;
    for (int i = 2; i <= 9; ++i)
    {
        oneToNinetyNine += lengthsOfTens[i]; // 20, 30, 40 ...
        for (int j = 1; j <= 9; ++j)
            oneToNinetyNine += (lengthsOfTens[i] + lengths[j]);
    }

    int res = 0;

    // 1 ~ 99
    res += oneToNinetyNine;

    // 100~999
    for (int i = 1; i <= 9; ++i)
    {
        // n00
        res += lengths[i]; // 1 ~ 9
        res += 7;          // hundred

        // n01 ~ n99
        res += ((lengths[i] + 10) * 99); // n hundred and * 99
        res += oneToNinetyNine;          // 1 ~ 99
    }

    // 1000
    res += 11;

    printf("%d", res);

    return 0;
}