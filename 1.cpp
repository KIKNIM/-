#include<iostream>
using namespace std;
/*����Ӣ�۵Ľṹ��*/
struct hero 
{
	string name;
	int age;
	string male;
};
/*�Խṹ����и�ֵ*/
void allocatespcae(hero harr[], int len)
{
	string nameseed[] = { "�ŷ�","����","����","����","����" };
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
	{
		
		 harr[i].name="����-";
		 harr[i].name += nameseed[i];
		 harr[i].age =rand()%10+25;
		 harr[i].male="male";
	}
}
/*ð������*/
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
/*�������*/
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