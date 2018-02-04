#include <stdio.h>
int main(void)
{
	int input, a, b, c, result;
	scanf("%d", &input);
	
	input /= 10;
	
	a = input / 5;
	b = input % 5 / 3;
	c = input - a*5 - b*3;
	
	result = a*7 + b*4 + c;
	
	printf("%d", result);
	
	return 0;
}
