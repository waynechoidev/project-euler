#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 5000
#define MAX_LEN 32
#define MAX_VAL 200

int main()
{

    FILE *fp = fopen("words.txt", "r");
    if (!fp)
    {
        perror("fopen");
        return 1;
    }

    char buffer[500000];
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    char words[MAX_WORDS][MAX_LEN];
    int length = 0;

    char *token = strtok(buffer, ",");

    while (token && length < MAX_WORDS)
    {

        char *start = token;
        char *end = token + strlen(token) - 1;

        if (*start == '"')
            start++;

        while (end > start && (*end == '"' || *end == '\n' || *end == '\r'))
        {
            *end = '\0';
            end--;
        }

        strncpy(words[length], start, MAX_LEN - 1);
        words[length][MAX_LEN - 1] = '\0';

        length++;

        token = strtok(NULL, ",");
    }

    int triangles[MAX_VAL] = {0};
    int i = 1;
    int n = 0;
    while (1)
    {
        n = i * (i + 1) / 2;
        if (n >= MAX_VAL)
            break;
        triangles[n] = 1;
        i++;
    }

    int count = 0;

    for (int i = 0; i < length; ++i)
    {
        int j = 0;
        char *word = words[i];
        int sum = 0;
        while (word[j] != '\0')
        {
            sum += word[j] - 'A' + 1;
            j++;
        }

        if (triangles[sum])
            count++;
    }

    printf("%d", count);

    return 0;
}