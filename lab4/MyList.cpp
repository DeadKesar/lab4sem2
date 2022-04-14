#include "MyList.h"



Node::Node(PostAdres& adres) : adres(adres)
{ }
MyList::MyList() : head(nullptr), tail(nullptr), size(0)
{   }

MyList::MyList(PostAdres& adres)
{
	Node *node = new Node(adres);
	this->head = node;
	this->tail = node;
	node->isTail = true;
	size = 1;
}
MyList::MyList(Node& node)
{
	this->head = &node;
	this->tail = &node;
	node.isTail = true;
	size = 1;
}
MyList::~MyList()
{
	Node* curent = this->head;
	while (!curent->next->isTail)
	{
		Node* temp = curent;
		curent = curent->next;
		delete temp;
	}
	delete curent;
}
//идея в том, что метод добавления добавляет элементы в список оставляя его сортированным.
void MyList::Add(Node& node)
{
	Node* curent = this->head;
	if (size > 1)
	{
		while (!curent->next->isTail)
		{
			if (curent->next->adres.compare(node.adres) >= 0)
			{
				node.next = curent->next;
				curent->next = &node;
				size++;
				return;
			}
			curent = curent->next;
		}
		if (curent->next->adres.compare(node.adres) >= 0)
		{
			node.next = curent->next;
			curent->next = &node;
			size++;
			return;
		}
		curent = curent->next;
	}
	if (curent->adres.compare(node.adres) >= 0)
	{
		node.next = curent;
		head = &node;	
		size++;
		return;
	}
	curent->isTail = false;
	curent->next = &node;
	curent->next->isTail = true;
	size++;
}
Node& MyList::Front()
{
	return *head;
}
Node& MyList::Back()
{
	return *tail;
}
int MyList::Size()
{
	return size;
}
bool MyList::Empty()
{
	return size == 0;
}
int MyList::Delete(Node& node)
{
	Node* curent = this->head;
	if (head->adres.equal(node.adres))
	{
		if (size > 1)
		{
			head = head->next;
			size--;
			delete curent;
			return 1;
		}
		delete curent;
		size = 0;
		curent = nullptr;
		return 1;
	}
	while (!curent->next->isTail)
	{
		if (curent->next->adres.equal(node.adres))
		{
			Node* forDel = curent->next;
			curent->next = curent->next->next;
			delete forDel;
			size--;
			return 1;
		}
	}
	if (curent->next->adres.equal(node.adres))
	{
		curent->isTail = true;
		delete curent->next;
		curent->next = nullptr;
		return 1;
	}
	return 0;
}



bool MyList::equal(MyList &list)
{
	if (this->size != list.size)
	{
		return false;
	}
	Node *curentThis = this->head;
	Node *curentOther = list.head;
	while (!curentThis->isTail)
	{
		if (!curentThis->adres.equal(curentOther->adres))
			return false;
		curentThis = curentThis->next;
		curentOther = curentOther->next;
	}
	if (curentThis->adres.equal(curentOther->adres))
		return true;
	return false;
}
Node& MyList::operator [](int index)
{
	if (index >= size)
		throw "Out of range";
	Node *temp = this->head;
	for (int i = 1; i < index; i++)
		temp = temp->next;
	return *temp;
}

 