#include "Tower.h"
#include<ctime>
#include<cstdlib>



Tower::Tower()
{
	SetHealth(TowerInitHealth);
	killed = 0;
}

void Tower::SetState(State S)
{
	currentstate = S;
}

void Tower::SetFiretype(FireType F)
{
	fire = F;

}

void Tower::SetFreezelimit(int Fz)
{
	freezelimit = Fz;
}

void Tower::AddEnemy(Enemy *&E)
{
	AEL.InsertBeg(E);
}


void Tower::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
}

void Tower::SetEnemy(int Max)
{
	AttackNO = Max;
}

void Tower::SetPower(int Power)
{
	firepower = Power;
}

int Tower::getKilled()
{
	return killed;
}

int Tower::getAELcount()
{
	return AEL.retCount();
}

bool Tower::AELisempty()
{
	return AEL.isempty();
}

double Tower::GetHealth() const
{
	return Health;
}

void Tower::AllAct(int EnemyCount)
{

	int count = AEL.retCount();
	int id = rand() % EnemyCount + 1;
	AEL.Enemymove();
	if(!AEL.isempty()){
	AEL.DeleteEnemy(id);
	killed++;
	}
}

void Tower::attack(Enemy * ActEnemies)
{
}
