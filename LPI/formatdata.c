#include <stdio.h>
#include <string.h>
#include <ctype.h>
void tolowercase(char *);
int main()
{
    char *monthnames[] = {"janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    int day, month, year;
    char date[32], monthname[16];
    while (fgets(date, sizeof(date), stdin) != NULL)
    {
        if (sscanf(date, "%d de %s de %d", &day, monthname, &year) == 3)
        {
            for (int i = 0; i < 12; i++)
            {
                if (strcasecmp(monthname, monthnames[i]) == 0)
                    month = i + 1;
            }
            printf("%02d/%02d/%d", day, month, year);
        }
        else if (sscanf(date, "%d/%d/%d", &day, &month, &year) == 3)
        {
            printf("%02d/%02d/%d", day, month, year);
        }
    }
    return 0;
}