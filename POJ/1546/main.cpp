#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
int convertToDec(char* str, int base);
stack<char> convertToResult(int number, int base);
int main(void)
{
	char input[8];
	int from, to, temp, i;
	stack<char> output;
	
	while(scanf("%s %d %d", input, &from, &to) != EOF)
	{
		temp = convertToDec(input, from);
		output = convertToResult(temp, to);
		
		if(output.size() > 7)
		{
			cout<<"  ERROR"<<endl;
		}
		else
		{
			for(i=0; i<7-output.size(); i++)
			{
				//����Ҫ�����ײ��ո� 
				cout<<" ";
			}
			while(!output.empty())
			{
				cout<<output.top();
				output.pop();
			}
			cout<<endl;
		}
	}
	
	return 0;
}
/*
	���ڽ������ֵת��Ϊʮ����  
	str ��ʾ�����ֵ���ַ�����ʽ��
	base ��ʾ�����ֵ�Ľ��� 
	ԭ����Ȩչ�� 
*/ 
int convertToDec(char* str, int base)
{
	int i, result = 0, temp = 1;
	/*
		�������Ҷ�Ҳ�ǿ��Եģ���û�д������������ 
		��Ϊ����������Ҫ֪���ǵڼ�λ 
	*/ 
	for(i=strlen(str)-1; i>=0; i--)
	{
		//����ASCII��Ĺ�ϵ����ת�� 
		if(str[i]>='0' && str[i] <='9')
		{
			result += (str[i]-48)*temp;
			temp *= base;
		}
		else if(str[i]>='A' && str[i] <='F')
		{
			result += (str[i]-55)*temp;
			temp *= base;
		}
		else
			continue;
	}
	
	return result;
}
/* 
	���ڽ�ʮ������ת��Ϊ������ƣ������ַ�����ʽѹ��ջ�� 
	number ��ʾʮ������
	base ��ʾҪת���ɵĽ��� 
	���������ϳ��Խ��������ȵõ�������Ϊĩλ����õ���Ϊǰ���λ��ֱ����Ϊ0������� 
*/ 
stack<char> convertToResult(int number, int base)
{
	char bit;
	int temp, num = number;
	stack<char> result;
	while(num)
	{
		temp = num % base;
		if(temp >= 0 && temp <= 9)
		{
			//ֱ�ӽ��ַ�ѹ��ջ�� 
			result.push(temp+48);
		}
		else
		{
			result.push(temp+55);
		}
		num /= base;
	}
	
	return result;
}
