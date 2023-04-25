#include<iostream>
using namespace std;
int t = 0;/*函数有两个参数，且两个参数之间还有运算，大概率需要进行大小判断，是解题的口子*/
int max(int num1, int num2){
	if (num1>num2)
	{
		t = num1;
		num1 = num2;
		num2 = t;/*把较大的值给第二个数*/
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
int gbs(int x, int y)  //计算最小公倍数函数 

{

	return x * y / max(x, y);

}

int main()
{
	int a, b = 0;
	cin >> a >> b;
	int m=max(a, b);
	int n = gbs(a, b);
	cout <<"最大公约数" << m<<"最小公倍数"<<n;
	
}