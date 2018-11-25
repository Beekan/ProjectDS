#pragma once
#ifndef _LINKEDLIST
#define _LINKEDLIST
#include "Enemies\Enemy.h"
template <class T>
class EnemyNode
{
private:
	T Item;
	EnemyNode<T> * next;
public: 
	EnemyNode();
	EnemyNode(T newItem);
	void setItem(T newItem);
	void setNext(EnemyNode<T>* nextNodePtr);
	T getItem() const ;
	EnemyNode<T>* getNext() const;
};
template <class T>
EnemyNode<T>::EnemyNode()
{
	Item = 0;
	next= NULL;
} 
template <class T>
EnemyNode<T>::EnemyNode(T newItem)
{
	Item = newItem;
	next= NULL;
} 

template <class T>
void EnemyNode<T>::setItem( T newItem)
{
	item = newItem;
}
template <class T>
void EnemyNode<T>::setNext(EnemyNode<T>* nextNodePtr)
{
next = nextNodePtr;
} 
template <class T>
T EnemyNode<T>::getItem() const
{
return Item;
} 
template <class T>
EnemyNode<T>* EnemyNode<T>::getNext() const
{
return next;
};
#endif