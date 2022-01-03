
#pragma once
#include "Matrix.h"
#include "MatrixOne.h"
#include "MatrixTriangle.h"

using namespace std;

class List
{
public:
	// Конструктор с параметрами -> 1 элемент
	List(Matrix& obj);
	// Деструктор списка
	~List();
	// Метод добавления записи
	void add_node(Matrix& object);
	// Метод удаления записи
	void delete_node();
	// Метод вставки записи по номеру
	void add_node_by_number(Matrix& obj, int value);
	// Метод удаления записи по номеру
	void delete_node_by_number(int value);
	// Метод поиска объектов по наличию элемента в матрице
	char* find_by_number(int value);
	// Метод поиска записей по количеству строк
	char* find_by_row_rank(int value);
	// Метод поиска записей по количеству колонок
	char* find_by_column_rank(int value);
	// Метод вывода списка на экран
	char* to_string();
	// Метод применяет виртуальный метод replace ко всем записям в списке
	void list_polimorph_replace(int num,int rep_num);
private:
	// Структура -> запись
	struct Node 
	{
		// Данные
		Matrix* object;
		// Указатель на следующую запись
		Node* next;
	};
	// Указатель на Первую запись
	Node* head;
};