#include "EnemyNode.h"



EnemyNode::EnemyNode()
{
	Item = NULL;
	next = NULL;
}

EnemyNode::EnemyNode(Enemy* newItem)
{
	Item = newItem;
	next = NULL;
}


void EnemyNode::setItem(Enemy* newItem)
{
	Item = newItem;
}

void EnemyNode::setNext(EnemyNode* nextNodePtr)
{
	next = nextNodePtr;
}

Enemy* EnemyNode::getItem() const
{
	return Item;
}

EnemyNode* EnemyNode::getNext() const
{
	return next;
};