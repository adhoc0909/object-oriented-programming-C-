#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

/*기초문제 1*/

int main()
{
	string s1 = "mouse";
	cout << s1 << endl;
	cout << s1.length() << ", " << s1.size() << endl << endl;

	cout << s1.empty() << endl;
	s1.clear();
	cout << s1.empty() << endl;

	s1 = "Good";
	s1 = s1 + "-bye";
	cout << s1 << endl;
	cout << s1[4] << ", " << s1.at(4) << endl;
	cout << (s1 == "Good-bye") << endl;
	cout << (s1 == "good-bye") << endl;
	cout << (s1 > "z") << endl << endl;

	cout << s1.substr(5, 3) << endl;
	cout << s1.substr(2, 2) << endl;
	cout << s1.find("od") << endl;
	cout << s1.find("od", 5) << endl;
	int od_index = s1.find("od");
	cout << s1.find("od", od_index + 2) << endl;
	cout << (s1.find("korea") == string::npos) << endl;

	return 0;
}


/*기초문제 2*/

int main()
{
	ofstream fout;
	fout.open("example.txt");

	string s2 = "Objective Oriented Programming";
	fout << s2 << endl;
	fout << "Random Variables" << endl;
	fout << "Linear Algebra" << endl;
	fout.close();

	ifstream fin;
	string s1;
	fin.open("example.txt");
	if (!fin)
	{
		cout << "Error, no such file exists" << endl;
		exit(100);
	}


	while (getline(fin, s1))
	{
		cout << s1 << endl;
	}



//	while (true)
//	{
//		fin >> s1;
//		if (!fin)
//			break;
//		cout << s1 << endl;
//	}

	fin.close();

	return 0;
}


/*기초문제 3*/

int main()
{
	double d1 = 1.23456789;

	cout << d1 << endl;

	cout.width(10);
	cout.precision(3);
	cout << d1 << endl;

	char ch1;
	char ch2;

	cin >> ch1;
	cout << '(' << ch1 << ')' << endl;

	cin.ignore();

	cin.unsetf(ios::skipws);
	cin >> ch2;
	cout << '(' << ch2 << ')' << endl;

	cin.setf(ios::skipws);

	return 0;
}


/*기초문제 4*/

bool getStu(ifstream& fin, int& id, int& exam1, int& exam2, int& exam3)
{
	fin >> id >> exam1 >> exam2 >> exam3;
	if (!fin)
		return false;
	return true;
}

void calcAvgGrade(int exam1, int exam2, int exam3, int& avg, char& grade)
{
	avg = (exam1 + exam2 + exam3) / 3;
	if (avg >= 90)
		grade = 'A';
	else if (avg >= 80)
		grade = 'B';
	else
		grade = 'F';
}

void writeStu(ofstream& fout, int id, int avg, char grade)
{
	fout.fill('0');
	fout << setw(4) << id;
	fout.fill(' ');
	fout << setw(4) << avg;
	fout << setw(4) << grade << endl;
}

int main()
{
	ifstream fin("ch7STUFL.DAT");
	ofstream fout("grade.txt");

	int id, exam1, exam2, exam3, avg;
	char grade;


	while (getStu(fin, id, exam1, exam2, exam3))
	{
		calcAvgGrade(exam1, exam2, exam3, avg, grade);
		writeStu(fout, id, avg, grade);
	}

	fin.close();
	fout.close();

	cout << "end";

	return 0;

}


/*응용문제 1*/

int main()
{
	string city;
	string area;
	string street;
	string building;

	cout << "시 : ";
	cin >> city;
	cout << "구 : ";
	cin >> area;
	cout << "로 : ";
	cin >> street;
	cout << "건물명 : ";
	cin >> building;

	cout << "집 주소 : " << city << area << street << building << endl;
}


/*응용문제 2*/

int main()
{
	string data = "사랑, 프로그래밍, 의자, 사랑의바보, 영통역, 천년의사랑, 냉장고, 객체지향";
	string key;
	int count=0;
	cout << "키워드 : ";
	cin >> key;
	cout << "검색결과 : ";

	data += ',';

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == ',')
		{

			string temp;
			if (count == 0)
				temp = data.substr(count, i - count);

			else
				temp = data.substr(count+1, i - count-1);

			if (temp.find(key) != string::npos)
				cout << temp<<"  ";
			count = i+1;
		}
	}
	return 0;
}


/*응용문제 3*/

int main()
{
	ofstream fout("matrix.txt");
	srand((unsigned int)time(0));

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			fout << rand() % 101 << ' ';

		fout << '\n';
	}

	fout.close();

	return 0;
}


/*응용문제 4*/

int main()
{
	ifstream fin;
	ofstream fout("test_sum.txt");

	fin.open("text1.txt");
	char ch;

	while (true)
	{
		fin.get(ch);
		if (!fin)
			break;
		fout << ch;
	}
	fout << "\n\n";

	fin.close();

	fin.open("text2.txt");
	while (true)
	{
		fin.get(ch);
		if (!fin)
			break;
		fout << ch;
	}
	fin.close();
	fout.close();

	return 0;
}


/*응용문제 5*/

int main()
{
	ifstream fin("original_file.txt");
	ofstream fout("result_file.txt");

	string s;
	string res = "";

	int len;
	int index = 0;
	cout << "length = ";
	cin >> len;
	while (getline(fin, s))
	{
		res += s;
		res += ' ';
	}

	fout.unsetf(ios::skipws);
	while (true)
	{
		if (res[index] == ' ')
			fout << res.substr(++index, len) << '\n';
		else
			fout << res.substr(index, len) << '\n';
		if (res.substr(index, len).size() != len)
			break;
		index += len;
		
	}
	

	return 0;
}
