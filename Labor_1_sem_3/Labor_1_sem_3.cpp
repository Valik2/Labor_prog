
#include<iostream>
#include"Matrix.h"

using namespace std;

int Matrix::sum_member = 0;

void test1()
{
	bool control = true;
	int a = 0;
	int** b = NULL;
	Matrix A;
	if (a != A.get_row_rank())
	{
		control = false;
	}
	if (a != A.get_column_rank())
	{
		control = false;
	}
	if (b != A.get_matrix_pointer())
	{
		control = false;
	}

	if (control == true)
	{
		cout << "Тест 1 пройден" << endl;
	}
	if (control == false)
	{
		cout << "Тест 1 не пройден" << endl;
	}
}
void test2()
{
	bool control = true;
	int mass1[3][3];
	mass1[0][0] = 9;
	mass1[0][1] = 8;
	mass1[0][2] = 7;
	mass1[1][0] = 6;
	mass1[1][1] = 5;
	mass1[1][2] = 4;
	mass1[2][0] = 3;
	mass1[2][1] = 2;
	mass1[2][2] = 1;

	int mass2[9] = { 9,8,7,6,5,4,3,2,1 };
	Matrix A(3, 3, mass2);
	Matrix B(A);

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (mass1[i][k] != A.get_number(i, k))
			{
				control = false;
			}
		}
	}

	mass1[0][0] = 3;
	mass1[0][1] = 2;
	mass1[0][2] = 1;
	mass1[1][0] = 6;
	mass1[1][1] = 5;
	mass1[1][2] = 4;
	mass1[2][0] = 9;
	mass1[2][1] = 8;
	mass1[2][2] = 7;

	A.row_bubble_sort();
	printf("%s", A.to_string());
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (mass1[i][k] != A.get_number(i, k))
			{
				control = false;
			}
		}
	}
	cout << endl;

	mass1[0][0] = 7;
	mass1[0][1] = 8;
	mass1[0][2] = 9;
	mass1[1][0] = 4;
	mass1[1][1] = 5;
	mass1[1][2] = 6;
	mass1[2][0] = 1;
	mass1[2][1] = 2;
	mass1[2][2] = 3;

	
	B.column_bubble_sort();
	printf("%s", B.to_string());
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (mass1[i][k] != B.get_number(i, k))
			{
				control = false;
			}
		}
	}

	if (control == true)
	{
		cout << "Тест 2 пройден" << endl;
	}
	if (control == false)
	{
		cout << "Тест 2 не пройден" << endl;
	}
}
void test3()
{
	bool control = true;
	int AA = 2;
	int BB = 3;
	int mass1[2][3];
	mass1[0][0] = 3;
	mass1[0][1] = 6;
	mass1[0][2] = 1;
	mass1[1][0] = 3;
	mass1[1][1] = 9;
	mass1[1][2] = 0;

	int mass0[6] = { 3,6,1,3,9,0 };
	Matrix A(2, 3, mass0);

	if (A.search_number_rank(3) != 2)
	{
		control = false;
	}
	A.replace(3, 4);

	mass1[0][0] = 4;
	mass1[0][1] = 6;
	mass1[0][2] = 1;
	mass1[1][0] = 4;
	mass1[1][1] = 9;
	mass1[1][2] = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (mass1[i][k] != A.get_number(i, k))
			{
				control = false;
			}
		}
	}

	A.set_number(0, 1, 10);
	if (A.get_number(0, 1) != 10)
	{
		control = false;
	}

	Matrix B(A);

	mass1[0][0] = 4;
	mass1[0][1] = 10;
	mass1[0][2] = 1;
	mass1[1][0] = 4;
	mass1[1][1] = 9;
	mass1[1][2] = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (mass1[i][k] != B.get_number(i, k))
			{
				control = false;
			}
		}
	}

	if (A.get_row_rank() != AA)
	{
		control = false;
	}
	if (A.get_column_rank() != BB)
	{
		control = false;
	}
	if (A.sum_member != 140)
	{
		control = false;
	}
	
	if (control == true)
	{
		cout << "Тест 3 пройден" << endl;
	}
	if (control == false)
	{
		cout << "Тест 3 не пройден" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	test1();
	test2();
	test3();
	return 0;
}