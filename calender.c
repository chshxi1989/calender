#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
-1: not leap year
0: leap_year
*/
int check_leap_year(int year)
{
    if(year%400 == 0)
    {
        return 0;
    }
    if(year%100 == 0)
    {
        return -1;
    }
    if(year%4 == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

/*
1900.1.1 is Monday
0: Sunday
1: Monday
6: Saturday
*/
int calender(int year, int month, int day)
{
    if(year < 1900)
    {
        return -1;
    }
    if(month <= 0 || month >12)
    {
        return -1;
    }
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(0 == check_leap_year(year))
    {
        month_days[1] = 29; 
    }
    if(day > month_days[month])
    {
        return -1;
    }
    int start = 1;
    int i = 0;
    for(i = 1900; i < year; i++)
    {
        if(0 == check_leap_year(i))
        {
             start = (start+366)%7;
        }
        else
        {
             start = (start+365)%7;
        }
    }
    for(i = 0; i < month-1; i++)
    {
        start = (start+month_days[i])%7;
    }
    start = (start+day-1)%7;
    return start;
}

int main(int argc, char** argv)
{
    if(argc != 4)
    {
        return -1;
    }
    int year = strtol(argv[1], NULL, 10);
    int month = strtol(argv[2], NULL, 10);
    int day = strtol(argv[3], NULL , 10);
    int cal = calender(year, month, day);
    if(cal == -1)
    {
        printf("args error\n");
    }
    switch(cal)
    {
        case 0: printf("Sunday\n"); break;
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Tursday\n"); break;
        case 5: printf("Friday\n"); break;
        case 6: printf("Saturday\n"); break;
        default: break;
    }
    return cal;
}
