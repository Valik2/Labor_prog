
#include "MatrixOne.h"
#include "MatrixTriangle.h"
#include "Matrix.h"
#include "List.h"
#include "Catch2/catch.hpp"

//TEST_CASE("Overloading the addition operator")
//{
//
//	int* mass = new int[4];
//	mass[0] = 2;
//	mass[1] = 1;
//	mass[2] = 2;
//	mass[3] = 1;
//	Matrix A(2, 2, mass);
//	mass[0] = -1;
//	mass[1] = 1;
//	mass[2] = 1;
//	mass[3] = 3;
//	Matrix B(2, 2, mass);
//	Matrix C = A + B;
//	REQUIRE(C.get_number(0, 0) == 1);
//	REQUIRE(C.get_number(0, 1) == 2);
//	REQUIRE(C.get_number(1, 0) == 3);
//	REQUIRE(C.get_number(1, 1) == 4);
//
//}
//
//TEST_CASE("Overloading the subtraction operator")
//{
//	int* mass = new int[4];
//	mass[0] = 10;
//	mass[1] = 10;
//	mass[2] = 10;
//	mass[3] = 0;
//	Matrix A(2, 2, mass);
//	mass[0] = 6;
//	mass[1] = 7;
//	mass[2] = 8;
//	mass[3] = -1;
//	Matrix B(2, 2, mass);
//	Matrix C = A - B;
//	REQUIRE(C.get_number(0, 0) == 4);
//	REQUIRE(C.get_number(0, 1) == 3);
//	REQUIRE(C.get_number(1, 0) == 2);
//	REQUIRE(C.get_number(1, 1) == 1);
//}
//
//TEST_CASE("Overloading the indexing operation")
//{
//	int* mass = new int[4];
//	mass[0] = 10;
//	mass[1] = 10;
//	mass[2] = 10;
//	mass[3] = 0;
//	Matrix A(2, 2, mass);
//	A[1][1] = 3;
//	REQUIRE(A.get_number(1, 1) == 3);
//}
//
//TEST_CASE("Exceptions test")
//{
//	int* mass = new int[6];
//	mass[0] = 10;
//	mass[1] = 10;
//	mass[2] = 10;
//	mass[3] = 0;
//	Matrix A(2, 2, mass);
//	mass[0] = 2;
//	mass[1] = 4;
//	mass[2] = 6;
//	mass[3] = 8;
//	mass[4] = 10;
//	mass[5] = 12;
//	Matrix B(2, 3, mass);
//	try
//	{
//		Matrix C = A + B;
//	}
//	catch (const exception& ex)
//	{
//		cout << "Catch -> " << ex.what() << endl;
//	}
//	try
//	{
//		Matrix C = A - B;
//	}
//	catch (const exception& ex)
//	{
//		cout << "Catch -> " << ex.what() << endl;
//	}
//	try
//	{
//		A[-1][3] = 2;
//	}
//	catch (const exception& ex)
//	{
//		cout << "Catch -> " << ex.what() << endl;
//	}
//}
//
//TEST_CASE("Îverloading operator as replacing the number at the specified position")
//{
//	int* mass = new int[4];
//	mass[0] = 1;
//	mass[1] = 12;
//	mass[2] = 3;
//	mass[3] = 6;
//	Matrix A(2, 2, mass);
//	A.set_number(0, 1);
//}
//
//TEST_CASE("Write to file and output from it")
//{
//	int* mass = new int[12];
//	mass[0] = 1;
//	mass[1] = 3;
//	mass[2] = 7;
//	mass[3] = -1;
//	mass[4] = 4;
//	mass[5] = 144;
//	mass[6] = 5;
//	mass[7] = -1;
//	mass[8] = 4;
//	mass[9] = 587;
//	mass[10] = 0;
//	mass[11] = 22;
//	Matrix A(3, 4, mass);
//	ofstream ofs;
//	ofs.open(file_text, ios::app | ios::out);
//	if (!ofs.is_open())
//	{
//		throw exception("File open error.");
//	}
//	ofs << A << endl;
//	ofs.close();
//
//	ifstream ifs;
//	ifs.open(file_text, ios::app | ios::in);
//	if (!ifs.is_open())
//	{
//		throw exception("File open error.");
//	}
//	Matrix B;
//	ifs >> B;
//
//	REQUIRE(A.get_column_rank() == B.get_column_rank());
//	REQUIRE(A.get_row_rank() == B.get_row_rank());
//
//	for (int i = 0; i < A.get_row_rank(); i++)
//	{
//		for (int j = 0; j < A.get_column_rank(); j++)
//		{
//			REQUIRE(A[i][j] == B[i][j]);
//		}
//	}
//}
//
//TEST_CASE("Write to binary file and output from it")
//{
//	fstream file;
//	file.open(file_binary, ios::binary | ios::out);
//	int* mass = new int[4];
//	mass[0] = -3;
//	mass[1] = 16;
//	mass[2] = 8;
//	mass[3] = 7;
//	Matrix A(2, 2, mass);
//	A.output(file);
//	file.close();
//
//	file.open(file_binary, ios::binary | ios::in);
//	Matrix B;
//	B.input(file);
//	file.close();
//
//	REQUIRE(A.get_column_rank() == B.get_column_rank());
//	REQUIRE(A.get_row_rank() == B.get_row_rank());
//	for (int i = 0; i < A.get_row_rank(); i++)
//	{
//		for (int j = 0; j < A.get_column_rank(); j++)
//		{
//			REQUIRE(A[i][j] == B[i][j]);
//		}
//	}		
//}
//
//TEST_CASE("Write to code and output from it")
//{
//	Matrix A;
//	cin >> A;
//	cout << A;
//}
//
//TEST_CASE("Test class MatrixOne")
//{
//	int* mass = new int[4];
//	mass[0] = 2;
//	mass[1] = 1;
//	mass[2] = 2;
//	mass[3] = 1;
//	Matrix GG(2, 2, mass);
//	MatrixOne A(2, 2);
//	MatrixOne B(2, 2);
//
//	REQUIRE(A[0][0] == 1);
//	REQUIRE(A[0][1] == 0);
//	REQUIRE(A[1][0] == 0);
//	REQUIRE(A[0][0] == 1);
//
//	Matrix CC = A + B;
//
//	REQUIRE(CC[0][0] == 2);
//	REQUIRE(CC[0][1] == 0);
//	REQUIRE(CC[1][0] == 0);
//	REQUIRE(CC[0][0] == 2);
//}
//
//TEST_CASE("Test class MatrixTriangle")
//{
//	int* mass = new int[12];
//	mass[0] = 1;
//	mass[1] = 3;
//	mass[2] = 7;
//	mass[3] = -1;
//	mass[4] = 4;
//	mass[5] = 144;
//	mass[6] = 5;
//	mass[7] = -1;
//	mass[8] = 4;
//	mass[9] = 587;
//	mass[10] = 0;
//	mass[11] = 22;
//	const char* text1 = "low";
//	const char* text2 = "high";
//	MatrixTriangle A(3, 4, mass, text1);
//
//	REQUIRE(A[0][0] == 0);
//	REQUIRE(A[0][1] == 0);
//	REQUIRE(A[0][2] == 0);
//	REQUIRE(A[0][3] == 0);
//	REQUIRE(A[1][0] == 1);
//	REQUIRE(A[1][1] == 0);
//	REQUIRE(A[1][2] == 0);
//	REQUIRE(A[1][3] == 0);
//	REQUIRE(A[2][0] == 3);
//	REQUIRE(A[2][1] == 7);
//	REQUIRE(A[2][2] == 0);
//	REQUIRE(A[2][3] == 0);
//
//	MatrixTriangle B(3, 4, mass, text2);
//
//	REQUIRE(B[0][0] == 1);
//	REQUIRE(B[0][1] == 3);
//	REQUIRE(B[0][2] == 7);
//	REQUIRE(B[0][3] == -1);
//	REQUIRE(B[1][0] == 0);
//	REQUIRE(B[1][1] == 4);
//	REQUIRE(B[1][2] == 144);
//	REQUIRE(B[1][3] == 5);
//	REQUIRE(B[2][0] == 0);
//	REQUIRE(B[2][1] == 0);
//	REQUIRE(B[2][2] == -1);
//	REQUIRE(B[2][3] == 4);
//
//	MatrixTriangle C(B);
//
//	REQUIRE(C[0][0] == 1);
//	REQUIRE(C[0][1] == 3);
//	REQUIRE(C[0][2] == 7);
//	REQUIRE(C[0][3] == -1);
//	REQUIRE(C[1][0] == 0);
//	REQUIRE(C[1][1] == 4);
//	REQUIRE(C[1][2] == 144);
//	REQUIRE(C[1][3] == 5);
//	REQUIRE(C[2][0] == 0);
//	REQUIRE(C[2][1] == 0);
//	REQUIRE(C[2][2] == -1);
//	REQUIRE(C[2][3] == 4);
//
//	for (int i = 0; i < 12; i++) 
//	{
//		mass[i] = 3;
//	}
//
//	MatrixTriangle D(3, 4, mass, text2);
//
//	REQUIRE(D[0][0] == 3);
//	REQUIRE(D[0][1] == 3);
//	REQUIRE(D[0][2] == 3);
//	REQUIRE(D[0][3] == 3);
//	REQUIRE(D[1][0] == 0);
//	REQUIRE(D[1][1] == 3);
//	REQUIRE(D[1][2] == 3);
//	REQUIRE(D[1][3] == 3);
//	REQUIRE(D[2][0] == 0);
//	REQUIRE(D[2][1] == 0);
//	REQUIRE(D[2][2] == 3);
//	REQUIRE(D[2][3] == 3);
//
//	
//	
//}

