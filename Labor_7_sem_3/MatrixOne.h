#pragma once
#include "Matrix.h"

class MatrixOne :public Matrix
{
public:
	// ����������� �� ��������
	MatrixOne();
	// ����������� � �����������
	MatrixOne(int row, int column);
	// ����������
	~MatrixOne();
	//
	void replace(int number, int rep_number) override;
};