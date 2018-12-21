#include "Tower.h"
#include "..\heap.h"
#include<ctime>
#include<cstdlib>
#include"..\Healer.h"



Tower::Tower()
{
	SetHealth(TowerInitHealth);
	freezelimit = (20/100)*0.25*TowerInitHealth;
	killed = 0;
	freezevalue = 0;
}

void Tower::attack()
{
	heap h;
	EnemyNode* EN;
	Heapitem* HI;
	Enemy* E;
	double health;
	double distance;
	double damage;
	double k=1;
	int count=AttackNO;
	if (AttackNO > AEL.retCount()) { count = AEL.retCount(); }
	int firetype = rand() % 100 + 1;
	EN = AEL.retHead();
	if (freezevalue < freezelimit) {
		while (EN) {
			h.Enqueue(EN->getItem()->Getpriority(), EN->getItem());
			EN = EN->getNext();
		}
		for (int i = 0; i < count-1; i++) {
			HI = h.Dequeue();
			E = HI->getData();
			if (firetype <= 20) {
				if (E->Getfreezetimer() == 0)
					E->setfreezetimer(firepower);
			}
			else if (firetype > 20) {
				if (dynamic_cast<Healer*>(E))
					k = 2;
				health = E->GetHealth();
				distance = E->GetDistance();
				damage = (1 / distance)*firepower*(1 / k);
				health = health - damage;
				E->SetHealth(health);
			}

		}
	}
	freezevalue = 0;
}

void Tower::get_attacked()
{
	Tower* T = this;
	EnemyNode* p = AEL.retHead();
	while (p) {
		p->getItem()->Act(T);
		p = p->getNext();
	}
}

void Tower::SetState(State S)
{
	currentstate = S;
}

void Tower::SetFiretype(FireType F)
{
	fire = F;

}

void Tower::SetFreezelimit(double Fz)
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

void Tower::setfreezevalue(double f)
{
	freezevalue = f;
}

int Tower::getKilled()
{
	return KEL.retCount();
}

double Tower::getHealth()
{
	return Health;
}

int Tower::getAELcount()
{
	return AEL.retCount();
}

double Tower::getfreezelimit()
{
	return freezelimit;
}

double Tower::getfreezevalue()
{
	return freezevalue;
}

ActiveEnemyList Tower::getAEL()
{
	return AEL;
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
	Enemy* E;
	Tower* T = this;
	AEL.Enemymove();
	get_attacked();
	attack();

	if (!AEL.isempty()) {
		if (AEL.DeleteEnemy(E))
		{
				KEL.InsertBeg(E);
		}
	}
	

}

void Tower::attack(Enemy * ActEnemies)
{
}
