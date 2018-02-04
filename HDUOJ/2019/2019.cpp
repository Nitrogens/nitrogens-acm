#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int num[105];
int main(void)
{
	int n, m, i, j, temp, flag;
	
	scanf("%d %d", &n, &m);
	
	while(n!=0 && m!=0)
	{
		memset(num, 0, sizeof(num));
		flag = 0;
		for(i=0; i<=n; i++)
		{
			scanf("%d", &num[i]);
			if(m<num[i] && flag == 0)
			{
				num[i+1] = num[i];
				num[i] = m;
				flag = 1;
				i++;
				continue;
			}
		}
		
		for(i=0; i<=n; i++)
		{
			if(i==0)
				printf("%d", num[i]);
			else
				printf(" %d", num[i]);
		}
		
		printf("\n");
		
		scanf("%d %d", &n, &m);
	}
	
	return 0;
}
