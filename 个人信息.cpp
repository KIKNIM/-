/*�Զ��������*/
#include<iostream>
using namespace std;
#include<string>
#include<ctime>
#include<iomanip>
#define MAX 50//���ܴ��ֺ�
struct Contactperson/*�����ϵ�˵Ľṹ��*/
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
void Fillname(Addressbook*abs)/*����*/
{
	for (int i = 0; i < MAX; i++)
	{
		string a ="��Ǯ��������֣��������������������������ʩ�ſײ��ϻ���κ�ս���л������ˮ��������˸��ɷ�����³Τ";
		string b = "ABCDEFGHIJKLMNOPQRETUVWXYZ";
		string c;
		c = a.substr((rand() % 18)*2, 2);
		string d ,f;
		d = b.substr(rand() % 26, 1);
		f= b.substr(rand() % 26, 1);
		abs->arr[i].name = c+d+f;
	}
}
void Automaticallyaddage(Addressbook* abs)/*����*/
{
	for (int i = 0; i < MAX ;i++)
	{
		int a = 0;
		a = rand() % 65 + 16;
		abs->arr[i].age=a;
		
	}
	
}
void Automaticfillingnumber(Addressbook* abs)/*��phone���и�ֵ*/
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
		abs->arr[i].phone =e+d+c;/*ͨ��������дnum*/
	}
}
void address(Addressbook* abs)
{
	for (int i = 0; i < MAX; i++)
	{
		string a[34] = { "������","�����","�ӱ�ʡ","ɽ��ʡ","���ɹ�������","����ʡ","����ʡ","������ʡ","�Ϻ���","����ʡ","�㽭ʡ","����ʡ","����ʡ","����ʡ","ɽ��ʡ","����ʡ","����ʡ","����ʡ","�㶫ʡ","����׳��������","����ʡ","������","�Ĵ�ʡ","����ʡ","����ʡ","����������","����ʡ","����ʡ","�ຣʡ","���Ļ���������","�½�ά���������","̨��","����ر�������","�����ر�������" };
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

void Displaycontact(Addressbook* abs)/*��ʾ��ϵ��*/
{

	if (abs->size == 0)
	{
		cout << "ͨѶ¼��û�д��ˣ�����¼������" << endl;
	}
	else
	{
		for (int i = 0; i < MAX; i++)
		{
			cout << "����" << "��" << abs->arr[i].name << "| | |";/*ע��������i����abs.size*/
			cout << "�Ա�" << "��" << (abs->arr[i].sex == 1 ? "��" : "Ů") << "| | |";/*��Ŀ����*/
			cout << "����" << "��" << abs->arr[i].age << "| | |";
			cout << "�绰" << "��" << abs->arr[i].phone << "| | |";
			cout << "����" << "��" <<setw(16) << abs->arr[i].add << "| | |";
			cout <<setw(10)<<"���֤:" << abs->arr[i].id << endl;
		}
		system("pause");/*�����������*/
		system("cls");/*����*/
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
