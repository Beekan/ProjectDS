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
	//DeleteAll();
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


/*void ActiveEnemyList::DeleteAll()
{
	EnemyNode* P = Head;
	while (Head != NULL)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
	count = 0;
}*/

bool ActiveEnemyList::DeleteEnemy(int ID)
{
	EnemyNode* P = Head;
	while (P != NULL)
	{
		if (P->getItem()->GetID() == ID) {
			Head = Head->getNext();
			delete P;
			count--;
			return true;
		}
		if (P->getNext() == NULL) { break; }
		if (P->getNext()->getItem()->GetID() == ID)
		{
			P->setNext(P->getNext()->getNext());
			delete P->getNext();
			count--;
			return true;
		}
		P = P->getNext();
	}
	return false;
	/*struct Node* temp = *head_ref, *prev;

	// If head node itself holds the key to be deleted 
	if (P != NULL && P->getItem()->GetID() == ID)
	{
		Head = P->getNext();   // Changed head 
		free(P);               // free old head 
		return;
	}

	// Search for the key to be deleted, keep track of the 
	// previous node as we need to change 'prev->next' 
	while (temp != NULL && P->getItem()->GetID() != ID)
	{
		prev = temp;
		temp = temp->next;
	}

	// If key was not present in linked list 
	if (temp == NULL) return;

	// Unlink the node from linked list 
	prev->next = temp->next;

	free(temp);  // Free memory 
}*/
}

bool ActiveEnemyList::isempty()
{
	return !Head;
}

	
