#pragma once
#ifndef _LLIST
#define _LLIST
#include "Enemies\Enemy.h"
#include "EnemyNode.h"

class LinkedList
{
private:
	EnemyNode<Enemy> *Head;
	int count;	//Number of Enemys in the list
public:
	LinkedList();
	~LinkedList();
	void PrintList();	
	void InsertBeg(Enemy E);	
	void DeleteAll();	
	void InsertEnd(Enemy E);	

	bool Find(int Key);

	bool DeleteEnemy(int ID);		
};

#endif	
