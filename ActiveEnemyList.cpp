#include "ActiveEnemyList.h"
#include <iostream>

using namespace std;


ActiveEnemyList::ActiveEnemyList()
{
	count = 0;
	Head = NULL;
}

ActiveEnemyList::~ActiveEnemyList()
{
	
}

void ActiveEnemyList::PrintList()
{
	cout << "\nList has " << count << " Enemys";
	cout << "\nprinting list contents:\n\n";
	EnemyNode* p = Head;

	while (p != NULL)
	{
		cout << "[ " << p->getItem()->GetHealth() << " ]";
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

void ActiveEnemyList::InsertBeg(Enemy* &E)
{
	EnemyNode *R = new EnemyNode(E);
	R->setNext(Head);
	Head = R;
	count++;
}

void ActiveEnemyList::Enemymove()
{
	EnemyNode* p = Head;
	while (p != NULL) {
		p->getItem()->DecrementDist();
		p = p->getNext();
	}
}

int ActiveEnemyList::retCount()
{
	return count;
}


bool ActiveEnemyList::DeleteEnemy(int ID,Enemy*& E)
{
	EnemyNode* P = Head;
	while (P != NULL)
	{
		if (P->getItem()->GetID() == ID) {
			E = P->getItem();
			Head = Head->getNext();
			delete P;
			count--;
			return true;
		}
		if (P->getNext() == NULL) { break; }
		if (P->getNext()->getItem()->GetID() == ID)
		{
			E = P->getNext()->getItem();
			P->setNext(P->getNext()->getNext());
			delete P->getNext();
			count--;
			return true;
		}
		P = P->getNext();
	}
	return false;
}

bool ActiveEnemyList::isempty()
{
	return !Head;
}

	
