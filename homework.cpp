#include<iostream>
using namespace std;
int t = 0;/*��������������������������֮�仹�����㣬�������Ҫ���д�С�жϣ��ǽ���Ŀ���*/
int max(int num1, int num2){
	if (num1>num2)
	{
		t = num1;
		num1 = num2;
		num2 = t;/*�ѽϴ��ֵ���ڶ�����*/
	}
	if (num2 % num1 == 0)
	{
		return num1;
	}
	else if (num2%num1!=0)
	{
		for (int  i = num1; i >0; i--)
		{
			if ((num1%i==0)&&(num2%i==0))
			{
				return i;
			}
		}
	}
}
int gbs(int x, int y)  //������С���������� 

{

	return x * y / max(x, y);

}

int main()
{
	int a, b = 0;
	cin >> a >> b;
	int m=max(a, b);
	int n = gbs(a, b);
	cout <<"���Լ��" << m<<"��С������"<<n;
	
}