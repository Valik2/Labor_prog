
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