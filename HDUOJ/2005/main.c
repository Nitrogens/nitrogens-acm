#include <stdio.h>
int main(void)
{
	int year, month, day, i;
	int sum = 0;
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int leap_days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	while(scanf("%d/%d/%d", &year, &month, &day) != EOF)
	{
		if( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			for(i=0; i<month; i++)
			{
				if(i != month-1)
				{
					sum += leap_days[i];
				}
				else
				{
					sum += day;
				}
			}
		}
		else
		{
			for(i=0; i<month; i++)
			{
				if(i != month-1)
				{
					sum += days[i];
				}
				else
				{
					sum += day;
				}
			}
		}
		
		printf("%d\n", sum);
		
		sum = 0;
	}
	
	return 0;
}
