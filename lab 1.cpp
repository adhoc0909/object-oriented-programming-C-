#include<iostream>
using namespace std;

/*
//���ʹ���1
int main()
{
	int x, y;
	x = 10;
	y = 20;
	cout << x << endl;
	cout << y << endl;
}
*/

/*
//���ʹ��� 2
//sizeof()�Լ��� �Ķ������ ũ�⸦ byte ������ ��ȯ�ϴ� �Լ��̴�.
int main()
{
	unsigned short siX;
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX): " << sizeof(siX) << endl;
	cout << "sizeof(iX): " << sizeof(iX) << endl;
	cout << "sizeof(liX): " << sizeof(liX) << endl;
	cout << "sizeof(lliX): " << sizeof(lliX) << endl;
}

*/

/*
//���ʹ��� 3
int main()
{
	cout << "(7==5):" << (7 == 5) << endl;
	cout << "(7>=5):" << (7 >= 5) << endl;
	cout << "(7!=5):" << (7 != 5) << endl;
	cout << "(7<=5):" << (7 <= 5) << endl;
	cout << "(7>=5 ? 100 : -100):" << (7 >= 5 ? 100 : -100) << endl;
}
*/

/*
//���ʹ��� 4
int main()
{
	const float PI = 3.14;
	char ch1 = 65;
	char ch2 = 97;
	cout << PI << endl;
	cout << ch1 << endl;
	cout << ch2 << endl;
}
*/

/*
//���ʹ��� 5
int main()
{
	int x, y, sum, mult;
	float div;
	cin >> x >> y;
	sum = x + y;
	mult = x * y;
	div = float(x) / y;
	cout << x << '\t' << y << endl;
	cout << "x + y = " << sum << endl;
	cout << "x * y = " << mult << endl;
	cout << "x / y = " << div << endl;
}
*/

/*
//���빮�� 1
int main()
{
	cout << "My name is ��ȣ��" << endl;
}
*/

/*
//���빮�� 2
int main()
{
	int A, B;
	cout << "Please enter two integer values: ";
	cin >> A >> B;
	cout << A << " + " << B << " = " << A + B << endl;
	cout << A << " - " << B << " = " << A - B << endl;
	cout << A << " * " << B << " = " << A * B << endl;
	cout << A << " / " << B << " = " << float(A) / B << endl;
	cout << A << " % " << B << " = " << A % B << endl;
}
*/

/*
//���빮�� 3
int main()
{
	int i1 = 2;
	int i2 = 5;
	int i3 = -3;
	double d1 = 2.0;
	double d2 = 5.0;
	double d3 = -0.5;

	cout << i1 + (i2 * i3) << endl;
	cout << i1 * (i2 + i3) << endl;
	cout << i1 / (i2 + i3) << endl;
	cout << i1 / i2 + i3 << endl;
	cout << 3 + 4 + 5 / 3 << endl;
	cout << (3 + 4 + 5) / 3 << endl;
	cout << d1 + (d2 * d3) << endl;
	cout << d1 + d2 * d3 << endl;
	cout << d1 / d2 - d3 << endl;
	cout << d1 / (d2 - d3) << endl;
	cout << d1 + d2 + d3 / 3 << endl;
	cout << (d1 + d2 + d3) / 3 << endl;
}
*/

/*
//���빮�� 4
int main()
{
	int A, B;
	int temp;
	cout << "Please enter two integer values: ";
	cin >> A >> B;
	cout << "A : " << A<<endl;
	cout << "B : " << B<<endl;
	temp = A;
	A = B;
	B = temp;
	cout << "value of A is : " << A<<endl;
	cout << "value of B is : " << B<<endl;
}
*/

/*
//���빮�� 5
int main()
{
	float fv;//ȭ���µ�
	cout << "Please enter Fahrenheit value: ";
	cin >> fv;
	cout << "Celsius value is " << 5.0f / 9.0f*(fv - 32) << endl;
}
*/