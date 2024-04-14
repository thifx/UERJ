#include <stdio.h>
enum bool
{
    false,
    true
};

enum bool isLeapYear(int);
int calculateDays(int, int, int);
int main()
{
    int day, month, year;
    scanf("%d %d %d", &day, &month, &year);
    int totalDays = calculateDays(day, month, year);
    printf("%d\n", totalDays);
    return 0;
}

enum bool isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    else
        return false;
}

int calculateDays(int day, int month, int year)
{
    int daysOfTheYear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = 0;
    int acc = 0;
    while (i < month - 1)
    {
        acc += daysOfTheYear[i];
        i++;
    }
    acc += day;
    enum bool isLeap = isLeapYear(year);
    if (isLeap == true)
        return acc + 1;
    return acc;
}