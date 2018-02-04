#include <stdio.h>
int main(void)
{
	int T, S, i;
	
	scanf("%d", &T);
	
	if (T<=3500)
	{
		S = T;
	}
	else
	{
		for(i=3501; i<=154400; i++)
		{
			if ((i>3500)&&(i<=5000))
			{
				if (T == 0.97f*i+105)
				{
					break;
				}
			}
			
			if ((i>5000)&&(i<=8000))
			{
				if (T == 0.9f*i+455)
				{
					break;
				}
			}
			
			if ((i>8000)&&(i<=12500))
			{
				if (T == 0.8f*i+1255)
				{
					break;
				}
			}
			
			if ((i>12500)&&(i<=38500))
			{
				if (T == 0.75f*i+1880)
				{
					break;
				}
			}
			
			if ((i>38500)&&(i<=58500))
			{
				if (T == 0.7f*i+3805)
				{
					break;
				}
			}
			
			if ((i>58500)&&(i<=83500))
			{
				if (T == 0.65f*i+6730)
				{
					break;
				}
			}
			
			if (i>83500)
			{
				if (T == 0.55f*i+15080)
				{
					break;
				}
			}
		}
		
		S = i;
	}
	
	printf("%d", S);
	
	return 0;
}
