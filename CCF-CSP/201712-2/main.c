#include <stdio.h>
int single_digit(int input);
int main(void)
{
	int n, k, i;
	scanf("%d %d", &n, &k);
	
	int status[n];	//0表示出局
	int sum = n;
	int temp = 0;
	
	for(i=0; i<n; i++)
	{
		status[i] = 1;
	}
	
	while(sum > 1)
	{
		for(i=0; i<n; i++)
		{
			if(status[i] == 0)
			{
				continue;
			}
			
			temp++;
			
			if( (temp % k == 0) || (single_digit(temp) == k) )
			{
				status[i] = 0;
				sum--;
			}
			
			if(sum == 1)
			{
				break;
			}
		}
	}
	
	for(i=0; i<n; i++)
	{
		if(status[i] == 1)
		{
			temp = i + 1;
			break;
		}
	}
	
	printf("%d", temp);
	
	return 0;
}
int single_digit(int input){
	
	int temp, i, j;
	int digit = 0;
	
	temp = input;
	
	while(temp != 0)
	{
		digit++;
		temp /= 10;
	}
	
	for(i=digit-1; i>=1; i--)
	{
		temp = 1;
		for(j=1; j<=i; j++)
		{
			temp *= 10;
		}
		
		input %= temp;
	}
	
	return input;
}
