#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadHeader(FILE *pgm_ptr, int *totalColumns, int *totalLines);
int **allocateImageBody(int totalLines, int totalColumns);

int main()
{
    char line[256];
    int totalLines = 0, totalColumns = 0;
    char filename[256];

    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;

    FILE *pgm_ptr = fopen(filename, "r");

    if (pgm_ptr == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    loadHeader(pgm_ptr, &totalColumns, &totalLines);

    int **imageData = allocateImageBody(totalLines, totalColumns);

    fgets(line, sizeof(line), pgm_ptr);

    for (int i = 0; i < totalLines; i++)
    {
        for (int j = 0; j < totalColumns; j++)
        {
            fscanf(pgm_ptr, "%d", &imageData[i][j]);
        }
    }

    for (int i = 0; i < totalLines; i++)
    {
        for (int j = 0; j < totalColumns; j++)
        {
            if (j < totalColumns - 1)
                printf("%03X ", imageData[i][j]);
            else
            {
                printf("%03X", imageData[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < totalLines; i++)
    {
        free(imageData[i]);
    }
    free(imageData);

    fclose(pgm_ptr);
    return 0;
}

void loadHeader(FILE *pgm_ptr, int *totalColumns, int *totalLines)
{
    char line[256];
    int linecount = 1;

    while (fgets(line, sizeof(line), pgm_ptr) != NULL)
    {
        if (line[0] == '#')
            continue;
        if (linecount == 2)
        {
            char *token = strtok(line, " ");
            int i = 0;
            while (token != NULL)
            {
                if (i == 0)
                {
                    *totalColumns = atoi(token);
                }
                else if (i == 1)
                {
                    *totalLines = atoi(token);
                }
                token = strtok(NULL, " ");
                i++;
            }
            break;
        }
        linecount++;
    }
}

int **allocateImageBody(int totalLines, int totalColumns)
{
    int **imageData = (int **)malloc(totalLines * sizeof(int *));
    for (int i = 0; i < totalLines; i++)
    {
        imageData[i] = (int *)malloc(totalColumns * sizeof(int));
    }
    return imageData;
}
