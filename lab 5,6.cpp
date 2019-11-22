#include<iostream>
#include<iomanip>
using namespace std;

/*기초문제 1*/

int main()
{
	char grade = 'X';
	int score;
	cout << "Enter your score: ";
	cin >> score;

	if (score >= 90 && score<=100)
	{
		grade = 'A';
		cout << "Your grade is " << grade << endl;
	}
	else if (score >= 80)
	{
		grade = 'B';
		cout << "Your grade is " << grade << endl;
	}
	else if (score >= 70)
	{
		grade = 'C';
		cout << "Your grade is " << grade << endl;
	}
	else if (score >= 60)
	{
		grade = 'D';
		cout << "Your grade is " << grade << endl;
	}
	else if (score < 60)
	{
		grade = 'F';
		cout << "Your grade is " << grade << endl;
	}
	else
	{
		cout << "The score (" << score << ") is invalid" << endl;
	}

	return 0;
}



/*기초문제 2*/

int main()
{
	int num = 1;
	int count = 1;
	cout.imbue(locale(""));
	while (count <= 20)
	{
		num *= 2;
		cout << count << '\t' << setw(10) << num << endl;
		count++;
	}
	return 0;
}


/*기초문제 3*/

int main()
{
	int column = 1, row = 1;
	while (row <= 10)
	{
		while (column <= 10)
		{
			int num;
			num=((column == row) ? ( 1 : 0 ));
			cout << setw(4) << num;
			column++;
		}
		column = 1;
		cout << endl;
		row++;
	}
	return 0;
}


/*기초문제 4*/

int main()
{
	int num;

	while (true)
	{
		cout << "Enter the number (0, 10]: ";
		cin >> num;
		if (num <= 10 && num > 0)
		{
			break;
		}
	}
	cout << "Success!" << endl;
	return 0;
}


/*기초문제 5*/

int main()
{
	int n, m;
	cout << "Enter n for n x m matrix: ";
	cin >> n;
	cout << "Enter m for n x m matrix: ";
	cin >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(4) << (i + 1)*(j + 1);
		}
		cout << endl;
	}
	return 0;
}


/*기초문제 6*/

int main()
{
	char key;
	cout << "Enter a key (p or q): ";
	cin >> key;
	switch (key)
	{
	case('p'):
		cout << "Pause" << endl;
		break;
	case('q'):
		cout << "Quit" << endl;
		break;
	case('P'):
		cout << "Pause" << endl;
		break;
	case('Q'):
		cout << "Quit" << endl;
		break;
	default:
		cout << "Default" << endl;
	}
	return 0;
}


/*응용문제 1*/

int main()
{
	double n;
	while(true)
	{
		cout << "number : ";
		cin >> n;
		if (n - (int)n != 0 || n < 0) break;
		else
		{
			if ((int)n % 2 == 0)
			{
				cout << (int)n << "은 짝수입니다." << endl;
			}
			else
			{
				cout << (int)n << "은 홀수입니다." << endl;
			}
		}
	}
	cout << "잘못된 숫자입니다." << endl;
	return 0;
}


/*응용문제 2*/

int main()
{
	int n;
	int result = 0;

	cout << "number : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		result += (i + 1);
	}
	cout << result << endl;
}


/*응용문제 3*/

int main()
{
	int n;
	int result = 0;

	cout << "number : ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if(i%2!=0 && i%3!=0)
		result += i;
	}
	cout << result << endl;
}


/*응용문제 4*/

int main()
{
	int n;
	while (true)
	{
		cout << "number : ";
		cin >> n;
		if (!(n >= 1 && n <= 9))
		{
			cout << "잘못된 숫자입니다." << endl;
			break;
		}
		else
		{
			for (int i = 1; i <= 9; i++)
			{
				cout << n << '*' << i << " = " << n * i<<"  ";
			}
			cout << endl;
		}
	}
	return 0;
}


/*응용문제 5*/

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a%b);
	}
}
int main()
{
	int x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "gcd(" << x << "," << y << ") = " << gcd(x, y) << endl;
}
