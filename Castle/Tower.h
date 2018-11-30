#pragma once
#include "..\Defs.h"
#include"ActiveEnemyList.h"
#include "Enemies\Enemy.h"
class Tower
{
	double Health;
	State currentstate;
	int AttackNO; //Number of enemies a tower can attack per tick
	FireType fire;
	int firepower;
	int freezelimit;
	ActiveEnemyList AEL;


	//
	// TODO: Add More Data Members As Needed
	//

public:

	Tower();
	void SetHealth(double h);
	void SetEnemy(int Max);
	void SetPower(int Power);
	double GetHealth() const;
	void attack(Enemy* ActEnemies); //Added by me
	//
	// TODO: Add More Member Functions As Needed
	//

};

