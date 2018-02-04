#include <stdio.h>
int main(void)
{
	char ch_a, ch_b, ch_c, temp;
	
	while(scanf("%c %c %c", &ch_a, &ch_b, &ch_c) != EOF)
	{
		if (ch_a > ch_b)
		{
			temp = ch_b;
			ch_b = ch_a;
			ch_a = temp;
		}
		
		if (ch_b > ch_c)
		{
			temp = ch_c;
			ch_c = ch_b;
			ch_b = temp;
		}
		
		if (ch_a > ch_b)
		{
			temp = ch_b;
			ch_b = ch_a;
			ch_a = temp;
		}
		
		printf("%c %c %c\n", ch_a, ch_b, ch_c);
		
		getchar();
	}
	
	return 0;
}
