#include <stdio.h>
#include <math.h>
int main(void)
{
	int input, k, temp;
	int digit = 0;	//���ֵ�λ��
	
	scanf("%d", &input);
	
	temp = input;
	
	while(temp > 0)	//���ϳ���10����N��λ�� 
	{
		temp /= 10;
		digit++;
	}
	
	int digit_container[digit];
		
	temp = input;
		
	for(k=1; k<=digit; k++)	//ȡ��N��ÿһλ��һ�������� 
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
