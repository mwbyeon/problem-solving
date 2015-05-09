
#include <stdio.h>

int isLeapYear(int year);
int whatDay(int year, int month, int day);

int main()
{
    int arrMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    char *arrDay[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    
    int date;
    int year,month,day;

    scanf("%d",&date);

    while ( date!=-1)
    {
        // 초기화;
        year = 2000;
        month = 1;
        day = 1;

        date++;

        // 년도 증가;
        while ( date > (isLeapYear(year)?366:365) )
        {
            // 윤년(366일)과 평년(365일);
            if ( isLeapYear(year) )     date -= 366;
            else                        date -= 365;

            year++;
        }

        // 월 증가;
        while ( date > (isLeapYear(year) && month==2 ? arrMonth[month]+1 : arrMonth[month]) )
        {
            if ( isLeapYear(year) && month==2 )
                date -= arrMonth[month]+1;
            else
                date -= arrMonth[month];
            month++;
        }

        // 일 수;
        day = date;

        printf("%d-",year);
        if ( month<10 ) printf("0");
        printf("%d-",month);
        if ( day<10 ) printf("0");
        printf("%d ",day);
        printf("%s\n",arrDay[whatDay(year,month,day)]);

        scanf("%d",&date);
    }

}

int isLeapYear(int year)
{
    if ( (year%4 == 0 && year%100 != 0) || year%400 == 0 )
        return 1;
    return 0;
}

int whatDay(int year, int month, int day)
{
    int yearFirst, yearSecond;
    int itsDay;

    if ( month==1 || month==2 )
    {
        month = month==1 ? 13:14;
        year--;
    }

    yearFirst = year/100;
    yearSecond = year%100;

    // w=[21a/4]+[5b/4]+[26(c+1)/10]+d-1 
    itsDay = (21*yearFirst/4)+(5*yearSecond/4)+(26*(month+1)/10)+day-1;

    return itsDay%7;
}