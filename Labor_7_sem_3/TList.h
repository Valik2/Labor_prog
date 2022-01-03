#pragma once
#include "Matrix.h"
template <class T>
class TList
{
public:
	// Конструктор с параметрами -> 1 элемент
	TList(T& obj);
	// Деструктор списка
	~TList();
	// Метод добавления записи
	void add_node(T& object);
	// Метод удаления записи
	void delete_node();
	// Метод вставки записи по номеру
	void add_node_by_number(T& obj, int value);
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
	void list_polimorph_replace(int num, int rep_num);
private:
	// Структура -> запись
	struct Node
	{
		// Данные
		T* object;
		// Указатель на следующую запись
		Node* next;
	};
	// Указатель на Первую запись
	Node* head;
};

template<class T>
inline TList<T>::TList(T& obj)
{
	Node* NEW_NODE = new Node;
	head = NEW_NODE;
	NEW_NODE->object = &obj;
	NEW_NODE->next = head;
}

template<class T>
inline TList<T>::~TList()
{
	if (head == NULL)
	{
		return;
	}
	Node* current = head->next;
	while (current != head)
	{
		Node* tmp = current->next;
		delete current;
		current = tmp;
	}
	delete head;
}

template<class T>
inline void TList<T>::add_node(T& obj)
{
	Node* current = head;
	if (head == NULL)
	{
		Node* NEW_NODE = new Node;
		head = NEW_NODE;
		NEW_NODE->object = &obj;
		NEW_NODE->next = head;
		return;
	}
	while (current->next != head)
	{
		current = current->next;
	}
	Node* NEW_NODE = new Node;
	NEW_NODE->object = &obj;
	NEW_NODE->next = head;
	current->next = NEW_NODE;
}

template<class T>
inline void TList<T>::delete_node()
{
	if (head == NULL)
	{
		throw exception("Delete from empty list.");
	}
	if (head == head->next)
	{
		Node* tmp = head;
		delete tmp;
		head = NULL;
		return;
	}
	Node* current = head;
	while (current->next->next != head)
	{
		current = current->next;
	}
	Node* tmp = current->next;
	current->next = head;
	delete tmp;
}

template<class T>
inline void TList<T>::add_node_by_number(T& obj, int value)
{
	if (head == NULL)
	{
		Node* NEW_NODE = new Node;
		head = NEW_NODE;
		NEW_NODE->object = &obj;
		NEW_NODE->next = head;
		return;
	}
	if (value < 1)
	{
		throw exception("Unavaliable number.");
	}
	if (value == 1)
	{
		Node* NEW_NODE = new Node;
		NEW_NODE->object = &obj;
		NEW_NODE->next = head;
		Node* tmp = head;
		head = NEW_NODE;
		Node* current = tmp;
		while (current->next != tmp)
		{
			current = current->next;
		}
		current->next = head;
		return;
	}
	Node* current = head;
	for (int i = 1; i < value - 1; i++)
	{
		current = current->next;
	}
	Node* NEW_NODE = new Node;
	NEW_NODE->object = &obj;
	Node* tmp = current->next;
	current->next = NEW_NODE;
	NEW_NODE->next = tmp;
}

template<class T>
inline void TList<T>::delete_node_by_number(int value)
{
	if (head == NULL)
	{
		throw exception("Delete from empty list.");
	}
	if (head == head->next)
	{
		Node* tmp = head;
		delete tmp;
		head = NULL;
		return;
	}
	if (value == 1)
	{
		Node* current = head;
		while (current->next != head)
		{
			current = current->next;
		}
		current->next = head->next;
		Node* tmp = head;
		delete tmp;
		head = current->next;
		return;
	}
	Node* current = head;
	for (int i = 1; i < value - 1; i++)
	{
		current = current->next;
	}
	Node* tmp = current->next;
	current->next = tmp->next;
	delete tmp;
}

template<>
inline char* TList<Matrix>::find_by_number(int value)
{
	if (head == NULL)
	{
		char* str = new char[512];
		str[0] = '\0';
		strcat_s(str, 512, "Empty list.\n");
		return str;
	}
	Node* current = head;
	char* str = new char[512];
	str[0] = '\0';
	bool flag = false;
	while (current->next != head)
	{
		for (int i = 0; i < current->object->get_row_rank(); i++)
		{
			for (int k = 0; k < current->object->get_column_rank(); k++)
			{
				if (current->object->get_number(i, k) == value)
				{
					flag = true;
				}
			}
		}
		if (flag == true)
		{
			strcat_s(str, 512, current->object->to_string());
			strcat_s(str, 512, "\n");
			flag = false;
		}
		current = current->next;
	}
	for (int i = 0; i < current->object->get_row_rank(); i++)
	{
		for (int k = 0; k < current->object->get_column_rank(); k++)
		{
			if (current->object->get_number(i, k) == value)
			{
				flag = true;
			}
		}
	}
	if (flag == true)
	{
		strcat_s(str, 512, current->object->to_string());
		strcat_s(str, 512, "\n");
	}
	return str;
}

