#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*기초문제 1*/
/*
class Point {
private:
	int x;
	int y;

public:
	Point() {}
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	void setXY(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	void print()
	{
		cout << x << ", " << y << endl;
	}
};

int main()
{
	Point pt1(1, 2), pt2(3, 4);
	pt1.setXY(10, 20);
	pt1.print();
	pt2.print();

	cout << pt1.getX() << endl;
	cout << pt2.getY() << endl;

	return 0;
}
*/

/*기초문제 2*/
/*
class Account
{
private:
	string name;
	string id;
	double balance;
public:
	Account() : name(""), id(""), balance(0) {}
	Account(string _name, string _id)
	{
		name = _name;
		id = _id;
		balance = 0;
	}
	Account(string _name, string _id, double _balance):
		name(_name), id(_id), balance(_balance)
	{
		if (balance < 0)
			balance = 0;
	}
	void deposit(double _amt) { balance += _amt; }
	bool withdraw(double _amt)
	{
		if (balance - _amt < 0)
			return false;
		balance -= _amt;
		return true;
	}
	void print()
	{
		cout << name << ", " << id << ", " << balance << endl;
	}
};

int main()
{
	Account ac1("배성호", "1002", 5000);
	Account ac2;
	ac2.print();
	ac1.print();

	int depo;
	cout << "예금할 금액을 입력하세요 : ";
	cin >> depo;
	ac1.deposit(depo);
	ac1.print();

	int wdrw;
	cout << "출금할 금액을 입력하세요 : ";
	cin >> wdrw;
	if (!ac1.withdraw(wdrw))
		cout << "잔액이 부족합니다." << endl;
	ac1.print();
	return 0;
}
*/

/*응용문제 1*/
/*
class Cstudent
{
private:
	int student_number;
	string name;
	string major;
public:
	Cstudent() : student_number(2018000000), name("홍길동"), major("컴퓨터공학과") {}
	Cstudent(int _stunum, string _name, string _major) :
		student_number(_stunum), name(_name), major(_major) {}
	void setNumber(int _num)
	{
		student_number = _num;
	}
	void setName(string _name)
	{
		name = _name;
	}
	void setMajor(string _major)
	{
		major = _major;
	}
	int getNumber() { return student_number; }
	string getName() { return name; }
	string getMajor() { return major; }

	void Display()
	{
		cout << "학번 :" << student_number << endl;
		cout << "이름 :" << name << endl;
		cout << "전공 :" << major << endl<<endl;
	}
};

int main()
{
	Cstudent s1;
	s1.Display();

	Cstudent s2(1999000000, "공지철", "연극영화과");
	s2.Display();

	s1.setNumber(2006000000);
	s1.setName("민경훈");
	s1.setMajor("포스트모던");
	cout << "학번 :" << s1.getNumber() << endl;
	cout << "이름 :" << s1.getName() << endl;
	cout << "전공 :" << s1.getMajor() << endl;
	return 0;

}

*/

/*응용문제 2*/
/*
class Cstudent
{
private:
	int student_number;
	string name;
	string major;
public:
	Cstudent() : student_number(2018000000), name("홍길동"), major("컴퓨터공학과") {}
	Cstudent(int _stunum, string _name, string _major) :
		student_number(_stunum), name(_name), major(_major) {}
	void setNumber(int _num)
	{
		student_number = _num;
	}
	void setName(string _name)
	{
		name = _name;
	}
	void setMajor(string _major)
	{
		major = _major;
	}
	int getNumber() { return student_number; }
	string getName() { return name; }
	string getMajor() { return major; }

	void Display()
	{
		cout << "학번 :" << student_number << endl;
		cout << "이름 :" << name << endl;
		cout << "전공 :" << major << endl << endl;
	}
};


int main()
{
	Cstudent s[3];
	int inputNumber;
	string inputName, inputMajor;
	int length = 0;

	while (1)
	{
		cout << length + 1 << " 번째 학생 입력" << endl;
		cout << "학번 : ";
		cin >> inputNumber;
		cout << "이름 : ";
		cin >> inputName;
		cout << "전공 : ";
		cin >> inputMajor;

		int temp = 0;
		for (int i = 0; i < length; i++)
		{
			if (s[i].getNumber() == inputNumber)
			{
				cout << "※중복된 학번이 존재합니다." << endl << endl;
				break;
			}
			temp++;
		}
		if (temp == length)
		{
			s[length].setNumber(inputNumber);
			s[length].setName(inputName);
			s[length].setMajor(inputMajor);
			cout << "※입력 완료" << endl << endl;
			length++;
			if (length == 3)
				break;
		}
		temp = 0;
	}
	cout << "----모든 입력이 완료되었습니다----" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << i + 1 << "학생정보" << endl;
		s[i].Display();
	}

	return 0;
}
*/

/*응용문제 3*/
/*
class Student
{
private:
	string name;
	int number;
	string major;
	vector<string> subject;
	vector<char> grade;

public:
	Student() : name("default"), number(0), major("depart") {}
	Student(string _name, int _number, string _major) :
		name(_name), number(_number), major(_major) {}

	void setName(string _name)
	{
		name = _name;
	}
	void setID(int _id)
	{
		number = _id;
	}
	void setDpt(string _major)
	{
		major = _major;
	}
	void print()
	{
		cout << name << " " << number << " " << major << endl;
	}
	void addGrade(string sub, char gra)
	{
		subject.push_back(sub);
		grade.push_back(gra);
	}
	void printGrades()
	{
		for (int i = 0; i < subject.size(); i++)
			cout << subject[i] << " " << grade[i] << endl;

		cout << "GPA : " << getGPA() << endl;
	}
	float getGPA()
	{
		float sum=0;
		float average;
		vector<int> int_grade;
		for (int i = 0; i < grade.size(); i++)
		{
			if (grade[i] == 'A')
				int_grade.push_back(4);
			else if (grade[i]=='B')
				int_grade.push_back(3);
			else if (grade[i]=='C')
				int_grade.push_back(2);
			else if (grade[i]=='D')
				int_grade.push_back(1);
			else if (grade[i]=='F')
				int_grade.push_back(0);
		}
		for (int i = 0; i < int_grade.size(); i++)
		{
			sum += int_grade[i];
		}
		average = sum / int_grade.size();
		return average;
	}
	void getYear(int year)
	{
		int grade = year - (number / 1000000);
		switch (grade)
		{
		case 0:
			cout << "Freshmen(1학년)" << endl;
			break;

		case 1:
			cout << "Sophomore(2학년)" << endl;
			break;
		case 2:
			cout << "Junior(3학년)" << endl;
			break;
		case 4:
			cout << "Senior(4학년)" << endl;
			break;
		default:
			cout << "About to graduate(5학년 이상)" << endl;
		}
	}
};


	int main() {
		Student Harry("Harry", 2017310973, "CS");
		Harry.print();
		Harry.getYear(2019);
		Harry.addGrade("programming", 'A');
		Harry.addGrade("Basic Circuit", 'B');
		Harry.printGrades();
		cout << "\n\n";
		Student Ron;
		Ron.print();
		cout << "\n";
		Ron.setName("Ron");
		Ron.setID(2014103959);
		Ron.setDpt("EE");
		Ron.print();
		Ron.getYear(2019);
		Ron.addGrade("Computer Architecture", 'B');
		Ron.addGrade("Maching Learning", 'B');
		Ron.addGrade("Computer Vision", 'C');
		Ron.printGrades();
		cout << "\n\n";
		return 0;
	}
*/