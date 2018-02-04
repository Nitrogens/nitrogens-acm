#include <stdio.h>
#include <math.h>
int main(void)
{
	int input, k, temp;
	int digit = 0;	//数字的位数
	
	scanf("%d", &input);
	
	temp = input;
	
	while(temp > 0)	//不断除以10计算N的位数 
	{
		temp /= 10;
		digit++;
	}
	
	int digit_container[digit];
		
	temp = input;
		
	for(k=1; k<=digit; k++)	//取出N的每一位到一个数组中 
	{
		digit_container[k-1] = temp / (int)pow(10, digit-k);
		temp -= digit_container[k-1] * (int)pow(10, digit-k);
	}
	
	temp = 0;
	for(k=1; k<=digit; k++)
	{
		temp += digit_container[k-1];
	}
	
	printf("%d", temp);
	
	return 0;
}
