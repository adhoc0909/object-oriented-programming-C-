#include<iostream>
#include<string>
#include<cmath>
using namespace std;

/*기초문제 1*/

class Point {
private:
	int x;
	int y;
	static int numCreatedObjects;

public:
	Point() :x(0), y(0) {
		numCreatedObjects++;
	}
	Point(int _x, int _y);
	~Point()
	{
		cout << "Destructed..." << endl;
	}
	static int getNumCreatedObject() { return numCreatedObjects; }

	void setXY(int _x, int _y) {
		this->x = _x;
		this->y = _y;
	}
	int getX() const;
	int getY() const;

	Point& operator=(const Point& pt) {
		this->x = pt.getX();
		this->y = pt.getY();
		return (*this);
	}
	Point operator+(Point& pt2) {
		this->x += pt2.getX();
		this->y += pt2.getY();
		return (*this);
	}

	friend ostream& operator<<(ostream& cout, Point& pt);
	friend void print(const Point& pt);
	friend class SpyPoint;
};

int Point::numCreatedObjects = 0;

Point::Point(int _x, int _y): x(_x), y(_y) {
	numCreatedObjects++;
}

int Point::getX() const { return x; }
int Point::getY() const { return y; }

void print(const Point& pt)
{
	cout << pt.x << ", " << pt.y << endl << endl;
}

ostream& operator<<(ostream& cout, Point& pt) {
	cout << pt.x << ", " << pt.y << endl;
	return cout;
}

//Point operator+(Point& pt1, Point& pt2)
//{
//	Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
//	return result;
//}

class SpyPoint {
public:
	void hack_all_info(const Point& pt)
	{
		cout<<"Hacked by SpyPoint"<<endl;
		cout << "x: " << pt.x << '\n' << "y: " << pt.y<<endl;
		cout << "numCreagedObj: " << pt.numCreatedObjects << endl;
	}
};

int main()
{
	Point pt1(1, 2);
	cout << "pt1 : ";
	print(pt1);

	Point* pPt1 = &pt1;
	cout << "pt1 : ";
	cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
	cout << "pt1 : ";
	cout << pPt1->getX() << ", " << pPt1->getY() << endl;

	Point* pPt2 = new Point;
	pPt2->setXY(10, 20);
	print(*pPt2);
	delete pPt2;

	int a = 3 + 5;
	Point pt2(10, 20), pt3(30, 40);

	Point pt4;
	pt4 + pt2;
	pt4 + pt3;

	cout << "pt2 : " << pt2 << endl;
	cout << "pt3 : " << pt3 << endl;
	cout << "pt4 : " << pt4 << endl;

	cout << "pt1 NumCreatedObject : " << pt1.getNumCreatedObject() << endl << endl;

	Point* ptAry = new Point[5];
	cout << "pt2 NumCreatedObject : " << pt2.getNumCreatedObject() << endl << endl;
	delete[] ptAry;

	SpyPoint spy;
	cout << endl << "pt1 info" << endl;
	spy.hack_all_info(pt1);
	cout << "pt4 info" << endl;
	spy.hack_all_info(pt4);

	return 0;

}


/*응용문제 1*/

class User {
private:
	string ID;
	string Password;
public:
	void setter(string& _ID, string& _Password);
	string getID();
	string getPassword();
};

void User::setter(string& _ID, string& _Password)
{
	ID = _ID;
	Password = _Password;
}

string User::getID()
{
	return ID;
}
string User::getPassword()
{
	return Password;
}

int main()
{
	User user[3];
	string id, password, searchId, searchPassword;
	for (int i = 0; i < 3; i++)
	{
		cout << "========== " << i + 1 << " =========="<<endl;
		cout << "ID : ";
		cin >> id;
		for (int j = 0; j < i; j++)
		{

			if (id == user[j].getID())
			{
				cout << "이미 존재하는 ID 입니다." << endl;
				cout << "종료합니다." << endl;
				exit(100);
			}
		}
		cout << "password : ";
		cin >> password;

		user[i].setter(id, password);
	}

	while (1)
	{

		cout << "========== " << "Login" << " ==========" << endl;
		cout << "ID : ";
		cin >> searchId;
		if (searchId == "종료")
		{
			cout << "종료하겠습니다." << endl;
			exit(100);
		}
		cout << "password : ";
		cin >> searchPassword;

		int count = 0;

		for (int i = 0; i < 3; i++)
		{
			if (user[i].getID() == searchId)
			{
				if (user[i].getPassword() == searchPassword)
				{
					cout << "로그인 되셨습니다." << endl;
					break;
				}
				else
				{
					cout << "잘못된 ID거나 PASSWORD 입니다." << endl;
					break;
				}
			}
			count++;
		}
		if (count == 3)
		{
			cout << "잘못된 ID거나 PASSWORD 입니다." << endl;
		}
		cout << "===========================" << endl << endl;
	}
}


/*응용문제 2*/

class Point {
private:
	int x;
	int y;

public:
	Point(int _x, int _y) :x(_x), y(_y) {}
	Point() :x(0), y(0) {}
	~Point() {}
	int getX() const { return this->x; }
	int getY() const { return this->y; }
	void setPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point& operator=(const Point& pt);
	Point operator-(const Point& pt);
	Point operator*(const Point& pt);
};

