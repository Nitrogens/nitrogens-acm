#include <stdio.h>
int main(void)
{
	int m, n, i, j, k, temp;
	int status;
	
	scanf("%d %d", &m, &n);
	
	int martix[m][n];
	
	int lingroupsum[m][m/3+1], colgroupsum[n][n/3+1];
	int lingroupstart[m][m/3+1], lingroupend[m][m/3+1], colgroupstart[n][n/3+1], colgroupend[n][n/3+1];
	int lingroupnum[m], colgroupnum[n];
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &martix[i][j]);
		}
	}
	
	for(i=0; i<m; i++)
	{
		lingroupnum[i] = 0;
		for(j=0; j<m/3+1; j++)
		{
			lingroupsum[i][j] = 1;
		}
	}
	
	for(i=0; i<n; i++)
	{
		colgroupnum[i] = 0;
		for(j=0; j<n/3+1; j++)
		{
			colgroupsum[i][j] = 1;
		}
	}
	
	temp = martix[0][0];
	
	for(i=0; i<m; i++)
	{
		for(j=1; j<n; j++)
		{
			if(martix[i][j] == temp)
			{
				status = 1;
				if(lingroupsum[i][lingroupnum[i]] == 1)
					lingroupstart[i][lingroupnum[i]] = j-1;
				lingroupsum[i][lingroupnum[i]]++;
			}
			else
			{
				if(status == 1)
				{
					lingroupend[i][lingroupnum[i]] = j-1;
					lingroupnum[i]++;
				}
				status = 0;
				temp = martix[i][j];
			}
			if((status == 1)&&(j == n-1))
			{
				lingroupnum[i]++;
			}
		}
		temp = martix[i+1][0];
	}
	
	temp = martix[0][0];
	
	for(j=0; j<n; j++)
	{
		for(i=1; i<m; i++)
		{
			if(martix[i][j] == temp)
			{
				status = 1;
				if(colgroupsum[j][colgroupnum[j]] == 1)
					colgroupstart[j][colgroupnum[j]] = j-1;
				colgroupsum[j][colgroupnum[j]]++;
			}
			else
			{
				if(status == 1)
				{
					colgroupend[j][colgroupnum[j]] = j-1;
					colgroupnum[j]++;
				}
				status = 0;
				temp = martix[i][j];
			}
			if((status == 1)&&(i == m-1))
			{
				colgroupnum[j]++;
			}
		}
		temp = martix[0][j+1];
	}
	
	for(k=0; k<m; k++)
	{
		for(i=0; i<lingroupnum[k]; i++)
		{
			if(lingroupend[k][i] - lingroupstart[k][i] >= 2)
			{
				for(j=lingroupstart[k][i]; j<=lingroupend[k][i]; j++)
				{
					martix[k][j] = 0;
				}
			}
		}
	}
	
	for(k=0; k<n; k++)
	{
		for(i=0; i<colgroupnum[k]; i++)
		{
			if(colgroupend[k][i] - colgroupstart[k][i] >= 2)
			{
				for(j=colgroupstart[k][i]; j<=colgroupend[k][i]; j++)
				{
					martix[j][k] = 0;
				}
			}
		}
	}
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			if(j == n-1)
			{
				printf("%d", martix[i][j]);
			}
			else
			{
				printf("%d ", martix[i][j]);
			}
		}
		if(i != m-1)
		{
			printf("\n");
		}
	}
	
	return 0;
}
