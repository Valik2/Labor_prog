#pragma once
#include "Matrix.h"

class MatrixOne :public Matrix
{
public:
	// Конструктор по умоланию
	MatrixOne();
	// Конструктор с параметрами
	MatrixOne(int row, int column);
	// Деструктор
	~MatrixOne();
	//
	void replace(int number, int rep_number) override;
};