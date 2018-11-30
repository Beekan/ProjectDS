#include "InactiveEnemyList.h"




InactiveEnemyList::InactiveEnemyList()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this InactiveEnemyList is empty.

Input: None.
Output: True if the InactiveEnemyList is empty; otherwise false.
*/

bool InactiveEnemyList::isEmpty() const
{
	if (frontPtr == nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enInactiveEnemyList
Adds newEntry at the back of this InactiveEnemyList.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/


bool InactiveEnemyList::enqueue(Enemy*& newEntry)
{
	EnemyNode* newNodePtr = new EnemyNode(newEntry);
	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr; // The InactiveEnemyList is empty
	else
		backPtr->setNext(newNodePtr); // The InactiveEnemyList was not empty
	backPtr = newNodePtr; // New node is at back
	return true;
} // end enqueue


  /////////////////////////////////////////////////////////////////////////////////////////////////////////

  /*Function: deInactiveEnemyList
  Removes the front of this InactiveEnemyList. That is, removes the item that was added
  earliest.

  Input: None.
  Output: True if the operation is successful; otherwise false.
  */


bool InactiveEnemyList::dequeue(Enemy*& frntEntry)
{
	if (isEmpty())
		return false;

	EnemyNode* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// InactiveEnemyList is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: one node in InactiveEnemyList
		backPtr = nullptr;

	// Free memory reserved by the deInactiveEnemyListd node
	delete nodeToDeletePtr;


	return true;

}



/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peekFront
Returns the front of this InactiveEnemyList. The operation does not modify the InactiveEnemyList.

Input: None.
Output: The front of the InactiveEnemyList.
*/

bool InactiveEnemyList::peekFront(Enemy*& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

///////////////////////////////////////////////////////////////////////////////////


InactiveEnemyList::~InactiveEnemyList()
{
}
