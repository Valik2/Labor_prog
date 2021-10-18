
#include "Matrix.h"

	Matrix::Matrix()
	{
		row = 0;
		column = 0;
		factor = NULL;
		uber = NULL;
	}
	Matrix::Matrix(int row, int column, int* factor)
	{
		this->column = column;
		this->row = row;
		this->factor = factor;

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
	char* Matrix::to_string()								// Метод преобразования матрицы в строку
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
	void Matrix::row_bubble_sort()								// Сортировка по первому эл. строки
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
	void Matrix::column_bubble_sort()								// Сортировка по первому эл. столбца
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
	int Matrix::search_number_rank(int number)					// Метод поиска числа по значению
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
	void Matrix::replace(int number, int rep_number)				// Метод замены переменных в матрице
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
	void Matrix::set_number(int tmp_row, int tmp_column, int number)		// Метод изменения одного числа в нужной строке и столбце
	{
		uber[tmp_row][tmp_column] = number;
	}
	int Matrix::get_row_rank()												// Метод взятия кол-ва строк в матрице
	{
		return row;
	}
	int Matrix::get_column_rank()											// Метод взятия кол-ва столбцов в матрице
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
	int Matrix::get_number(int tmp_row, int tmp_column)					// Метод взятия числа в нужной строке и столбце
	{
		return uber[tmp_row][tmp_column];
	}