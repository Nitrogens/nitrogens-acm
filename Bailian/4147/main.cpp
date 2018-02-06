#include <cstdio>
#include <cstring>

void Hanoi(int N, char label_a[2], char label_b[2], char label_c[2], int top_num);

int main(void)
{
	//���ӵ����� 
	int N;
	//�������������� 
	char label_a[2], label_b[2], label_c[2];
	
	while(scanf("%d %s %s %s", &N, label_a, label_b, label_c) != EOF)
	{
		Hanoi(N, label_a, label_b, label_c, 1);
	}
	
	return 0;
}

/*
N��ʾ���ӵ����� 
����label�ֱ��ʾ��ʼ�������м��������յ�����
��Ϊ��㣬�ֱ���a, b, c��ָ�� 
top_num��ʾ�������ӱ�� 
*/ 
void Hanoi(int N, char label_a[2], char label_b[2], char label_c[2], int top_num)
{
	//ֻ��һ�����ӵĻ���ֱ�Ӵ�a�Ƶ�c���� 
	if(N == 1)
	{
		printf("%d:%c->%c\n", top_num, label_a[0], label_c[0]);
		return;
	}
	
	//�ݹ���ã��Ƚ�N-1�������Ƶ�b 
	Hanoi(N-1, label_a, label_c, label_b, top_num);
	
	//���һ�����ӣ�ֱ�Ӵ�a�Ƶ�c���� 
	printf("%d:%c->%c\n", N, label_a[0], label_c[0]);
	
	//�ٽ�b�е������Ƶ�c�� 
	Hanoi(N-1, label_b, label_a, label_c, top_num);
}
