/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-08, Chapter5.
 */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    int year, month, day, yearday;
    int doy, pmonth, pday;

    year = 2012;
    month = 2;
    day = 29;
    doy = day_of_year(year, month, day);
    if (doy)
        printf("%d-%d-%d: day %dth of the year.\n", year, month, day, doy);
    else
        printf("%d-%d-%d: invalid!\n", year, month, day);

    year = 2012;
    month = 6;
    day = 31;
    doy = day_of_year(year, month, day);
    if (doy)
        printf("%d-%d-%d: day %dth of the year.\n", year, month, day, doy);
    else
        printf("%d-%d-%d: invalid!\n", year, month, day);
        
    year = 2012;
    yearday = 60;
    doy = month_day(year, yearday, &pmonth, &pday);
    if (doy)
        printf("day %dth of year %d is %d-%d.\n", yearday, year, pmonth, pday);
    else
        printf("day %dth of year %d do not exsits!\n", yearday, year);

    year = 2012;
    yearday = 367;
    doy = month_day(year, yearday, &pmonth, &pday);
    if (doy)
        printf("day %dth of year %d is %d-%d.\n", yearday, year, pmonth, pday);
    else
        printf("day %dth of year %d do not exsits!\n", yearday, year);

    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (month < 1 || month > 12 || day < 1)
        return 0;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (day > daytab[leap][month])
        return 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (yearday < 1 || yearday > (leap ? 366 : 365))
        return 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
    return 1;
}