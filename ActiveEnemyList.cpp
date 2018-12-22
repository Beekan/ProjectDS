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
	int s;
	while (p != NULL) {
		if (p->getItem()->Getfreezetimer() == 0) {
			if (p->getItem()->GetHealth() / p->getItem()->GetOriginalHealth() < 0.5) {
				s = p->getItem()->getsteptimer();
				p->getItem()->setsteptimer(s++);
			}
			if (p->getItem()->getsteptimer() % 2 == 0)
				p->getItem()->DecrementDist();
		}
		p = p->getNext();
	}
}

/*void ActiveEnemyList::Enemyattack()
{
	EnemyNode* p = Head;
	while (p) {
		p->getItem()->Act();
		p = p->getNext();
    }
}*/

int ActiveEnemyList::retCount()
{
	return count;
}


bool ActiveEnemyList::DeleteEnemy(Enemy*& E)
{
	EnemyNode* P = Head;
	while (P != NULL)
	{
		if (P->getItem()->GetHealth() == 0) {
			E = P->getItem();
			Head = Head->getNext();
			delete P;
			count--;
			return true;
		}
		if (P->getNext() == NULL) { break; }
		if (P->getNext()->getItem()->GetHealth() == 0)
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

void ActiveEnemyList::setHead(EnemyNode *& E)
{
	Head = E;
}

void ActiveEnemyList::NullHead()
{
	Head = NULL;
	count = 0;
}

EnemyNode* ActiveEnemyList::retHead()
{
	return Head;
}

void ActiveEnemyList::merge(ActiveEnemyList &L)
{
	EnemyNode* p = Head;
	EnemyNode* q = L.retHead();
	REGION R;
	while (q) {
		R = q->getItem()->GetRegion();
		q->getItem()->SetRegion(REGION(R + 1));
		q = q->getNext();
	}
	if (p) {
		while (p->getNext())
			p = p->getNext();
		p->setNext(q);
	}
	else
		Head = L.retHead();
	
	
	count =count+L.retCount();
	L.NullHead();
	
	
}

bool ActiveEnemyList::deletetower(Enemy *& E)
{
	EnemyNode* P = Head;
	REGION R;
	if (Head) {
		E = P->getItem();
		R = E->GetRegion();
		E->SetRegion(REGION(R + 1));
		Head = Head->getNext();
		delete P;
		count--;
		return true;
	}
		
		
	
	return false;
}

	
