#include<iostream>
using namespace std;
/*创建英雄的结构体*/
struct hero 
{
	string name;
	int age;
	string male;
};
/*对结构体进行赋值*/
void allocatespcae(hero harr[], int len)
{
	string nameseed[] = { "张飞","关羽","赵云","刘备","貂蝉" };
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
	{
		
		 harr[i].name="三国-";
		 harr[i].name += nameseed[i];
		 harr[i].age =rand()%10+25;
		 harr[i].male="male";
	}
}
/*冒牌排序*/
void Bubblesort(hero harr[],int len) 
{
	for (int i = 0; i <len ; i++)
	{
		
		for (int j = 0; j < len-i-1; j++)
		{
			if (harr[j].age>harr[j+1].age)
			{
				hero temp = harr[j];
				harr[j] = harr[j + 1];
				harr[j + 1] = temp;
			}
		}
	}
};
/*输出内容*/
void printinfo(hero harr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout<<"{" << harr[i].name <<"," << harr[i].age << "," << harr[i].male<<"}\n";
	}
}

int main()
{
	hero harr[5];
	int len = sizeof(harr) / sizeof(harr[0]);
	allocatespcae(harr, len);
	Bubblesort(harr, len);
	printinfo(harr, len);
}