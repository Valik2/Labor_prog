
#include "Matrix.h"
#include "Catch2/catch.hpp"


TEST_CASE("Overloading the addition operator")
{

	int* mass = new int[4];
	mass[0] = 2;
	mass[1] = 1;
	mass[2] = 2;
	mass[3] = 1;
	Matrix A(2, 2, mass);
	mass[0] = -1;
	mass[1] = 1;
	mass[2] = 1;
	mass[3] = 3;
	Matrix B(2, 2, mass);
	Matrix C = A + B;
	REQUIRE(C.get_number(0, 0) == 1);
	REQUIRE(C.get_number(0, 1) == 2);
	REQUIRE(C.get_number(1, 0) == 3);
	REQUIRE(C.get_number(1, 1) == 4);

}

TEST_CASE("Overloading the subtraction operator")
{
	int* mass = new int[4];
	mass[0] = 10;
	mass[1] = 10;
	mass[2] = 10;
	mass[3] = 0;
	Matrix A(2, 2, mass);
	mass[0] = 6;
	mass[1] = 7;
	mass[2] = 8;
	mass[3] = -1;
	Matrix B(2, 2, mass);
	Matrix C = A - B;
	REQUIRE(C.get_number(0, 0) == 4);
	REQUIRE(C.get_number(0, 1) == 3);
	REQUIRE(C.get_number(1, 0) == 2);
	REQUIRE(C.get_number(1, 1) == 1);
}

TEST_CASE("Overloading the indexing operation")
{
	int* mass = new int[4];
	mass[0] = 10;
	mass[1] = 10;
	mass[2] = 10;
	mass[3] = 0;
	Matrix A(2, 2, mass);
	A[1][1] = 3;
	REQUIRE(A.get_number(1, 1) == 3);
}

TEST_CASE("Exceptions test")
{
	int* mass = new int[6];
	mass[0] = 10;
	mass[1] = 10;
	mass[2] = 10;
	mass[3] = 0;
	Matrix A(2, 2, mass);
	mass[0] = 2;
	mass[1] = 4;
	mass[2] = 6;
	mass[3] = 8;
	mass[4] = 10;
	mass[5] = 12;
	Matrix B(2, 3, mass);
	try
	{
		Matrix C = A + B;
	}
	catch (const exception& ex)
	{
		cout << "Catch -> " << ex.what() << endl;
	}
	try
	{
		Matrix C = A - B;
	}
	catch (const exception& ex)
	{
		cout << "Catch -> " << ex.what() << endl;
	}
	try
	{
		A[-1][3] = 2;
	}
	catch (const exception& ex)
	{
		cout << "Catch -> " << ex.what() << endl;
	}
}

TEST_CASE("Îverloading operator as replacing the number at the specified position")
{
	int* mass = new int[4];
	mass[0] = 1;
	mass[1] = 12;
	mass[2] = 3;
	mass[3] = 6;
	Matrix A(2, 2, mass);
	A.set_number(0, 1);
}

TEST_CASE("Write to file and output from it")
{
	int* mass = new int[12];
	mass[0] = 1;
	mass[1] = 3;
	mass[2] = 7;
	mass[3] = -1;
	mass[4] = 4;
	mass[5] = 144;
	mass[6] = 5;
	mass[7] = -1;
	mass[8] = 4;
	mass[9] = 587;
	mass[10] = 0;
	mass[11] = 22;
	Matrix A(3, 4, mass);
	ofstream ofs;
	ofs.open(file_text, ios::app | ios::out);
	if (!ofs.is_open())
	{
		throw exception("File open error.");
	}
	ofs << A << endl;
	ofs.close();

	ifstream ifs;
	ifs.open(file_text, ios::app | ios::in);
	if (!ifs.is_open())
	{
		throw exception("File open error.");
	}
	Matrix B;
	ifs >> B;

	REQUIRE(A.get_column_rank() == B.get_column_rank());
	REQUIRE(A.get_row_rank() == B.get_row_rank());

	for (int i = 0; i < A.get_row_rank(); i++)
	{
		for (int j = 0; j < A.get_column_rank(); j++)
		{
			REQUIRE(A[i][j] == B[i][j]);
		}
	}
}

TEST_CASE("Write to binary file and output from it")
{
	fstream file;
	file.open(file_binary, ios::binary | ios::out);
	int* mass = new int[4];
	mass[0] = -3;
	mass[1] = 16;
	mass[2] = 8;
	mass[3] = 7;
	Matrix A(2, 2, mass);
	A.output(file);
	file.close();

	file.open(file_binary, ios::binary | ios::in);
	Matrix B;
	B.input(file);
	file.close();

	REQUIRE(A.get_column_rank() == B.get_column_rank());
	REQUIRE(A.get_row_rank() == B.get_row_rank());
	for (int i = 0; i < A.get_row_rank(); i++)
	{
		for (int j = 0; j < A.get_column_rank(); j++)
		{
			REQUIRE(A[i][j] == B[i][j]);
		}
	}		
}

TEST_CASE("Write to code and output from it")
{
	Matrix A;
	cin >> A;
	cout << A;
}