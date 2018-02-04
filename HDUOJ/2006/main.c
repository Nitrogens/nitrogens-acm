#include <stdio.h>
int main(void)
{
	int n, i, temp;
	int result = 1;
	
	while(scanf("%d", &n) != EOF)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &temp);
			if(temp % 2 != 0)
			{
				result *= temp;
			}
		}
		
		printf("%d\n", result);
		
		result = 1;
	}
	
	return 0;
}
