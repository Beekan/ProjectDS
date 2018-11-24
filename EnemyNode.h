#pragma once
#ifndef _LINKEDLIST
#define _LINKEDLIST
#include "Enemies\Enemy.h"
template <class T>
class EnemyNode
{
private:
	T Item;
	EnemyNode * next;
public: 
	EnemyNode();
	EnemyNode(T newItem);
	void setItem(T newItem);
	void setNext(EnemyNode* nextNodePtr);
	T getItem() const ;
	EnemyNode* getNext() const;

template <class T>
EnemyNode(T newItem)
{
	Item = newItem;
	next= NULL;
} 
EnemyNode()
{
	next= NULL;
} 
template <class T>
void setItem( T newItem)
{
	item = newItem;
}

void setNext(EnemyNode* nextNodePtr)
{
next = nextNodePtr;
} 
template <class T>
T getItem() 
{
return item;
} 
template <class T>
T* getNext() 
{
return next;
}
};
#endif