#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* 函数day_of_year和month_dat*/
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);


/* day_of_year: 日期转换成某年中第几天 */
int day_of_year(int year, int month, int day)
{
	int i,leep;
	leep = year %4 == 0 && year%100 != 0 || year %400 == 0;
	if(month < 1 || month > 12){
		return -1;
	}

	for(i =1; i< month; i++){
		day += daytab[leep][i];
	}

	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leep;
	if(year < 1){
		*pmonth = -1;
		*pday = -1;
		return;
	}
	leep = year %4 == 0 && year%100 != 0 || year %400 == 0;
	for(i =1; i<=12 && yearday > daytab[leep][i]; i++){
		yearday -= daytab[leep][i];
	}

	if(i > 12 && yearday > daytab[leep][12]){
		*pmonth = -1;
		*pday = -1;
	}else{
		*pmonth = i;
		*pday = yearday;
	}
}