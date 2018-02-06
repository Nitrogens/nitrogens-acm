#include <cstdio>
#include <cstring>

void Hanoi(int N, char label_a[2], char label_b[2], char label_c[2], int top_num);

int main(void)
{
	//盘子的总数 
	int N;
	//三个容器的名称 
	char label_a[2], label_b[2], label_c[2];
	
	while(scanf("%d %s %s %s", &N, label_a, label_b, label_c) != EOF)
	{
		Hanoi(N, label_a, label_b, label_c, 1);
	}
	
	return 0;
}

/*
N表示盘子的总数 
三个label分别表示起始容器、中间容器和终点容器
（为简便，分别用a, b, c代指） 
top_num表示最顶层的盘子编号 
*/ 
void Hanoi(int N, char label_a[2], char label_b[2], char label_c[2], int top_num)
{
	//只有一个盘子的话，直接从a移到c即可 
	if(N == 1)
	{
		printf("%d:%c->%c\n", top_num, label_a[0], label_c[0]);
		return;
	}
	
	//递归调用，先将N-1个盘子移到b 
	Hanoi(N-1, label_a, label_c, label_b, top_num);
	
	//最后一个盘子，直接从a移到c即可 
	printf("%d:%c->%c\n", N, label_a[0], label_c[0]);
	
	//再将b中的盘子移到c中 
	Hanoi(N-1, label_b, label_a, label_c, top_num);
}
