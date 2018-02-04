#include <stdio.h>
#include <string.h>
int main(void)
{
	int T, i, j, temp, count, flag, flag2;
	char strA[1005], strB[1005];
	int A[1005], B[1005];
	scanf("%d", &T);
	
	for(i=0; i<T; i++)
	{
		memset(strA, '\0', 1005*sizeof(char));
		memset(strB, '\0', 1005*sizeof(char));
		memset(A, 0, 1005*sizeof(int));
		memset(B, 0, 1005*sizeof(int));
		
		count = 0;
		
		scanf("%s %s", strA, strB);
		
		for(j=strlen(strA)-1; j>=0; j--)
		{
			A[strlen(strA)-1-j] = strA[j] - '0';
		}
		
		for(j=strlen(strB)-1; j>=0; j--)
		{
			B[strlen(strB)-1-j] = strB[j] - '0';
		}
		
		if(strlen(strA) > strlen(strB))
		{
			flag2 = 1;
			for(j=0; j<strlen(strA); j++)
			{
				count++;
				temp = A[j] + B[j];
				A[j] = temp % 10;
				A[j+1] += temp / 10;
			}
		}
		else
		{
			flag2 = 2;
			for(j=0; j<strlen(strB); j++)
			{
				count++;
				temp = A[j] + B[j];
				B[j] = temp % 10;
				B[j+1] += temp / 10;
			}
		}
		
		if(temp / 10 != 0)
		{
			count++;
		}
		
		if(i > 0)
		{
			printf("\n");
		}
		
		printf("Case %d:\n", i+1);
		
		flag = 0;
		
		for(j=0; j<strlen(strA); j++)
		{
			if(strA[j] != '0')
			{
				flag = 1;
			}
			if(strA[j] == '0' && flag == 0 && strlen(strA) > 1)
			{
				continue;
			}
			printf("%c", strA[j]);
		}
		
		printf(" + ");
		
		flag = 0;
		
		for(j=0; j<strlen(strB); j++)
		{
			if(strB[j] != '0')
			{
				flag = 1;
			}
			if(strB[j] == '0' && flag == 0 && strlen(strB) > 1)
			{
				continue;
			}
			printf("%c", strB[j]);
		}
		
		printf(" = ");
		
		flag = 0;
		
		if(flag2 == 1)
		{
			for(j=count-1; j>=0; j--)
			{
				if(A[j] != 0)
				{
					flag = 1;
				}
				if(A[j] == 0 && flag == 0 && count > 1)
				{
					continue;
				}
				printf("%d", A[j]);
			}
		}
		else
		{
			for(j=count-1; j>=0; j--)
			{
				if(B[j] != 0)
				{
					flag = 1;
				}
				if(B[j] == 0 && flag == 0 && count > 1)
				{
					continue;
				}
				printf("%d", B[j]);
			}
		}
		
		printf("\n");
	}
	
	return 0;
}
