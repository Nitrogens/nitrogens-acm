#include <stdio.h>
int main(void)
{
	int m, n, i, j;
	scanf("%d %d", &m, &n);
	
	short int martix[m][n];	//用int的话，所有元素的大小之和会超过编译器的stack导致崩溃 
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%hd", &martix[i][j]);
		}
	}
	
	for(i=n-1; i>=0; i--)
	{
		for(j=0; j<m; j++)
		{
			if(j == m-1)
			{
				printf("%hd", martix[j][i]);
			}
			else
			{
				printf("%hd ", martix[j][i]);
			}
		}
		if(i>0)
		{
			printf("\n");
		}
	}
	
	return 0;
}
