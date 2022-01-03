
#include "MatrixOne.h"

MatrixOne::MatrixOne()
{
}

MatrixOne::MatrixOne(int row, int column):Matrix()
{
	if (row < 0)
	{
		throw exception("The number of rows is less than 0.");
	}
	if (column < 0)
	{
		throw exception("The number of column is less than 0.");
	}
	if (row == 0 || column == 0)
	{
		throw exception("Empty matrix detected.");
	}
	this->row = row;
	this->column = column;

	uber = new int* [row];
	for (int i = 0; i < row; i++)
	{
		uber[i] = new int[column];
	}

	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < column; k++)
		{
			uber[i][k] = 0;
			if (i == k)
			{
				uber[i][k] = 1;
			}
		}
	}
}

MatrixOne::~MatrixOne()
{
}

void MatrixOne::replace(int number, int rep_number)
{

	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < column; k++)
		{
			if (uber[i][k] == number && number != 1)
			{
				uber[i][k] = rep_number;
			}
		}
	}
}