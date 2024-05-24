#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int printableCharCount = 0, charCount = 0, lineCount = 0;
    int c;
    FILE *fileptr;
    char filename[256];

    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;

    fileptr = fopen(filename, "r");
    if (fileptr == NULL)
    {
        printf("Erro no arquivo %s\n", filename);
        exit(1);
    }
    while ((c = fgetc(fileptr)) != EOF)
    {
        if (isprint(c))
            printableCharCount++;
        if (c == 10)
            lineCount++;
        charCount++;
    }

    printf("%d\n%d\n%d\n", charCount, printableCharCount, lineCount);
    fclose(fileptr);
    return 0;
}