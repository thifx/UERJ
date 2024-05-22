#include <stdio.h>
#include <string.h>

int main()
{
    char DFAstate = 'a', c;
    int wordcounter = 0;
    const char delimiters[] = " :;,.";

    while ((c = fgetc(stdin)) != '\n')
    {
        switch (DFAstate)
        {
        case 'a':
            if (strchr(delimiters, c) == NULL)
            {
                wordcounter++;
                DFAstate = 'b';
            }
            break;
        case 'b':
            if (strchr(delimiters, c))
            {
                DFAstate = 'a';
            }
            break;
        }
    }
    printf("%d", wordcounter);
    return 0;
}