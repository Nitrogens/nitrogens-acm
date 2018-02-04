#include <stdio.h>
int abs(int input);
int main(void)
{
	int n, i, temp;
	scanf("%d", &n);
	
	int number[n];
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &number[i]);
	}
	
	for(i=0; i<n-1; i++)
	{
		if(i==0)
		{
			temp = abs(number[i] - number[i+1]);
		}
		else
		{
			if(abs(number[i] - number[i+1]) > temp)
				temp = abs(number[i] - number[i+1]);
		}
	}
	
	printf("%d", temp);
	
	return 0;
}
int abs(int input)
{
	return (input<0)?(-input):input;
}