template<>
inline char* TList<int>::find_by_number(int value)
{
	if (head == NULL)
	{
		char* str = new char[512];
		str[0] = '\0';
		strcat_s(str, 512, "Empty list.\n");
		return str;
	}
	Node* current = head;
	char str[1000] = "";
	char buff[12];
	str[0] = '\0';
	int counter = 0;
	while (current->next != head)
	{
		if (*(current->object) == value)
		{
			sprintf_s(buff, sizeof(buff), "(%d)", *(current->object));
			strcat_s(str, sizeof(str), buff);
			strcat_s(str, 512, "\n");
			counter++;
		}
		current = current->next;
	}
	if (*(current->object) == value)
	{
		sprintf_s(buff, sizeof(buff), "(%d)", *(current->object));
		strcat_s(str, sizeof(str), buff);
		strcat_s(str, 512, "\n");
		counter++;
	}
	return str;
}

template<>
inline char* TList<Matrix>::find_by_row_rank(int value)
{
	if (head == NULL)
	{
		char* str = new char[512];
		str[0] = '\0';
		strcat_s(str, 512, "Empty list.\n");
		return str;
	}
	Node* current = head;
	char* str = new char[512];
	str[0] = '\0';
	while (current->next != head)
	{
		if (current->object->get_row_rank() == value)
		{
			strcat_s(str, 512, current->object->to_string());
			strcat_s(str, 512, "\n");
		}
		current = current->next;
	}
	if (current->object->get_row_rank() == value)
	{
		strcat_s(str, 512, current->object->to_string());
		strcat_s(str, 512, "\n");
	}
	return str;
}

template<>
inline char* TList<Matrix>::find_by_column_rank(int value)
{
	if (head == NULL)
	{
		char* str = new char[512];
		str[0] = '\0';
		strcat_s(str, 512, "Empty list.\n");
		return str;
	}
	Node* current = head;
	char* str = new char[512];
	str[0] = '\0';
	while (current->next != head)
	{
		if (current->object->get_column_rank() == value)
		{
			strcat_s(str, 512, current->object->to_string());
			strcat_s(str, 512, "\n");
		}
		current = current->next;
	}
	if (current->object->get_column_rank() == value)
	{
		strcat_s(str, 512, current->object->to_string());
		strcat_s(str, 512, "\n");
	}
	return str;
}

template<>
inline char* TList<Matrix>::to_string()
{
	if (head == NULL)
	{
		char* str = new char[512];
		str[0] = '\0';
		strcat_s(str, 512, "Empty list.\n");
		return str;
	}
	Node* current = head;
	char* str = new char[512];
	str[0] = '\0';
	while (current->next != head)
	{
		strcat_s(str, 512, current->object->to_string());
		strcat_s(str, 512, "\n");
		current = current->next;
	}
	strcat_s(str, 512, current->object->to_string());
	strcat_s(str, 512, "\n");
	return str;
}

template<>
inline char* TList<int>::to_string()
{
	if (head == NULL)
	{
		char* str = new char[512];
		str[0] = '\0';
		strcat_s(str, 512, "Empty list.\n");
		return str;
	}
	Node* current = head;
	char str[1000] = "";
	char buff[12];
	str[0] = '\0';
	while (current->next != head)
	{
		//cout << *(current->object) << endl;
		sprintf_s(buff, sizeof(buff), "(%d)", *(current->object));
		strcat_s(str, sizeof(str), buff);
		strcat_s(str, 512, "\n");
		current = current->next;
	}
	int a = *(current->object);
	sprintf_s(buff, sizeof(buff), "(%d)", a);
	strcat_s(str, sizeof(str), buff);
	strcat_s(str, 512, "\n");
	strcat_s(str, 512, "\0");
	return str;
}

template<>
inline char* TList<float>::to_string()
{
	if (head == NULL)
	{
		char* str = new char[512];
		str[0] = '\0';
		strcat_s(str, 512, "Empty list.\n");
		return str;
	}
	Node* current = head;
	char str[1000] = "";
	char buff[12];
	str[0] = '\0';
	while (current->next != head)
	{
		//cout << *(current->object) << endl;
		sprintf_s(buff, sizeof(buff), "(%f)", *(current->object));
		strcat_s(str, sizeof(str), buff);
		strcat_s(str, 512, "\n");
		current = current->next;
	}
	int a = *(current->object);
	sprintf_s(buff, sizeof(buff), "(%f)", a);
	strcat_s(str, sizeof(str), buff);
	strcat_s(str, 512, "\n");
	strcat_s(str, 512, "\0");
	return str;
}

template<>
inline void TList<Matrix>::list_polimorph_replace(int num, int rep_num)
{
	if (head == NULL)
	{
		return;
	}
	Node* current = head;
	while (current->next != head)
	{
		current->object->replace(num, rep_num);
		current = current->next;
	}
	current->object->replace(num, rep_num);
}
