
#pragma once
#include "Matrix.h"
#include "MatrixOne.h"
#include "MatrixTriangle.h"

using namespace std;

class List
{
public:
	// ����������� � ����������� -> 1 �������
	List(Matrix& obj);
	// ���������� ������
	~List();
	// ����� ���������� ������
	void add_node(Matrix& object);
	// ����� �������� ������
	void delete_node();
	// ����� ������� ������ �� ������
	void add_node_by_number(Matrix& obj, int value);
	// ����� �������� ������ �� ������
	void delete_node_by_number(int value);
	// ����� ������ �������� �� ������� �������� � �������
	char* find_by_number(int value);
	// ����� ������ ������� �� ���������� �����
	char* find_by_row_rank(int value);
	// ����� ������ ������� �� ���������� �������
	char* find_by_column_rank(int value);
	// ����� ������ ������ �� �����
	char* to_string();
	// ����� ��������� ����������� ����� replace �� ���� ������� � ������
	void list_polimorph_replace(int num,int rep_num);
private:
	// ��������� -> ������
	struct Node 
	{
		// ������
		Matrix* object;
		// ��������� �� ��������� ������
		Node* next;
	};
	// ��������� �� ������ ������
	Node* head;
};