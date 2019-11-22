#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

/*기초문제 1*/

int main()
{
	vector<vector<int>> vec(2, vector<int>(3));

	for (vector<int>& v : vec)
	{
		for (int& elem : v)
		{
			cin >> elem;
		}
	}
	for (auto v : vec)
	{
		for (auto elem : v)
		{
			cout << elem << '\t';
		}
		cout << endl;
	}
	auto a = 10;
	auto b = 10.1;
	auto c = 'd';
	cout << a << ", " << b << ", " << c << endl;

	return 0;
}


/*기초문제 2*/

int main()
{
	int ary[3] = { 1,2,3 };
	cout << (ary + 0) << ", " << *(ary + 0) << ", " << ary[0] << endl;
	cout << (ary + 1) << ", " << *(ary + 1) << ", " << ary[1] << endl;
	cout << (ary + 2) << ", " << *(ary + 2) << ", " << ary[2] << endl;

	return 0;
}


/*기초문제 3*/

void print(const int* ar, const int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << ar[i] << ' ';
	}
	cout << endl;
}
int sum(int* begin, int* end)
{
	int* curr = begin;
	int result = 0;
	while (curr != end)
	{
		result += *curr;
		curr++;
	}
	return result;
}

int main()
{
	int ary[] = { 10,20,30,40,50 };
	print(ary, 5);

	int* begin, *end;
	begin = ary;
	end = ary + 5;
	cout << sum(begin, end) << endl;

	return 0;
}


/*기초문제 4*/

int main()
{
	int size;
	cout << "Size: ";
	cin >> size;
	const int len = 10;
	int staticArr[len];

	double* dynamicArr;
	dynamicArr = new double[size];
	for (int i = 0; i < size; i++)
	{
		cout << "dynamic\t";
	}
	cout << endl;

	delete[] dynamicArr;

}


/*기초문제 5*/

int main()
{
	int matrix[2][3] = { {1,2,3}, {4,5,6} };

	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << matrix[row][col] << '\t';
		}
		cout << endl;
	}
	return 0;
}


/*기초문제 6*/

bool found_char(const char* s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return true;
		s++;
	}
	return false;
}

int main()
{
	const char* ch = "phrase";

	for (char c = 'a'; c <= 'z'; c++)
	{
		cout << "[" << c << "] is ";
		if (!found_char(ch, c))
			cout << "NOT ";
		cout << "in " << ch << endl;
	}

	return 0;
}



/*응용문제 1*/

int elements[19] = { -9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9 };

vector<vector<int>> initializer(int row, int col);
void print(const vector<vector<int>> &v);
vector<vector<int>> mult(vector<vector<int>> &v1, vector<vector<int>> &v2);

int main()
{
	vector<vector<int>> mat_A;
	vector<vector<int>> mat_B;

	int row_A, col_A;
	int row_B, col_B;
	cout << "A의 행, 열의 크기를 입력해주세요 :";
	cin >> row_A >> col_A;
	cout << "B의 행, 열의 크기를 입력해주세요 :";
	cin >> row_B >> col_B;

	mat_A=initializer(row_A, col_A);
	mat_B=initializer(row_B, col_B);
	cout << "A 행렬 :"<<endl;
	print(mat_A);

	cout << "B 행렬 :" << endl;
	print(mat_B);

	cout << "AB 곱행렬 : " << endl;
	print(mult(mat_A, mat_B));

	return 0;
}

vector<vector<int>> initializer(int row, int col)
{
	if (row == 0 || col == 0)
	{
		cout << "행렬을 생성할 수 없습니다." << endl;
		exit(100);
	}
	vector<vector<int>> vec;
	vector<int> temp;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.push_back(elements[rand() % 19]);
		}
		vec.push_back(temp);
		temp.clear();
	}
	return vec;
}
void print(const vector<vector<int>>& v)
{
	for (unsigned i = 0; i < v.size(); i++)
	{
		for (unsigned j = 0; j < v[i].size(); j++)
		{
			cout << setw(4) << v[i][j];
		}
		cout << endl;
	}
}
vector<vector<int>> mult(vector<vector<int>> &v1, vector<vector<int>> &v2)
{
	if (v1[0].size() != v2.size())
	{
		cout << "두 행렬을 곱할 수 없습니다." << endl;
		exit(100);
	}
	int sum;
	vector<vector<int>> res_mat;
	vector<int> temp;
	for (unsigned i = 0; i < v1.size(); i++)
	{
		for (unsigned j = 0; j < v2[0].size(); j++)
		{
			sum = 0;
			for (unsigned k = 0; k < v2.size(); k++)
			{
				sum += v1[i][k] * v2[k][j];
			}
			temp.push_back(sum);
		}
		res_mat.push_back(temp);
		temp.clear();
	}

	return res_mat;
}


/*응용문제 2*/

int* make_arr(int n)
{
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = 2 * i + 1;
	}
	return arr;
}
void print_arr(int* a, int n)
{
	cout << "\nOdd Number Array:" << endl;
	while (n)
	{
		cout << *a << " ";
		a++;
		n--;
	}
	cout << endl;
}
int sum_arr(int* a, int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += a[i];
	}
	return s;
}

int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;

	int* arr = make_arr(n);
	print_arr(arr, n);

	int sum = sum_arr(arr, n);
	cout << "\nSum of the array: " << sum << endl;

	delete[] arr;
	return 0;
}


/*응용문제제 3*/

void sort(int* arr, int size)
{
	int temp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
}
int main()
{
	int n;
	while (true)
	{
		int count = 0;
		cout << "Please enter a number: ";
		cin >> n;
		if (n < 2)
		{
			cout << "Wrong number!!!" << endl;
			break;
		}
		cout << "Size of random array: " << n / 2;
		int* arr = new int[n / 2];

		for (int i = 0; i < n / 2; i++)
			arr[i] = rand() % n + 1;
		cout << endl;
		cout << "[ Array ]" << endl;
		for (int i = 0; i < n / 2; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;

		sort(arr, n / 2);
		for (int i = 0; i < n / 2-1; i++)
		{
			if (arr[i] == arr[i + 1])
			{
				count++;
			}

		}
		if (count == 0)
		{
			cout << "Duplicates not found." << endl<<endl;
		}
		else
		{
			cout << "Duplicates found." << endl<<endl;
		}
		delete[] arr;
		
	}
	return 0;
	
}



/*응용문제 4*/
int **buildTable(int n)
{
	int** mat = new int*[n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = 0;
		}
	}

	return mat;
}
void make_identify_matrix(int** table, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				table[i][j] = 1;
		}
	}
}
void printTable(int** table, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << table[i][j] << '\t';
		}
		cout << '\n';
	}
}


int main()
{
	int n = 0;
	cout << "N을 입력하시오: ";
	cin >> n;
	if (n < 1)
	{
		cout << "\n행렬을 생성할 수 없습니다.\n" << endl;
		exit(EXIT_FAILURE);
	}

	int** table = buildTable(n);
	make_identify_matrix(table, n);
	printTable(table, n);

	for (int i = 0; i < n; i++)
		delete[] table[i];
	delete[] table;

	return 0;
}