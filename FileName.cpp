#include<iostream>
#include<string>
#include<ctime>/*时间头文件*/
using namespace std;
struct student/*创建一个学生的结构体*/
{
	string name;
	int age;
	int score;
};
struct teacher/*教师结构体*/
{
	string name;
	student ar[5];
};
void allocatespcae(struct teacher tarr[], int len)/*对老师及学生进行赋值*/
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
void printinfo(teacher tarr[], int len)/*输出所有信息*/
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师姓名：" << tarr[i].name <<"\t"<< endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名" << tarr[i].ar[j].name << "\t"

				"分数" << tarr[i].ar[j].score << "\t"

				"年龄" << tarr[i].ar[j].age << endl;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));/*生成随机时间的种子，好像可以不加头文件，但是还是加上最好*/
	struct teacher tarr[3];/*定义一个老师的数组*/
	
	/*通过函数对老师的数组和同学的数组进行赋值*/
	int len = sizeof(tarr) / sizeof(tarr[0]);
	allocatespcae(tarr, len);

	/*输出所有的信息*/
	printinfo(tarr, len);
}