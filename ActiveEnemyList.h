#ifndef _LLIST
#define _LLIST
#include "Enemies\Enemy.h"
#include "EnemyNode.h"


class ActiveEnemyList
{
private:
	EnemyNode* Head;
	int count;	//Number of Enemys in the list
public:
	ActiveEnemyList();
	~ActiveEnemyList();
	void PrintList();
	void InsertBeg(Enemy*& E);
	void Enemymove();
	int retCount();
	bool DeleteEnemy(Enemy*& E);
	bool isempty();
	void setHead(EnemyNode* &E);
	void NullHead();
	EnemyNode* retHead();
	void merge(ActiveEnemyList & L);
	bool deletetower(Enemy*&E);
	
	void InsertEnd(Enemy* E);
    bool Find(int Key);
};
#endif
