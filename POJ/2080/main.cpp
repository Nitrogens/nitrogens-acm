#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isLeapYear(int year);
int main(void)
{
	int input, year, month, day, i, weekday, backup;
	
	//查表法 
	int monthsOfLeapYear[12]
	{
		31,
		31+29,
		31+29+31,
		31+29+31+30,
		31+29+31+30+31,
		31+29+31+30+31+30,
		31+29+31+30+31+30+31,
		31+29+31+30+31+30+31+31,
		31+29+31+30+31+30+31+31+30,
		31+29+31+30+31+30+31+31+30+31,
		31+29+31+30+31+30+31+31+30+31+30,
		31+29+31+30+31+30+31+31+30+31+30+31
	};
	
	int monthsOfNormalYear[12]
	{
		31,
		31+28,
		31+28+31,
		31+28+31+30,
		31+28+31+30+31,
		31+28+31+30+31+30,
		31+28+31+30+31+30+31,
		31+28+31+30+31+30+31+31,
		31+28+31+30+31+30+31+31+30,
		31+28+31+30+31+30+31+31+30+31,
		31+28+31+30+31+30+31+31+30+31+30,
		31+28+31+30+31+30+31+31+30+31+30+31
	};
	
	string weekDay[7]
	{
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};
	
	while(scanf("%d", &input) != EOF)
	{
		year = 0;
		month = 0;
		day = 0;
		if(input == -1)
			break;
		//从1999年12月31日开始计算的话，比较方便，因此当作从这天开始，input需要加1 
		input++;
		backup = input;
		while(true)
		{
			/*
				前两个if都是处理year，不断减去每一年的天数 
			*/
			if(isLeapYear(year) && input > 366)
			{
				input -= 366;
				year++;
				continue;
			}
			else if(!isLeapYear(year) && input > 365)
			{
				input -= 365;
				year++;
				continue;
			}
			else
			{
				//开始处理月份和日期 
				for(i=0; i<12; i++)
				{
					if(isLeapYear(year))
					{
						/* 
							这里必须用<=, 而不是<, 否则会出现类似 2001-01-00 这类的错误答案
							正确答案是2000-12-31
							往下以此类推 
						*/ 
						if(input <= monthsOfLeapYear[i])
							break;
					}
					else
					{
						if(input <= monthsOfNormalYear[i])
							break;
					}
				}
				month = i+1;
				if(isLeapYear(year))
				{
					if(i > 0)
						day = input - monthsOfLeapYear[i-1];
					else
						day = input;	//1月
				}
				else
				{
					if(i > 0)
						day = input - monthsOfNormalYear[i-1];
					else
						day = input;	//1月
				}
				break;
			}
			
		}
		weekday = (backup % 7 + 5) % 7;	//计算星期，基准时间是1999年12月31日 星期五 
		printf("%04d-%02d-%02d ", 2000+year, month, day);	//注意按照格式输出 
		cout<<weekDay[weekday]<<endl;
	}
	
	return 0;
}
bool isLeapYear(int year)
{
	//闰年的判断，4年一闰，100年不闰，400年又闰 
	return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
}
