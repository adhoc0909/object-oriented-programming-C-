#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
using namespace std;

/*기초문제 1*/
/*
void swap(int* x, int* y)
{
	int temp=*x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a = 10, b = 20;
	cout << a << ", " << b << endl;
	swap(&a, &b);
	cout << a << ", " << b << endl;
	return 0;
}
*/

/*기초문제 2*/
/*
int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }
int evaluate(int(*f)(int, int), int a, int b) { return f(a, b); }
int main()
{
	int(*func)(int, int);
	func = &sum;
	cout << func(10, 20) << endl;
	func = &mult;
	cout << func(10, 20) << endl;
	cout << evaluate(&sum, 100, 200) << endl;
	cout << evaluate(&mult, 100, 200) << endl;

	return 0;
}
*/

/*기초문제 3*/
/*
void print(const vector<int>& v)
{
	for (unsigned i = 0; i < v.size(); i++)
		cout << v[i] << '\t';
	cout << endl;
}

int main()
{
	vector<int> vec{ 10, 20, 30 };
	print(vec);

	vec[0] = 1;
	vec.at(0) = 1;
	print(vec);

	vec.push_back(100);
	print(vec);

	vec.pop_back();

	cout << endl;

	for (int& elem : vec)
	{
		cout << "enter an element of vector v: ";
		cin >> elem;
	}

	cout << endl << "[ vector v ]" << endl;

	for (int elem : vec)
		cout << elem << '\t';
	cout << endl;

	return 0;
}
*/

/*기초문제*/
/*
bool is_prime(int num)
{
	if (num < 2)
		return false;
	for (int i = 2; i < num; i++)
	{
		if (num % 2 == 0)
			return false;
	}
	return true;
}

vector<int> primes(int lower, int upper)
{
	vector<int> v;
	for (int i = lower; i <= upper; i++)
	{
		if (is_prime(i))
			v.push_back(i);
	}
	return v;
}

int main()
{
	int lower = 10, upper = 100;
	vector<int> vec;
	vec = primes(lower, upper);
	for (int elem : vec)
		cout << elem << setw(5);
	cout << endl;
	return 0;
}


/*응용문제 1*/
/*
void square(int* n)
{
	(*n) *= (*n);
}

int main()
{
	int a;
	cout << "input>";
	cin >> a;
	square(&a);
	cout << "제곱값>" << a;

	return 0;
}
*/

/*응용문제 2*/
/*
void converter(string *ss)
{
	cout << "input> ";
	cin >> *ss;

}

int main()
{
	string str = "This is default value";
	cout << "기본값 출력> " << str << endl;
	converter(&str);
	cout << "변환된 값 출력> " << str << endl;
	return 0;
}
*/

/*응용문제 3*/
/*
void reverse(vector<int>* vec)
{
	int temp;
	for (int i = 0; i < (int)((*vec).size() / 2); i++)
	{
		temp = (*vec)[((*vec).size() - i-1)];
		(*vec)[(*vec).size() - i-1] = (*vec)[i];
		(*vec)[i] = temp;
	}
}

int main()
{
	vector<int> v(10);
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = i+1;
	}

	cout << "기본 Vector 값:" << endl;
	for (int elem : v)
		cout << elem <<' ';
	cout << endl;

	reverse(&v);

	cout << "함수 실행 후 Vector 값" << endl;
	for (int elem : v)
		cout << elem <<' ';
	cout << endl;
	return 0;
}
*/

/*응용문제 4*/

int inputGrade(float grade)
{
	cin >> grade;
//	if ((grade - (int)grade) != 0.0 || grade < 0 || grade>100)
//	{
//		cout << "invalid input!!!" << endl;
//		exit(EXIT_FAILURE);
//	}
//	else
		return (int)grade;
}
int* topGrade(const vector<int>& grade)
{
	int max;
	max = 0;
	for (int i = 0; i < grade.size(); i++)
	{
		if (max <= grade[i])
			max = grade[i];
	}
	return &max;
}

int main()
{
	vector<int> grades;
	float _grade = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "Input " << i << "-th grade(0~100):";
		int grade = inputGrade(_grade);
		grades.push_back(grade);
	}

	int res = *topGrade(grades);
	cout << "Top Grade: " << res << endl;
	return 0;
}

