#include <stdio.h>
int main(void)
{
	int m, n, i, j;
	scanf("%d %d", &m, &n);
	
	short int martix[m][n];	//��int�Ļ�������Ԫ�صĴ�С֮�ͻᳬ����������stack���±��� 
	
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
