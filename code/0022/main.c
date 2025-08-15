#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAMES 6000

int cmp(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int main()
{
    FILE *fp = fopen("names.txt", "r");
    char buffer[600000];
    fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    char *names[MAX_NAMES];
    int count = 0;
    char *token = strtok(buffer, "\",");
    while (token != NULL)
    {
        names[count++] = token;
        token = strtok(NULL, "\",");
    }

    qsort(names, count, sizeof(char *), cmp);

    int res = 0;
    for (int i = 0; i < count; ++i)
    {
        int sum = 0;
        int j = 0;
        while (names[i][j] != '\0')
        {
            sum += (names[i][j++] - 'A' + 1);
        }

        res += ((i + 1) * sum);
    }

    printf("%d", res);

    return 0;
}