#include <cstdio>
#include <cstring>

int n;
//用于存储每一个皇后的位置
int place[300];
int abs(int a);
void solve(int start_line);

int main(void)
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		
		solve(0);
	}
	
	return 0;
}
//求绝对值的函数
int abs(int a)
{
	return (a < 0)?(-a):a;
}

/*
用于求解的函数 
start_line表示求解为start_line这一行的方案
*/ 
void solve(int start_line)
{
	int i, j;
	
	//如果最后一行已经求解完毕，则输出结果，并结束递归
	if(start_line == n)
	{
		for(i=0; i<n; i++)
		{
			printf("%d ", place[i] + 1);
		}
		printf("\n");
		return;
	}
	
	//i用于扫描每一列，即遍历start_line这一行的所有情况
	for(i=0; i<n; i++)
	{
		//对前面已经安排好的皇后进行遍历，从而判断这个位置(i)是否可行
		for(j=0; j<start_line; j++)
		{
			/*
			||前面的条件判断新皇后与已经安排好的皇后是否在同一列
			||后面的条件判断新皇后与已经安排好的皇后是否在正方形的一条对角线上 
			（通过横纵距离是否相等来判断）
			不满足题目条件的方案要被否决
			*/ 
			if(place[j] == i || abs(place[j] - i) == abs(j - start_line))
			{
				break;
			}
		}
		
		//判断是否满足题中条件
		if(j == start_line)
		{
			//记录新皇后的位置
			place[start_line] = i;
			//对下一行进行求解
			solve(start_line+1);
		}
	}
}
