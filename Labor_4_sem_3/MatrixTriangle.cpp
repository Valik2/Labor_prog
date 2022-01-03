
#include "MatrixTriangle.h"

MatrixTriangle::MatrixTriangle():Matrix()
{
	factor = NULL;
}

MatrixTriangle::MatrixTriangle(int row, int column,int* factor,const char* mode):Matrix()
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
	if (mode != "high" && mode != "low")
	{
		throw exception("This mode is unknown.");
	}

	this->row = row;
	this->column = column;

	this->factor = new int[row * column];
	for (int i = 0; i < row * column; i++)
	{
		this->factor[i] = factor[i];
	}

	uber = new int* [row];
	for (int i = 0; i < row; i++)
	{
		uber[i] = new int[column];
	}

	if (mode == "high")
	{
		int pp = 0;
		for (int i = 0; i < row; i++)
		{
			for (int k = 0; k < column; k++)
			{
				uber[i][k] = 0;
			}
			for (int k = i; k < column; k++)
			{
				uber[i][k] = factor[pp];
				pp++;
			}
		}
	}
	if (mode == "low")
	{
		int pp = 0;
		for (int i = 0; i < row; i++)
		{
			for (int k = 0; k < column; k++)
			{
				uber[i][k] = 0;
			}
			for (int k = 0; k < i; k++)
			{
				uber[i][k] = factor[pp];
				pp++;
			}
		}
	}
	
}

MatrixTriangle::MatrixTriangle(const MatrixTriangle& other):Matrix()
{
	this->column = other.column;
	this->row = other.row;

	factor = new int[row * column];

	for (int i = 0; i < row * column; i++)
	{
		factor[i] = other.factor[i];
	}

	uber = new int* [row];
	for (int i = 0; i < row; i++)
	{
		uber[i] = new int[column];
	}

	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < column; k++)
		{
			uber[i][k] = other.uber[i][k];
		}
	}
}

MatrixTriangle::~MatrixTriangle()
{
	delete[] factor;
}

int* MatrixTriangle::get_factor_pointer()
{
	if (factor == NULL)
	{
		return NULL;
	}
	int* factor1 = new int[row*column];
	for (int i = 0; i < row * column; i++)
	{
		factor1[i] = factor[i];
	}
	return factor1;
}

void MatrixTriangle::set_factor(int* factor, char* mode)
{
	if (mode != "high" && mode != "low")
	{
		throw exception("This mode is unknown.");
	}
	delete[] this->factor;
	this->factor = new int[row * column];
	for (int i = 0; i < row * column; i++)
	{
		this->factor[i] = factor[i];
	}
	if (mode == "high")
	{
		int pp = 0;
		for (int i = 0; i < row; i++)
		{
			for (int k = 0; k < column; k++)
			{
				uber[i][k] = 0;
			}
			for (int k = i; k < column; k++)
			{
				uber[i][k] = factor[pp];
				pp++;
			}
		}
	}
	if (mode == "low")
	{
		int pp = 0;
		for (int i = 0; i < row; i++)
		{
			for (int k = 0; k < column; k++)
			{
				uber[i][k] = 0;
			}
			for (int k = 0; k < i; k++)
			{
				uber[i][k] = factor[pp];
				pp++;
			}
		}
	}
}