Point& Point::operator=(const Point& pt)
{
	this->x = pt.getX();
	this->y = pt.getY();
	return (*this);
}

Point Point::operator-(const Point& pt)
{
	Point result((this->x) - pt.getX(), (this->y) - pt.getY());
	return result;
}

Point Point::operator*(const Point& pt)
{
	Point result((this->x) * pt.getX(), (this->y) * pt.getY());
	return result;
}

int main()
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Point* pP1, * pP2, * pP3;

	cout << "첫 번째 좌표(x1, y1)을 입력하세요 : ";
	cin >> x1 >> y1;

	cout << "두 번째 좌표(x2, y2)을 입력하세요 : ";
	cin >> x2 >> y2;

	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);
	pP3 = new Point();

	*pP3 = *pP1 - *pP2;


	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

	cout << "두 좌표 사이의 길이는 " << sqrt(pP3->getX() + pP3->getY()) << "입니다." << endl;


	delete pP1;
	delete pP2;
	delete pP3;
	return 0;
}


/*응용문제 3*/
class Account {
private:
	string name;
	string id;
	int balance;
public:
	Account(string _name, string _id, int _balance) : name(_name), id(_id), balance(_balance) {}
	~Account() {}
	string getname() const { return this->name; }
	string getid() const { return this->id; }
	int getbalance() const { return this->balance; }

	Account& operator=(const Account& stu)
	{
		this->name = stu.getname();
		this->id = stu.getid();
		this->balance = stu.getbalance();
		return (*this);
	}
	Account operator+(const Account& stu)
	{
		Account result(this->name, this->id, this->balance + stu.getbalance());
		return result;
	}
	Account operator-(const Account& stu)
	{
		Account result(this->name, this->id, this->balance - stu.getbalance());
		return result;
	}
};

ostream& operator<<(ostream& out, const Account& stu)
{
	cout << "학번 : " << stu.getid() << ", 이름 : " << stu.getname() << ", 잔액 : " << stu.getbalance();
	return cout;
}

int main()
{
	Account acnt[3] = {
		Account("장윤호", "2014", 10000),
		Account("김유민", "2019", 0),
		Account("박진배", "2013", 5000),
	};

	string id1, id2, name;


	while (1)
	{
		Account temp("","",0);
		int cnt1 = 0, cnt2=0;
		cout << "돈을 보낼 학생의 학번을 입력하세요: ";
		cin >> id1;
		if (id1 == "종료")
		{
			cout << "종료합니다." << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << acnt[i]<<endl;
			}
			exit(100);
		}
		cout << "돈을 받을 학생의 학번을 입력하세요: ";
		cin >> id2;
		for (int i = 0; i < 3; i++)
		{
			if (id1 == acnt[i].getid())
			{
				break;
			}
			cnt1++;
		}
		for (int i = 0; i < 3; i++)
		{
			if (id2 == acnt[i].getid())
			{
				break;
			}
			cnt2++;
		}
		if (cnt1 == 3 || cnt2 == 3)
		{
			cout << "보내는 학생 혹은 받는 학생의 학번이 존재하지 않습니다. 다시 입력해주세요." << endl;
			continue;
		}
		if (id1 == id2)
		{
			cout << "보내는 학생와 받는 학생의 학번이 동일합니다. 다시 입력해주세요." << endl;
			continue;
		}

		int index1 ,index2;
		for (int i = 0; i < 3; i++)
		{
			if (acnt[i].getid() == id1)
			{
				index1 = i;
			}
			if (acnt[i].getid() == id2)
			{
				index2 = i;
			}
		}
		if (acnt[index1].getbalance() == 0)
		{
			cout << "보내는 학생의 잔액이 부족합니다." << endl;
			continue;
		}
		temp = acnt[index1];
		acnt[index1] = temp - acnt[index1];
		acnt[index2] = acnt[index2] + temp;
		cout << "보낸 학생의 잔액 => "<<acnt[index1] << endl;;
		cout << "받은 학생의 잔액 => " << acnt[index2] << endl;


	}
}

/*응용문제 4*/

class Account {
private:
	string id;
	string name;
	int balance;
	static int acc_bal;
public:
	Account() {}
	~Account() {
		this->acc_bal += this->balance;
	}
	void setter(string _id, string _name, int _balance)
	{
		this->id = _id;
		this->name = _name;
		this->balance = _balance;
	}
	int getAcBal() { return acc_bal; }
};
int Account::acc_bal = 0;

int main()
{
	int n;
	cout << "총 학생 수 입력: ";
	cin >> n;
	string id;
	string name;
	string* ids = new string[n];
	int bal;
	Account* acnt = new Account[n];
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "번째 학생 계좌 입력 " << endl;
		cout << "학번 : ";
		cin >> id;
		for (int j = 0; j < i; j++)
		{
			if (ids[j] == id)
			{
				cout << "중복된 id가 있습니다. 종료합니다." << endl;
				exit(100);
			}
		}
		ids[i] = id;

		cout << '\n';
		cout << "이름 : ";
		cin >> name;
		cout << '\n';
		cout << "잔액 : ";
		cin >> bal;
		cout << '\n';
		acnt[i].setter(id, name, bal);
		cout << "========================" << endl << endl;
	}
	delete[] acnt;
	Account temp;
	cout << "회수된 금액 : " << temp.getAcBal() << endl;
}
