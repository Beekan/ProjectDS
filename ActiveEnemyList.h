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
	//void DeleteAll();
	bool DeleteEnemy(int ID);
	void InsertEnd(Enemy* E);
    bool Find(int Key);
};
#endif
