#include<iostream>
#include<string>
#include<ctime>/*ʱ��ͷ�ļ�*/
using namespace std;
struct student/*����һ��ѧ���Ľṹ��*/
{
	string name;
	int age;
	int score;
};
struct teacher/*��ʦ�ṹ��*/
{
	string name;
	student ar[5];
};
void allocatespcae(struct teacher tarr[], int len)/*����ʦ��ѧ�����и�ֵ*/
{
	string nameseed = "ABCDEF";
	for (int i = 0; i < 3; i++)
	{
		tarr[i].name = "teacher-";
		tarr[i].name += nameseed[i];
		for (int j = 0; j < 5; j++)
		{
			tarr[i].ar[j].name = "student-";
			tarr[i].ar[j].name += nameseed[j];
			tarr[i].ar[j].age = rand() % 7 + 12;
			tarr[i].ar[j].score = rand() % 61 + 40;
		}
	}

}
void printinfo(teacher tarr[], int len)/*���������Ϣ*/
{
	for (int i = 0; i < len; i++)
	{
		cout << "��ʦ������" << tarr[i].name <<"\t"<< endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\tѧ������" << tarr[i].ar[j].name << "\t"

				"����" << tarr[i].ar[j].score << "\t"

				"����" << tarr[i].ar[j].age << endl;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));/*�������ʱ������ӣ�������Բ���ͷ�ļ������ǻ��Ǽ������*/
	struct teacher tarr[3];/*����һ����ʦ������*/
	
	/*ͨ����������ʦ�������ͬѧ��������и�ֵ*/
	int len = sizeof(tarr) / sizeof(tarr[0]);
	allocatespcae(tarr, len);

	/*������е���Ϣ*/
	printinfo(tarr, len);
}