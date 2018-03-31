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
		input++;
		backup = input;
		while(true)
		{
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
				for(i=0; i<12; i++)
				{
					if(isLeapYear(year))
					{
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
						day = input;
				}
				else
				{
					if(i > 0)
						day = input - monthsOfNormalYear[i-1];
					else
						day = input;
				}
				break;
			}
			
		}
		weekday = (backup % 7 + 5) % 7;
		printf("%04d-%02d-%02d ", 2000+year, month, day);
		cout<<weekDay[weekday]<<endl;
	}
	
	return 0;
}
bool isLeapYear(int year)
{
	return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
}
