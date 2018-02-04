#include <stdio.h>
int main(void)
{
	int m, n, i;
	int x = 0;
	int y = 0;
	int temp_x, temp_y;
	
	while(scanf("%d %d", &m, &n) != EOF)
	{
		if(m > n)
		{
			for(i=n; i<=m; i++)
			{
				if(i % 2 == 0)
				{
					x += i*i;
				}
				else
				{
					y += i*i*i;
				}
			}
		}
		else
		{
			for(i=m; i<=n; i++)
			{
				if(i % 2 == 0)
				{
					x += i*i;
				}
				else
				{
					y += i*i*i;
				}
			}
		}
		
		printf("%d %d\n", x, y);
		
		x = 0;
		y = 0;
	}
	
	return 0;
}
