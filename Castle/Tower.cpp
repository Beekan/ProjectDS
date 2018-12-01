#include "Tower.h"


Tower::Tower()
{
	SetHealth(TowerInitHealth);
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

double Tower::GetHealth() const
{
	return Health;
}

void Tower::AllAct()
{
	AEL.Enemymove();
}

void Tower::attack(Enemy * ActEnemies)
{
}
