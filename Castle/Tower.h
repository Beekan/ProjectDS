#pragma once
#include "..\Defs.h"
#include"../ActiveEnemyList.h"


class Tower
{
	double Health;
	State currentstate;
	int AttackNO; //Number of enemies a tower can attack per tick
	FireType fire;
	int firepower;
	double freezelimit;
	double freezevalue;
	double totaldamage;
	int killed;
	ActiveEnemyList AEL;
	ActiveEnemyList KEL;


	//
	// TODO: Add More Data Members As Needed
	//

public:

	Tower();
	void settotaldamage(double);
	void attack(int);
	void get_attacked();
	void SetState(State);
	void SetFiretype(FireType);
	void SetFreezelimit(double);
    void AddEnemy(Enemy*&);
	void SetHealth(double h);
	void SetEnemy(int Max);
	void SetPower(int Power);
	void setfreezevalue(double f);
	int getKilled();
	double gettotaldamage();
	double getHealth();
	int getAELcount();
	double getfreezelimit();
	double getfreezevalue();
	ActiveEnemyList getAEL();
	bool AELisempty();
	double GetHealth() const;
	void AllAct(int);
	void attack(Enemy* ActEnemies); //Added by me
	//
	// TODO: Add More Member Functions As Needed
	//

};

