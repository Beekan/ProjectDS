#pragma once
#ifndef _LLIST
#define _LLIST
#include "Enemies\Enemy.h"
#include "EnemyNode.h"
template <class T>
class LinkedList
{
private:
	EnemyNode<Enemy> *Head;
	int count;	//Number of Enemys in the list
public:
	LinkedList();
	~LinkedList();
	void PrintList();	
	void InsertBeg(Enemy E);	
	void DeleteAll();	
	void InsertEnd(Enemy E);	

	bool Find(int Key);

	bool DeleteEnemy(int ID);		
};
template <class T>
LinkedList::LinkedList()
{
	count = 0;
	Head = NULL;
}
template <class T>
LinkedList::~LinkedList()
{
	DeleteAll();
}
template <class T>
void LinkedList::PrintList()
{
	cout << "\nList has " << count << " Enemys";
	cout << "\nprinting list contents:\n\n";
	EnemyNode<Enemy> *p = Head;

	while (p != NULL)
	{
		cout << "[ " << p->getItem().GetHealth() << " ]";
		cout << "--->";
		p = p->getNext();
	}
	cout << "*\n";
}
////////////////////////////////////////////////////////////////////////
/*
* Function: InsertBeg.
* Creates a new Enemy and adds it to the beginning of a linked list.
*
* Parameters:
*	- data : The value to be stored in the new Enemy.
*/
template <class T>
void LinkedList::InsertBeg(Enemy E)
{
	EnemyNode<Enemy> *R = new EnemyNode<Enemy>(E);
	R->setNext(Head);
	Head = R;
	count++;
}
////////////////////////////////////////////////////////////////////////
template <class T>
void LinkedList::DeleteAll()
{
	EnemyNode<Enemy> *P = Head;
	while (Head != NULL)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
	count = 0;
}
template <class T>
bool LinkedList::DeleteEnemy(int ID)
{
	EnemyNode<Enemy> *P = Head;
	while (P != NULL)
	{
		if (P->getNext()->getItem().GetID() == ID)
		{
			P->setNext(P->getNext()->getNext());
			delete P->getNext();
			count--;
			return true;
		}
		P = P->getNext();
	}
	return false;
}

#endif	
