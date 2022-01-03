
#include "List.h"

List::List(Matrix& obj)
{
	Node* NEW_NODE = new Node;
	head = NEW_NODE;
	NEW_NODE->object = &obj;
	NEW_NODE->next = head;
}
List::~List()
{
	if (head == NULL)
	{
		return;
	}
	Node* current = head->next;
	while(current != head) 
	{
		Node* tmp = current->next;
		delete current;
		current = tmp;
	}
	delete head;
}
void List::add_node(Matrix& obj)
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
void List::delete_node()
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
void List::add_node_by_number(Matrix& obj, int value)
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
	for(int i = 1; i < value-1; i ++)
	{
		current = current->next;
	}
	Node* NEW_NODE = new Node;
	NEW_NODE->object = &obj;
	Node* tmp = current->next;
	current->next = NEW_NODE;
	NEW_NODE->next = tmp;

}
void List::delete_node_by_number(int value)
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
char* List::find_by_number(int value)
{
	if (head == NULL)
	{
		char* str = new char[512];
		strcat_s(str, 512, "Empty list.");
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
				if (current->object->get_number(i,k) == value)
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
char* List::find_by_row_rank(int value)
{
	if (head == NULL)
	{
		char* str = new char[512];
		strcat_s(str, 512, "Empty list.");
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
char* List::find_by_column_rank(int value)
{
	if (head == NULL)
	{
		char* str = new char[512];
		strcat_s(str, 512, "Empty list.");
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
char* List::to_string()
{
	if (head == NULL)
	{
		char* str = new char[512];
		strcat_s(str, 512, "Empty list.");
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
void List::list_polimorph_replace(int num, int rep_num)
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
