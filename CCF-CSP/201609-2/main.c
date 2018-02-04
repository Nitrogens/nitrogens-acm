#include <stdio.h>
int main(void)
{
	int N, i, j, number, temp, seats[100], tickets[5];
	int row = 0;
	int column = 0;
	scanf("%d", &N);
	
	for(i=0; i<100; i++)
	{
		seats[i] = 0;
	}
	
	for(i=0; i<N; i++)
	{
		scanf("%d", &number);
		
		for(j=0; j<20; j++)
		{
			if(seats[j*5+5-number] == 1)
			{
				row++;
			}
			if(seats[j*5+5-number] == 0)
			{
				break;
			}
		}
		
		if (row != 20)
		{
			for(j=0; j<5; j++)
			{
				if(seats[row*5+j] == 0)
				{
					break;
				}
				else
				{
					column++;
				}
			}
			
			for(j=column; j<column+number; j++)
			{
				seats[row*5+j] = 1;
				tickets[j-column] = row*5+j+1;
			}
			
			for(j=0; j<number; j++)
			{
				if(j == number-1)
				{
					printf("%d", tickets[j]);
				}
				else
				{
					printf("%d ", tickets[j]);
				}
			}
			
			if(i != N-1)
			{
				printf("\n");
			}
			
		}
		else
		{
			temp = number;
			for(j=0; j<100; j++)
			{
				if(seats[j] == 0)
				{
					seats[j] = 1;
					tickets[number-temp] = j+1;
					temp--;
				}
				if(temp == 0)
				{
					break;
				}
			}
			
			for(j=0; j<number; j++)
			{
				if(j == number-1)
				{
					printf("%d", tickets[j]);
				}
				else
				{
					printf("%d ", tickets[j]);
				}
			}
			
			if(i != N-1)
			{
				printf("\n");
			}
		}
		
		row = 0;
		column = 0;
		
	}
	
	return 0;
}
