#include <stdio.h>
int abs(int input);

int main(void)
{
	int N, i, j, temp, result;
	scanf("%d", &N);
	
	int number[N];
	
	for(i=0; i<N; i++)
	{
		scanf("%d", &number[i]);
	}
	
	for(i=0; i<N; i++)
	{
		for(j=i+1; j<N; j++)
		{
			temp = abs(number[i] - number[j]);
			if((i==0)&&(j==1))
			{
				result = temp;
			}
			else
			{
				if(temp < result)
				{
					result = temp;
				}
			}
		}
	}
	
	printf("%d", result);
	
	return 0;
}

int abs(int input)
{
	return (input<0)?(-input):input;
}
