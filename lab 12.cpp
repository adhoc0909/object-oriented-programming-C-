#include<iostream>
#include<string>
#include<cmath>
using namespace std;

/*기초문제 1*/
/*
class Base {
protected:
	void print_base() { cout << "Base" << endl; }
};

class Derived : private Base {
public:
	void print_derived()
	{
		Base::print_base();
		cout << "Derived" << endl;
	}
};

int main()
{
	Base base;
	Derived derived;

	derived.print_derived();

	return 0;
}
*/

/*기초문제 2*/
/*
class Text {
private:
	string text;
public:
	Text(string _t) :text(_t) {}
	virtual string get() const { return text; }
	virtual void append(string _extra) { text += _extra; }
};

class FancyText: public Text {
private:
	string left_brac;
	string right_brac;
	string connector;
public:
	FancyText(string _t, string _lb, string _rb, string _con):
		Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}
	string get() const override { return left_brac + Text::get() + right_brac; }
	void append(string _extra) override { Text::append(connector + _extra); }
};

class FixedText : public Text {
public:
	FixedText() :Text::Text("Fixed") {}
	void append(string _extra) override {}
};

int main()
{
	Text t1("Plain");
	t1.append("A");
	cout << t1.get() << endl;

	FancyText t2("Fancy", "<<", ">>", "***");
	t2.append("A");
	cout << t2.get() << endl;

	FixedText t3;
	t3.append("A");
	cout << t3.get() << endl;
	t1 = t2;

	return 0;
}
*/

/*응용문제 1*/
/*
class Polygon {
public:
	Polygon() {}
	Polygon(int point, float length) { mPoint = point, mLength = length; }
	~Polygon() {}
	virtual void calcPerimeter() { cout << "empty" << endl; }
	virtual void calcArea() { cout << "empty" << endl; }
protected:
	int mPoint;
	double mLength;
};

class Rectangle : public Polygon {
public:
	Rectangle() {}
	Rectangle(int point, float length) : Polygon(point, length) {}
	~Rectangle() {}
	void calcPerimeter() override { cout <<"Preimeter: "<< mPoint*mLength << endl; }
	void calcArea() override { cout <<"Area: "<< mLength * mLength << endl; }
};

int main()
{
	Polygon pol;
	Rectangle rec(4, 10);

	cout << "--- Polygon class ---" << endl;
	pol.calcPerimeter();
	pol.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();
}
*/

/*응용문제 2*/
/*
class Polygon {
public:
	Polygon() {}
	Polygon(int point, float length) { mPoint = point, mLength = length; }
	~Polygon() {}
	virtual void calcPerimeter() { cout << "empty" << endl; }
	virtual void calcArea() { cout << "empty" << endl; }
protected:
	int mPoint;
	double mLength;
};

class Rectangle : public Polygon {
public:
	Rectangle() {}
	Rectangle(int point, float length) : Polygon(point, length) {}
	~Rectangle() {}
	void calcPerimeter() override { cout << "Preimeter: " << mPoint * mLength << endl; }
	void calcArea() override { cout << "Area: " << mLength * mLength << endl; }
};

class Triangle : public Polygon {
public:
	Triangle() {}
	Triangle(int point, int length): Polygon(point, length) {}
	~Triangle() {}
	void calcPerimeter() override { cout << "Perimeter: " << mPoint * mLength << endl; }
	void calcArea() override {
		cout << "Area: " << (sqrt(3) / 4)*mLength << endl;
	}
};

class Circle : public Polygon {
public:
	Circle() {}
	Circle(int point, int length) :Polygon(point, length) {}
	~Circle() {}
	void calcPerimeter() override { cout << "Perimeter: " << 2 * 3.14*mLength << endl; }
	void calcArea() override { cout << "Area: " << mLength * mLength*3.14 << endl; }
	};

int main() {
	Triangle tri(3, 10);
	Rectangle rec(4, 10);
	Circle cir(0, 5);
	cout << "--- Triangle class ---" << endl;
	tri.calcPerimeter();
	tri.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();
	cout << "--- Circle class ---" << endl;
	cir.calcPerimeter();
	cir.calcArea();
	return 0;
}
*/

