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
	
	//��� 
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
		//��1999��12��31�տ�ʼ����Ļ����ȽϷ��㣬��˵��������쿪ʼ��input��Ҫ��1 
		input++;
		backup = input;
		while(true)
		{
			/*
				ǰ����if���Ǵ���year�����ϼ�ȥÿһ������� 
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
				//��ʼ�����·ݺ����� 
				for(i=0; i<12; i++)
				{
					if(isLeapYear(year))
					{
						/* 
							���������<=, ������<, ������������ 2001-01-00 ����Ĵ����
							��ȷ����2000-12-31
							�����Դ����� 
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
						day = input;	//1��
				}
				else
				{
					if(i > 0)
						day = input - monthsOfNormalYear[i-1];
					else
						day = input;	//1��
				}
				break;
			}
			
		}
		weekday = (backup % 7 + 5) % 7;	//�������ڣ���׼ʱ����1999��12��31�� ������ 
		printf("%04d-%02d-%02d ", 2000+year, month, day);	//ע�ⰴ�ո�ʽ��� 
		cout<<weekDay[weekday]<<endl;
	}
	
	return 0;
}
bool isLeapYear(int year)
{
	//������жϣ�4��һ��100�겻��400������ 
	return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
}
