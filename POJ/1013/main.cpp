#include <cstdio>
#include <cstring>

int main(void)
{
	int n, i, j, k;
	
	//存储读入的左右称量的硬币以及天平的状态
	char left[3][7], right[3][7], status[3][5];
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		//对三个数组进行清零
		memset(left, '\0', sizeof(left));
		memset(right, '\0', sizeof(right));
		memset(status, '\0', sizeof(status));
		
		for(j=0; j<3; j++)
		{
			scanf("%s%s%s", left[j], right[j], status[j]);
		}
		
		for(j='A'; j<='L'; j++)
		{
			//假设假币为轻的
			for(k=0; k<3; k++)
			{
				switch(status[k][0])
				{
					case 'u':
						//天平右侧没有所假设的硬币的话，假设不成立
						if(strchr(right[k], j) == NULL)
						{
							/* 
							利用k = 4来跳出循环
							k = 3用于表明循环被完全执行，因此这里用了4
							*/
							k = 4;
						}
						break;
					case 'd':
						//天平左侧没有所假设的硬币的话，假设不成立
						if(strchr(left[k], j) == NULL)
						{
							k = 4;
						}
						break;
					case 'e':
						//平衡时，两侧都不应该有所假设的硬币，否则假设不成立 
						if(strchr(left[k], j) || strchr(right[k], j))
						{
							k = 4;
						}
						break;
				}
			}
			if(k == 3)	//循环被完全执行
			{
				printf("%c is the counterfeit coin and it is light.\n", j);
				break;
			}
			
			//假设假币为重的
			for(k=0; k<3; k++)
			{
				switch(status[k][0])
				{
					case 'u':
						if(strchr(left[k], j) == NULL)
						{
							k = 4;
						}
						break;
					case 'd':
						if(strchr(right[k], j) == NULL)
						{
							k = 4;
						}
						break;
					case 'e':
						if(strchr(left[k], j) || strchr(right[k], j))
						{
							k = 4;
						}
						break;
				}
			}
			if(k == 3)
			{
				printf("%c is the counterfeit coin and it is heavy.\n", j);
				break;
			}
		}
	}
	
	return 0;
}
