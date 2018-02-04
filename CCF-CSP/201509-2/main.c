#include <stdio.h>
int main(void)
{
	int year, day;
	scanf("%d %d", &year, &day);
	
	if( ( (year % 4 == 0) && (year % 100 != 0) ) || (year % 400 == 0) )
	{
		if ( day <= 31 )
		{
			printf("%d\n%d", 1, day);
		}
		else if ( day <= 60 )
		{
			printf("%d\n%d", 2, day-31);
		}
		else if ( day <= 91 )
		{
			printf("%d\n%d", 3, day-60);
		}
		else if ( day <= 121 )
		{
			printf("%d\n%d", 4, day-91);
		}
		else if ( day <= 152 )
		{
			printf("%d\n%d", 5, day-121);
		}
		else if ( day <= 182 )
		{
			printf("%d\n%d", 6, day-152);
		}
		else if ( day <= 213 )
		{
			printf("%d\n%d", 7, day-182);
		}
		else if ( day <= 244 )
		{
			printf("%d\n%d", 8, day-213);
		}
		else if ( day <= 274 )
		{
			printf("%d\n%d", 9, day-244);
		}
		else if ( day <= 305 )
		{
			printf("%d\n%d", 10, day-274);
		}
		else if ( day <= 335 )
		{
			printf("%d\n%d", 11, day-305);
		}
		else if ( day <= 366 )
		{
			printf("%d\n%d", 12, day-335);
		}
	}
	else
	{
		if ( day <= 31 )
		{
			printf("%d\n%d", 1, day);
		}
		else if ( day <= 59 )
		{
			printf("%d\n%d", 2, day-31);
		}
		else if ( day <= 90 )
		{
			printf("%d\n%d", 3, day-59);
		}
		else if ( day <= 120 )
		{
			printf("%d\n%d", 4, day-90);
		}
		else if ( day <= 151 )
		{
			printf("%d\n%d", 5, day-120);
		}
		else if ( day <= 181 )
		{
			printf("%d\n%d", 6, day-151);
		}
		else if ( day <= 212 )
		{
			printf("%d\n%d", 7, day-181);
		}
		else if ( day <= 243 )
		{
			printf("%d\n%d", 8, day-212);
		}
		else if ( day <= 273 )
		{
			printf("%d\n%d", 9, day-243);
		}
		else if ( day <= 304 )
		{
			printf("%d\n%d", 10, day-273);
		}
		else if ( day <= 334 )
		{
			printf("%d\n%d", 11, day-304);
		}
		else if ( day <= 365 )
		{
			printf("%d\n%d", 12, day-334);
		}
	}
	
	return 0;
}