TEST_CASE("Test List class")
{
	int* mass = new int[9];
	mass[0] = 1;
	mass[1] = 3;
	mass[2] = 1;
	mass[3] = 3;
	mass[4] = 7;
	mass[5] = 1;
	Matrix A(2, 2, mass);
	MatrixOne B(2, 2);
	MatrixTriangle C(3, 3, mass,"high");
	

	List Name_list(A);
	Name_list.add_node(B);
	Name_list.add_node(C);
	
	Name_list.list_polimorph_replace(1, 0);
	cout << Name_list.to_string();

	REQUIRE(A[0][0] == 0);
	REQUIRE(A[0][1] == 3);
	REQUIRE(A[1][0] == 0);
	REQUIRE(A[1][1] == 3);

	REQUIRE(B[0][0] == 1);
	REQUIRE(B[0][1] == 0);
	REQUIRE(B[1][0] == 0);
	REQUIRE(B[1][1] == 1);
	
	REQUIRE(C[0][0] == 0);
	REQUIRE(C[0][1] == 3);
	REQUIRE(C[0][2] == 0);
	REQUIRE(C[1][0] == 0);
	REQUIRE(C[1][1] == 3);
	REQUIRE(C[1][2] == 7);
	REQUIRE(C[2][0] == 0);
	REQUIRE(C[2][1] == 0);
	REQUIRE(C[2][2] == 0);
}