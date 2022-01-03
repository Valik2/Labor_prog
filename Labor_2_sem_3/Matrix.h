
#pragma once
#include<iostream>
#include <malloc.h>
using namespace std;

class Matrix
{
public:
	// ����������� ���� ��� �������� ���� ��������� ��������� ������
	static int sum_member;
	// ����������� �� ���������
	Matrix();
	// ����������� � �����������
	Matrix(int row, int column, int* factor);
	// ����������� �����������
	Matrix(const Matrix& other);
	// ����������
	~Matrix();
	// ����� �������������� ������� � ������
	char* to_string();
	// ���������� �� ������� ��. ������
	void row_bubble_sort();
	// ���������� �� ������� ��. �������
	void column_bubble_sort();
	// ����� ������ ����� �� ��������
	int search_number_rank(int number);
	// ����� ������ ���������� � �������
	void replace(int number, int rep_number);
	// ����� ��������� ������ ����� � ������ ������ � �������
	void set_number(int tmp_row, int tmp_column);
	void set_number(int tmp_row, int tmp_column, int number);
	// ����� ������ ���-�� ����� � �������
	int get_row_rank();
	// ����� ������ ���-�� �������� � �������
	int get_column_rank();
	// ����� ������ ������ ������� �������
	int** get_matrix_pointer();	
	// ����� ������ ����� � ������ ������ � �������
	int get_number(int tmp_row, int tmp_column);
	// ���������� ��������� ��������
	friend Matrix operator +(const Matrix& o1, const Matrix& o2);
	// ���������� ��������� ���������
	friend Matrix operator -(const Matrix& o1, const Matrix& o2);
	// ���������� ��������� ��������������
	int* operator [](int index);
	// ���������� ��������� ������������
	Matrix& operator=(const Matrix& other);
private:
	// �������
	int row;
	// ������
	int column;
	// ������������ ������
	int** uber;
};