#include <stdio.h>
#include <string.h>
int main(void)
{
	char lincontent[10000];
	int count = 0;
	
	gets(lincontent);
	
	while(strcmp(lincontent, "#") != 0)
	{
		
		if(strtok(lincontent, " ") != NULL)
		{
			count++;
		}
		else
		{
			continue;
		}
		
		while(strtok(NULL, " ") != NULL)
		{
			count++;
		}
		
		printf("%d\n", count);
		
		count = 0;
		
		gets(lincontent);
	}
	
	return 0;
}