/*응용문제 3*/
/*
class Train {
public:
	Train() {}
	Train(int people) { mPeople = people; }
	virtual int station(int takeOff, int takeOn) 
	{ 
		return takeOn-takeOff;
	}
protected:
	int mPeople;
};

class Ktx :public Train {
public:
	Ktx() :Train(0) {}
	Ktx(int people) :Train(people) {}
	~Ktx() {}
	int station(int takeOff, int takeOn) override
	{
		mPeople+= Train::station(takeOff, takeOn);
		return mPeople;
	}
	int getPeople() {
		return mPeople;
	}
};

int main()
{
	Ktx k;
	int in, out;
	int max=0;
	for (int i = 0; i < 5; i++)
	{
		cout <<i+1<< "번역: ";
		cin >> out >> in;
		if (k.getPeople() < out)
		{
			cout << "정원 미달입니다." << endl;
			exit(100);
		}
		if (k.getPeople() + in - out > 300)
		{
			cout << "정원 초과입니다." << endl;
			exit(100);
		}
		if (max < k.station(out, in))
			max = k.getPeople();
	}
	cout << "가장 많은 사람이 탑승했을 때의 사람 수: " << max << endl;
}
*/

/*응용문제 4*/
/*
class Avengers {
public:
	Avengers()
	{
		name = "";
		attack_point = 0;
		defense_point = 0;
		health = 0;
	}
	~Avengers() {}
	virtual void set(string _name, int _attack, int _defense, int _health) {}
	virtual int attack(){ return 0; }
	virtual void defense(int _attack_point){}
	virtual void print_info() {}

protected:
	string name;
	int attack_point;
	int defense_point;
	int health;
};

class Character : public Avengers{
public:
	Character() {}
	~Character() {}
	void set(string _name, int _attack, int _defense, int _health) override
	{
		name = _name;
		attack_point = _attack;
		defense_point = _defense;
		health = _health;
	}
	int attack() override
	{
		return attack_point;
	}
	void defense(int _attack_point) override
	{
		health -= _attack_point - defense_point;
	}
	void print_info()
	{
		cout << "name: " << name<<endl;
		cout << "Attack_Point: " << attack_point << endl;
		cout << "Defense_Point: " << defense_point << endl;
		cout << "Health: " << health;
	}
	int get_health() { return health; }
};

int main()
{
	Character my_char;
	Character enemy_char;
	string character;
	int randnum=rand()%3;
	string char_list[3]{ "IronMan", "CaptinAmerica", "Thor" };
	int info_list[3][3]{
	{70, 60, 80},
	{40, 50, 30},
	{100, 100, 100}
	};
	cout << "Choose your character(IronMan, CaptinAmerica, Thor): ";
	cin >> character;
	if (character == "IronMan")
		my_char.set(character, 70, 40, 100);
	else if (character == "CaptinAmerica")
		my_char.set(character, 60, 50, 100);
	else if (character == "Thor")
		my_char.set(character, 80, 30, 100);
	else
	{
		cout << "wrong character name" << endl;
		exit(100);
	}
	enemy_char.set(char_list[randnum], info_list[0][randnum], info_list[1][randnum], info_list[2][randnum]);
	
	cout << "--My character--" << endl;
	my_char.print_info();
	cout << "Enemy Character--" << endl;
	enemy_char.print_info();


	cout << "--Battle--" << endl;
	cout << "My Life: " << my_char.get_health() << '\t' << "Enemy Life: " << enemy_char.get_health() << endl;
	while (true)
	{
		enemy_char.defense(my_char.attack());
		cout << "My Life: " << my_char.get_health() << '\t' << "Enemy Life: " << enemy_char.get_health() << endl;
		if (enemy_char.get_health() <= 0)
		{
			cout << "You Win!" << endl;
			break;
		}
		my_char.defense(enemy_char.attack());
		cout << "My Life: " << my_char.get_health() << '\t' << "Enemy Life: " << enemy_char.get_health() << endl;
		if (my_char.get_health() <= 0)
		{
			cout << "Enemy Win!" << endl;
			break;
		}
	}

}
*/