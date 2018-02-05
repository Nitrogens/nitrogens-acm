#include <cstdio>
#include <cstring>

//用于存储原始的钟表数据
char clock_original[10];
//每次操作，都要从原始数据中复制一份，再进行操作
char clock[10];
//为书写简便，将（编号）1~9移动封装成一个函数
void operation(int number, int frequency);
int main(void)
{
	int i, i1, i2, i3, i4, i5, i6, i7, i8, i9;
	
	for(i=1; i<=9; i++)
	{
		scanf("%d", &clock_original[i]);
	}
	
	/*
		对所有的移动进行枚举，每种移动最多进行三次
		也就是对每种移动的次数进行遍历 
		
		如果进行四次的话，等于没有进行 
	*/ 
	for(i1=0; i1<=3; i1++)
	for(i2=0; i2<=3; i2++)
	for(i3=0; i3<=3; i3++)
	for(i4=0; i4<=3; i4++)
	for(i5=0; i5<=3; i5++)
	for(i6=0; i6<=3; i6++)
	for(i7=0; i7<=3; i7++)
	for(i8=0; i8<=3; i8++)
	for(i9=0; i9<=3; i9++)
	{
		//每一种方案，都要从原始数据复制一份进行操作 
		memcpy(clock, clock_original, sizeof(clock_original));
		
		//对钟表进行移动操作 
		operation(1, i1);
		operation(2, i2);
		operation(3, i3);
		operation(4, i4);
		operation(5, i5);
		operation(6, i6);
		operation(7, i7);
		operation(8, i8);
		operation(9, i9);
		
		//如果所有的钟表都指向12 
		if(clock[1]+clock[2]+clock[3]+clock[4]+clock[5]+clock[6]+clock[7]+clock[8]+clock[9] == 0)
		{
			//从小到大输出，有几步移动就输出几步 
			for(i=1; i<=i1; i++)	printf("1 ");
			for(i=1; i<=i2; i++)	printf("2 ");
			for(i=1; i<=i3; i++)	printf("3 ");
			for(i=1; i<=i4; i++)	printf("4 ");
			for(i=1; i<=i5; i++)	printf("5 ");
			for(i=1; i<=i6; i++)	printf("6 ");
			for(i=1; i<=i7; i++)	printf("7 ");
			for(i=1; i<=i8; i++)	printf("8 ");
			for(i=1; i<=i9; i++)	printf("9 ");
			
			break;
		}
		
	}
	
	return 0;
}

//number表示移动编号，frequency表示操作次数 
void operation(int number, int frequency)
{
	int i;
	for(i=0; i<frequency; i++)
		switch(number)
		{
			case 1:
				clock[1] = (clock[1] + 1) % 4;
				clock[2] = (clock[2] + 1) % 4;
				clock[4] = (clock[4] + 1) % 4;
				clock[5] = (clock[5] + 1) % 4;
				break;
			case 2:
				clock[1] = (clock[1] + 1) % 4;
				clock[2] = (clock[2] + 1) % 4;
				clock[3] = (clock[3] + 1) % 4;
				break;
			case 3:
				clock[2] = (clock[2] + 1) % 4;
				clock[3] = (clock[3] + 1) % 4;
				clock[5] = (clock[5] + 1) % 4;
				clock[6] = (clock[6] + 1) % 4;
				break;
			case 4:
				clock[1] = (clock[1] + 1) % 4;
				clock[4] = (clock[4] + 1) % 4;
				clock[7] = (clock[7] + 1) % 4;
				break;
			case 5:
				clock[2] = (clock[2] + 1) % 4;
				clock[4] = (clock[4] + 1) % 4;
				clock[5] = (clock[5] + 1) % 4;
				clock[6] = (clock[6] + 1) % 4;
				clock[8] = (clock[8] + 1) % 4;
				break;
			case 6:
				clock[3] = (clock[3] + 1) % 4;
				clock[6] = (clock[6] + 1) % 4;
				clock[9] = (clock[9] + 1) % 4;
				break;
			case 7:
				clock[4] = (clock[4] + 1) % 4;
				clock[5] = (clock[5] + 1) % 4;
				clock[7] = (clock[7] + 1) % 4;
				clock[8] = (clock[8] + 1) % 4;
				break;
			case 8:
				clock[7] = (clock[7] + 1) % 4;
				clock[8] = (clock[8] + 1) % 4;
				clock[9] = (clock[9] + 1) % 4;
				break;
			case 9:
				clock[5] = (clock[5] + 1) % 4;
				clock[6] = (clock[6] + 1) % 4;
				clock[8] = (clock[8] + 1) % 4;
				clock[9] = (clock[9] + 1) % 4;
				break;
		}
}
