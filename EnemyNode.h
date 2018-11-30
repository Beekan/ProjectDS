#pragma once
#ifndef _LINKEDLIST
#define _LINKEDLIST
#include "Enemies\Enemy.h"
class EnemyNode
{
private:
	Enemy* Item;
	EnemyNode* next;
public:
	EnemyNode();
	EnemyNode(Enemy* newItem);
	void setItem(Enemy* newItem);
	void setNext(EnemyNode* nextNodePtr);
	Enemy* getItem() const;
	EnemyNode* getNext() const;
};
#endif