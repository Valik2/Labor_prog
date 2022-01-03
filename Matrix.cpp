
#include "Matrix.h"

	Matrix::Matrix()
	{
		row = 0;
		column = 0;
		uber = NULL;
	}
	Matrix::Matrix(int row, int column, int* factor)
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
		if (_msize(factor) / sizeof(*factor) < row * column)
		{
			throw exception("Not enough elements to build a matrix.");
		}
		this->column = column;
		this->row = row;

		uber = new int* [row];
		for (int i = 0; i < row; i++)
		{
			uber[i] = new int[column];
		}
		
		int mass = 0;
		for (int i = 0; i < row; i++)
		{
			for (int k = 0; k < column; k++)
			{
				uber[i][k] = factor[mass];
				mass++;
				sum_member = sum_member + uber[i][k];
			}
		}
	}
	Matrix::Matrix(const Matrix& other)
	{
		this->column = other.column;
		this->row = other.row;

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
				sum_member = sum_member + uber[i][k];
			}
		}
	}
	Matrix::~Matrix()
	{
		for (int i = 0; i < row; ++i)
			delete[] uber[i];
		delete[] uber;
	}
	char* Matrix::to_string()
	{
		char str[1000] = "";
		char buff[12];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				sprintf_s(buff, sizeof(buff), "%d", uber[i][j]);
				strcat_s(str, sizeof(str), buff);
				strcat_s(str, sizeof(str), " ");
			}
			strcat_s(str, sizeof(str), "\n");
		}
		return str;
	}
	void Matrix::row_bubble_sort()
	{
		for (int y = 0; y < row; y++)
		{
			for (int i = 0; i < (row - 1); i++)
			{
				if (uber[i][0] > uber[i + 1][0])
				{
					for (int j = 0; j < column; j++)
					{
						int x = uber[i][j];
						uber[i][j] = uber[i + 1][j];
						uber[i + 1][j] = x;
					}
				}
			}
		}
	}
	void Matrix::column_bubble_sort()
	{
		for (int y = 0; y < row; y++)
		{
			for (int i = 0; i < (column - 1); i++)
			{
				if (uber[0][i] > uber[0][i + 1])
				{
					for (int j = 0; j < row; j++)
					{
						int x = uber[j][i];
						uber[j][i] = uber[j][i + 1];
						uber[j][i + 1] = x;
					}
				}
			}
		}
	}
	int Matrix::search_number_rank(int number)
	{
		int count = 0;
		for (int i = 0; i < row; i++)
		{
			for (int k = 0; k < column; k++)
			{
				if (uber[i][k] == number)
				{
					count++;
				}
			}
		}
		return count;
	}
	void Matrix::replace(int number, int rep_number)
	{
		int count = 0;
		for (int i = 0; i < row; i++)
		{
			for (int k = 0; k < column; k++)
			{
				if (uber[i][k] == number)
				{
					count++;
					uber[i][k] = rep_number;
				}
			}
		}
	}
	void Matrix::set_number(int tmp_row, int tmp_column, int number)
	{
		if (tmp_row < 0 || tmp_row > row)
		{
			throw exception("This row is missing(seter).");
		}
		if (tmp_column < 0 || tmp_column > column)
		{
			throw exception("This column is missing(seter).");
		}
		uber[tmp_row][tmp_column] = number;
	}
	void Matrix::set_number(int tmp_row, int tmp_column)
	{
		if (tmp_row < 0 || tmp_row > row)
		{
			throw exception("This row is missing(seter).");
		}
		if (tmp_column < 0 || tmp_column > column)
		{
			throw exception("This column is missing(seter).");
		}
		uber[tmp_row][tmp_column] = 0;
	}
	int Matrix::get_row_rank()
	{
		return row;
	}
	int Matrix::get_column_rank()
	{
		return column;
	}
	int** Matrix::get_matrix_pointer()
	{
		if (uber == NULL)
		{
			return NULL;
		}
		int** uber1 = new int* [row];
		for (int i = 0; i < row; i++)
		{
			uber1[i] = new int[column];
		}

		for (int i = 0; i < row; i++)
		{
			for (int k = 0; k < column; k++)
			{
				uber1[i][k] = uber[i][k];
			}
		}
		return uber1;
	}
	int Matrix::get_number(int tmp_row, int tmp_column)
	{
		if (tmp_row < 0 || tmp_row > row)
		{
			throw exception("This row is missing(geter).");
		}
		if (tmp_column < 0 || tmp_column > column)
		{
			throw exception("This column is missing(geter).");
		}
		return uber[tmp_row][tmp_column];
	}
	Matrix operator + (const Matrix& o1, const Matrix& o2)
	{
		if (o1.row == 0 && o2.row == 0)
		{
			Matrix temp;
			return temp;
		}
		if (o1.row != 0 && o2.row == 0)
		{
			Matrix temp(o1);
			return temp;
		}
		if (o1.row == 0 && o2.row != 0)
		{
			Matrix temp(o2);
			return temp;
		}
		if ((o1.column != o2.column) || (o1.row != o2.row))
		{
			throw exception("Matrix of different sizes cannot be added.");
		}
		int index = 0;
		int* mass1 = new int[o1.row * o1.column];
		for (int i = 0; i < o1.row; i++)
		{
			for (int j = 0; j < o1.column; j++)
			{
				mass1[index] = o1.uber[i][j] + o2.uber[i][j];
				index++;
			}
		}
		Matrix temp(o1.row, o1.column, mass1);
		return temp;
	}
	Matrix operator - (const Matrix& o1, const Matrix& o2)
	{
		if (o1.row == 0 && o2.row == 0)
		{
			Matrix temp;
			return temp;
		}
		if (o1.row != 0 && o2.row == 0)
		{
			Matrix temp(o1);
			return temp;
		}
		if (o1.row == 0 && o2.row != 0)
		{
			int* mass1 = new int[o2.row * o2.column];
			int index = 0;
			for (int i = 0; i < o2.row; i++)
			{
				for (int j = 0; j < o2.column; j++)
				{
					mass1[index] = o2.uber[i][j] * (-1);
					index++;
				}
			}
			Matrix temp(o2.row, o2.column, mass1);
			return temp;
		}
		if ((o1.column != o2.column) || (o1.row != o2.row))
		{
			throw exception("Matrices of different sizes cannot be subtracted.");
		}
		int index = 0;
		int* mass1 = new int[o1.row * o1.column];
		for (int i = 0; i < o1.row; i++)
		{
			for (int j = 0; j < o1.column; j++)
			{
				mass1[index] = o1.uber[i][j] - o2.uber[i][j];
				index++;
			}
		}
		Matrix temp(o1.row, o1.column, mass1);
		return temp;
	}
	int* Matrix::operator[](int index)	// Нарушение инкапсуляции // Возвращается указатель, вернуть копию
	{
		if (index < 0)
		{
			throw exception("The value cannot be less than 0.");
		}
		int* mass = uber[index];
		return mass;
	}
	Matrix& Matrix::operator=(const Matrix& other)
	{
		this->column = other.column;
		this->row = other.row;

		if (uber != NULL)
		{
			for (int i = 0; i < row; ++i)
				delete[] uber[i];
			delete[] uber;
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
		return *this;
	}