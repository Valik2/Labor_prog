#pragma once
#include "Matrix.h"

class MatrixTriangle :public Matrix
{
public:
	// Конструктор по умолчанию
	MatrixTriangle();
	// Конструктор с параметрами
	MatrixTriangle(int row, int column,int* factor,const char* mode);
	// Конструктор копирования
	MatrixTriangle(const MatrixTriangle& other);
	// Деструктор
	~MatrixTriangle();
	// Метод взятия адреса массива чисел
	int* get_factor_pointer();
	// Метод изменения треугольной матрицы с помощью нового одномерного массива
	void set_factor(int* factor, char* mode);
	//
	void replace(int number, int rep_number) override;
private:
	// Одномерный массив
	int* factor;
};