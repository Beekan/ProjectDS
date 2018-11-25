#pragma once
#include "..\Defs.h"
#include "A:\zewailcity\year 3\fall\CIE205\project\CIE205-Project-F2018-std\DSProject_Code_S2018\Enemies\Enemy.h"
class Tower
{
	double Health;
	State currentstate;
	int AttackNO; //Number of enemies a tower can attack per tick
	firetype fire;
	int firepower;
	int freezelimit;


	//
	// TODO: Add More Data Members As Needed
	//

public:

	Tower();
	void SetHealth(double h);
	double GetHealth() const;
	void attack(Enemy* ActEnemies); //Added by me
	//
	// TODO: Add More Member Functions As Needed
	//

};

