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
	totaldamage = 0;
}

void Tower::settotaldamage(double d)
{
	totaldamage = d;
}

void Tower::attack(int timestep)
{
	heap* h=new heap(AEL.retCount());
	EnemyNode* EN;
	Enemy* E;
	double health;
	double distance;
	double damage;
	double k=1;
	int count=AttackNO;
	if (AttackNO > AEL.retCount()) { count = AEL.retCount(); }
	int firetype;
	EN = AEL.retHead();
	if (freezevalue < freezelimit&& Health>0) {
		while (EN) {
			h->Enqueue(EN->getItem()->Getpriority(), EN->getItem());
			EN = EN->getNext();
		}
		for (int i = 0; i < count; i++) {
			firetype = rand() % 100 + 1;
			Heapitem* HI = new Heapitem();
			HI=h->Dequeue();
			E = HI->getData();
			if (firetype <= 20) {
				if (E->Getfreezetimer() == 0)
					E->setfreezetimer(firepower/2);
			}
			else if (firetype > 20) {
				if (dynamic_cast<Healer*>(E))
					k = 2;
				health = E->GetHealth();
				distance = E->GetDistance();
				damage = (1 / distance)*firepower*(1 / k);
				health = health - damage;
				E->SetHealth(health);
				totaldamage = totaldamage + damage;
				if (E->getFSD() == 0)
					E->setFSD(timestep);
				
			}
			HI->~Heapitem();
			delete HI;

		}
		return;
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

void Tower::deletetower(Enemy *& E)
{
	AEL.deletetower(E);
}

void Tower::insertbeg(Enemy *& E)
{
	AEL.InsertBeg(E);
}


double Tower::gettotaldamage()
{
	return totaldamage;
}

double Tower::getHealth()
{
	return Health;
}

int Tower::getAELcount()
{
	return AEL.retCount();
}

int Tower::getKELcount()
{
	return KEL.retCount();
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

bool Tower::dequeueKEL(Enemy *& E)
{
	if(KEL.dequeue(E))
		return true;
	return false;
}

bool Tower::peekfront(Enemy *& E)
{
	if (KEL.peekFront(E))
		return true;
	return false;
}

bool Tower::AELisempty()
{
	return AEL.isempty();
}

double Tower::GetHealth() const
{
	return Health;
}

void Tower::AllAct(int timestep)
{
	
	EnemyNode* EN=AEL.retHead();
	while (EN ) {
		Enemy** E=new Enemy*;
		if (AEL.DeleteEnemy(*E))
		{
			(*E)->setKD(timestep);
			KEL.enqueue(*E);
			EN = AEL.retHead();

		}
		delete E;
		if (AEL.retCount() == 0) { break; }
		EN=EN->getNext();
		
	}
	AEL.Enemymove();
	get_attacked();
	attack(timestep);

}

void Tower::deletekilled(int timestep)
{
	Enemy* E;
	int EN = AEL.retCount();
	while (EN) {
		if (AEL.DeleteEnemy(E))
		{
			E->setKD(timestep);
			KEL.enqueue(E);

		}
		EN--;
	}
}

void Tower::attack(Enemy * ActEnemies)
{
}
