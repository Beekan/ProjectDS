#pragma once
#include "EnemyNode.h"
class InactiveEnemyList
{
private:

	EnemyNode* backPtr;
	EnemyNode* frontPtr;
	int count;
public:
	InactiveEnemyList();
	bool isEmpty() const;
	bool enqueue(Enemy*& newEntry);
	bool dequeue(Enemy*& frntEntry);
	bool peekFront(Enemy*& frntEntry)  const;
	int retCount();

	~InactiveEnemyList();
};

