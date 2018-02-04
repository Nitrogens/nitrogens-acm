#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int number[105];
int main(void)
{
	int n, i, temp, pos;
	scanf("%d", &n);
	
	while(n != 0)
	{
		memset(number, 0, sizeof(number));
		for(i=0; i<n; i++)
		{
			scanf("%d", &number[i]);
		}
		pos = 0;
		temp = number[0];
		for(i=0; i<n; i++)
		{
			if(number[i]<temp)
			{
				temp = number[i];
				pos = i;
			}
		}
		
		temp = number[0];
		number[0] = number[pos];
		number[pos] = temp;
		
		for(i=0; i<n; i++)
		{
			if(i==0)
				printf("%d", number[i]);
			else
				printf(" %d", number[i]);
		}
		printf("\n");
		scanf("%d", &n);
	}
	
	return 0;
}
