
#pragma once
#include<iostream>
#include <malloc.h>
using namespace std;

class Matrix
{
public:
	// Статический член для подсчета всех элементов созданных матриц
	static int sum_member;
	// Конструктор по умолчанию
	Matrix();
	// Конструктор с параметрами
	Matrix(int row, int column, int* factor);
	// Конструктор копирования
	Matrix(const Matrix& other);
	// Деструктор
	~Matrix();
	// Метод преобразования матрицы в строку
	char* to_string();
	// Сортировка по первому эл. строки
	void row_bubble_sort();
	// Сортировка по первому эл. столбца
	void column_bubble_sort();
	// Метод поиска числа по значению
	int search_number_rank(int number);
	// Метод замены переменных в матрице
	void replace(int number, int rep_number);
	// Метод изменения одного числа в нужной строке и столбце
	void set_number(int tmp_row, int tmp_column);
	void set_number(int tmp_row, int tmp_column, int number);
	// Метод взятия кол-ва строк в матрице
	int get_row_rank();
	// Метод взятия кол-ва столбцов в матрице
	int get_column_rank();
	// Метод взятия адреса матрицы объекта
	int** get_matrix_pointer();	
	// Метод взятия числа в нужной строке и столбце
	int get_number(int tmp_row, int tmp_column);
	// Перегрузка оператора сложения
	friend Matrix operator +(const Matrix& o1, const Matrix& o2);
	// Перегрузка оператора вычитания
	friend Matrix operator -(const Matrix& o1, const Matrix& o2);
	// Перегрузка оператора индексирования
	int* operator [](int index);
	// Перегрузка оператора присваивания
	Matrix& operator=(const Matrix& other);
private:
	// Столбцы
	int row;
	// Строки
	int column;
	// Динамический массив
	int** uber;
};