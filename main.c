#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUMBERS 10

int parseFieldArguments(const char *arg, int *numbers)
{
    const char *start = arg + 2;
    char *token;
    char *argCopy = strdup(start);
    int count = 0;
    token = strtok(argCopy, " ,");
    while (token != NULL)
    {
        numbers[count++] = atoi(token);
        token = strtok(NULL, " ,");
    }

    free(argCopy);
    return count;
}

void printField(FILE *file, int *numbers, int count, char delimiter, int maxLines)
{
    char line[MAX_LINE_LENGTH];
    int lines = 0;

    char delimStr[] = {delimiter, '\0'};

    while (fgets(line, sizeof(line), file) && lines < maxLines)
    {
        line[strcspn(line, "\n")] = 0;

        char *token = strtok(line, delimStr);
        char output[MAX_LINE_LENGTH] = "";
        int column;

        for (column = 0; token != NULL; column++)
        {

            for (int i = 0; i < count; i++)
            {
                if (column == numbers[i])
                {

                    strcat(output, token);
                    strcat(output, " ");
                    break;
                }
            }

            token = strtok(NULL, delimStr);
        }

        if (output[0] != '\0')
        {
            output[strlen(output) - 1] = '\0';
            printf("%s\n", output);
        }

        lines++;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s -<command> <json-file>\n", argv[0]);
        return 1;
    }

     int maxLine = 30;
    const char *command = argv[1];
    const char *fileName = NULL;
    char delimeter = '\t';
    int count = 0;
    int numbers[MAX_NUMBERS];

    for (int i = 1; i < argc; i++)
    {
        if (strncmp(argv[i], "-f", 2) == 0)
        {
            count = parseFieldArguments(argv[i], numbers);
        }
        else if (strncmp(argv[i], "-d", 2) == 0)
        {
            delimeter = argv[i][2];
        }
        else if (strncmp(argv[i], "-n", 2) == 0)
        {
            maxLine = atoi(argv[i] + 2);
        }
        else
        {
            fileName = argv[i];
        }
    }

    if (index < 0 || fileName == NULL)
    {
        printf("Invalid arguments. Usage: %s -f<field-number> [-d<delimiter>] <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    printField(file, numbers, count, delimeter, maxLine);

    fclose(file);

    return 0;
}