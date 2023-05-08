/*自动填充数据*/
#include<iostream>
using namespace std;
#include<string>
#include<ctime>
#include<iomanip>
#define MAX 50//不能带分号
struct Contactperson/*设计联系人的结构体*/
{
	string name;
	int age;
	int sex;
	string phone;
	string add;
	string id;
};
struct Addressbook
{
	struct Contactperson arr[MAX];
	int size;
};
void Fillname(Addressbook*abs)/*姓名*/
{
	for (int i = 0; i < MAX; i++)
	{
		string a ="赵钱孙李周吴郑王冯陈褚卫蒋沈韩杨朱秦尤许何吕施张孔曹严华金魏陶姜戚谢邹喻柏水窦章云苏潘葛奚范彭郎鲁韦";
		string b = "ABCDEFGHIJKLMNOPQRETUVWXYZ";
		string c;
		c = a.substr((rand() % 18)*2, 2);
		string d ,f;
		d = b.substr(rand() % 26, 1);
		f= b.substr(rand() % 26, 1);
		abs->arr[i].name = c+d+f;
	}
}
void Automaticallyaddage(Addressbook* abs)/*年龄*/
{
	for (int i = 0; i < MAX ;i++)
	{
		int a = 0;
		a = rand() % 65 + 16;
		abs->arr[i].age=a;
		
	}
	
}
void Automaticfillingnumber(Addressbook* abs)/*对phone进行赋值*/
{
	for (int i = 0; i < MAX; i++)
	{
		string a = "0123456789";
		string c;
		string d= a.substr(rand() % 8+2, 1);
		string e = "1";
		for (int i = 0; i < 9; i++)
		{
			string b = a.substr(rand() % 10, 1);
			c += b;
		}
		abs->arr[i].phone =e+d+c;/*通过数组来写num*/
	}
}
void address(Addressbook* abs)
{
	for (int i = 0; i < MAX; i++)
	{
		string a[34] = { "北京市","天津市","河北省","山西省","内蒙古自治区","辽宁省","吉林省","黑龙江省","上海市","江苏省","浙江省","安徽省","福建省","江西省","山东省","河南省","湖北省","湖南省","广东省","广西壮族自治区","海南省","重庆市","四川省","贵州省","云南省","西藏自治区","陕西省","甘肃省","青海省","宁夏回族自治区","新疆维吾尔自治区","台湾","香港特别行政区","澳门特别行政区" };
		string d[34] = { "11","12","13","14","15","21","22","23","31","32","33","34","35","36","37","41","42","43","44","45","46","50","51","52","53","54","61","62","63","64","65","71","81","82" };
		int b = rand() % 34;
		abs->arr[i].add=a[b];
		string r=d[b];
		for (int i = 0; i < 16; i++)
		{
			string g = "0123456789";
			string h = g.substr(rand() % 10, 1);
			r += h;
		}
		abs->arr[i].id = r;
		
	}
}
void gender(Addressbook*abs)
{
	for (int i = 0; i < MAX; i++)
	{
		int a = 0;
		a = rand() % 10;
		if (a%2)
		{
			abs->arr[i].sex = 1;
		}
		else
		{
			abs->arr[i].sex = 2;
		}
	
	}
}

void Displaycontact(Addressbook* abs)/*显示联系人*/
{

	if (abs->size == 0)
	{
		cout << "通讯录里没有此人，请先录入数据" << endl;
	}
	else
	{
		for (int i = 0; i < MAX; i++)
		{
			cout << "姓名" << "：" << abs->arr[i].name << "| | |";/*注意这里是i不是abs.size*/
			cout << "性别" << "：" << (abs->arr[i].sex == 1 ? "男" : "女") << "| | |";/*三目运算*/
			cout << "年龄" << "：" << abs->arr[i].age << "| | |";
			cout << "电话" << "：" << abs->arr[i].phone << "| | |";
			cout << "籍贯" << "：" <<setw(16) << abs->arr[i].add << "| | |";
			cout <<setw(10)<<"身份证:" << abs->arr[i].id << endl;
		}
		system("pause");/*按任意键继续*/
		system("cls");/*清屏*/
	}
}
void id(Addressbook* abs)
{

}

int main()
{
	Addressbook abs;
	abs.size = MAX;
	Fillname(&abs);
	srand((unsigned int)time(NULL));
	Automaticfillingnumber(&abs);
	Automaticallyaddage(&abs);
	gender(&abs);
	address(&abs);
	Displaycontact(&abs);
}
