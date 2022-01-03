
#include "Matrix.h"
#include "Catch2/catch.hpp"

TEST_CASE("Exception processing for constructor with arguments")
{
	
	try
	{
		int* a = new int[3];
		a[0] = 4;
		a[1] = 3;
		a[2] = 2;
		a[3] = 2;
		Matrix AA(2, 2, a);
	}
	catch(const exception& ex)
	{
		cout << "Exception caught! -> " << ex.what() << endl;
	}
	
	try
	{
		int* a = new int[4];
		a[0] = 4;
		a[1] = 3;
		a[2] = 2;
		a[3] = 2;
		Matrix AA(-1, 2, a);
	}
	catch (const exception& ex)
	{
		cout << "Exception caught! -> " << ex.what() << endl;
	}
	try
	{
		int* a = new int[4];
		a[0] = 4;
		a[1] = 3;
		a[2] = 2;
		a[3] = 2;
		Matrix AA(2, -10, a);
	}
	catch (const exception& ex)
	{
		cout << "Exception caught! -> " << ex.what() << endl;
	}
	try
	{
		int* a = new int[4];
		a[0] = 4;
		a[1] = 3;
		a[2] = 2;
		a[3] = 2;
		Matrix AA(0, 2, a);
	}
	catch (const exception& ex)
	{
		cout << "Exception caught! -> " << ex.what() << endl;
	}
}

TEST_CASE("Exception processing for set_number method")
{
	try
	{
		int* a = new int[4];
		a[0] = 4;
		a[1] = 3;
		a[2] = 2;
		a[3] = 2;
		Matrix AA(2, 2, a);
		AA.set_number(16, 2, 7);
	}
	catch (const exception& ex)
	{
		cout << "Exception caught! -> " << ex.what() << endl;
	}
	try
	{
		int* a = new int[4];
		a[0] = 4;
		a[1] = 3;
		a[2] = 2;
		a[3] = 2;
		Matrix AA(2, 2, a);
		AA.set_number(2, -1, 7);
	}
	catch (const exception& ex)
	{
		cout << "Exception caught! -> " << ex.what() << endl;
	}
}

TEST_CASE("Exception processing for get_number method")
{
	try
	{
		int* a = new int[4];
		a[0] = 4;
		a[1] = 3;
		a[2] = 2;
		a[3] = 2;
		Matrix AA(2, 2, a);
		int b = AA.get_number(16, 2);
	}
	catch (const exception& ex)
	{
		cout << "Exception caught! -> " << ex.what() << endl;
	}
	try
	{
		int* a = new int[4];
		a[0] = 4;
		a[1] = 3;
		a[2] = 2;
		a[3] = 2;
		Matrix AA(2, 2, a);
		int b = AA.get_number(2, -1);
	}
	catch (const exception& ex)
	{
		cout << "Exception caught! -> " << ex.what() << endl;
	}
}