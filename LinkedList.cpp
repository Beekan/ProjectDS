#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
	count = 0;
	Head = NULL;
}

LinkedList::~LinkedList()
{
	DeleteAll();
}

void LinkedList::PrintList()
{
	cout<<"\nList has "<<count<<" Enemys";
	cout<<"\nprinting list contents:\n\n";
	EnemyNode<Enemy> *p = Head;
	
	while(p != NULL)
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
void LinkedList::InsertBeg(Enemy E)
{
	EnemyNode<Enemy> *R = new EnemyNode<Enemy>(E);
	R->setNext(Head);
	Head = R;
	count++;
}
////////////////////////////////////////////////////////////////////////

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
bool LinkedList::DeleteEnemy(int ID)
{
	EnemyNode<Enemy> *P = Head;
	while (P != NULL)	
	{
		if(P->getNext()->getItem().GetID() ==  ID)
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