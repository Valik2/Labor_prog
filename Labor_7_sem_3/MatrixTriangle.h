#pragma once
#include "Matrix.h"

class MatrixTriangle :public Matrix
{
public:
	// ����������� �� ���������
	MatrixTriangle();
	// ����������� � �����������
	MatrixTriangle(int row, int column,int* factor,const char* mode);
	// ����������� �����������
	MatrixTriangle(const MatrixTriangle& other);
	// ����������
	~MatrixTriangle();
	// ����� ������ ������ ������� �����
	int* get_factor_pointer();
	// ����� ��������� ����������� ������� � ������� ������ ����������� �������
	void set_factor(int* factor, char* mode);
	//
	void replace(int number, int rep_number) override;
private:
	// ���������� ������
	int* factor;
};