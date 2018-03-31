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
				//按照要求，行首补空格 
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
	用于将输入的值转换为十进制  
	str 表示输入的值（字符串形式）
	base 表示输入的值的进制 
	原理：按权展开 
*/ 
int convertToDec(char* str, int base)
{
	int i, result = 0, temp = 1;
	/*
		从左往右读也是可以的，但没有从右往左读方便 
		因为从左往右需要知道是第几位 
	*/ 
	for(i=strlen(str)-1; i>=0; i--)
	{
		//利用ASCII码的关系进行转换 
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
	用于将十进制数转化为任意进制，并以字符的形式压入栈中 
	number 表示十进制数
	base 表示要转化成的进制 
	方法：不断除以进制数，先得到的余数为末位，后得到的为前面的位，直到商为0宣告结束 
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
			//直接将字符压入栈中 
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
