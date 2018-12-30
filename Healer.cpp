#include "Healer.h"
#include "Castle\Tower.h"
#include "ActiveEnemyList.h"




Healer::Healer(Tower * t) :Enemy(t)
{
	T = t;
	Clr = ORANGERED;
	freezetimer = 0;
	reloadtimer = 0;
	steptimer = 0;
	Priority = 3;
	firstshotdelay = 0;
	killdelay = 0;
	lifetime = 0;
	KTS = 0;
}

void Healer::Act(Tower* &T)
{
	ActiveEnemyList AEL;
	EnemyNode* Head;
	double health;
	int distance1;
	AEL = T->getAEL();
	Head = AEL.retHead();
	if (reloadtimer == 0 && freezetimer == 0&& Health>0) {
		while (Head != NULL) {
			if (Head->getItem() == this) { Head = Head->getNext(); continue; }
			distance1 = Head->getItem()->GetDistance();
			if (abs(distance1 - Distance) <= 2 &&Head->getItem()->GetHealth()>0) {
				health = Head->getItem()->GetHealth();
				health = health + 0.5*power;
				Head->getItem()->SetHealth(health);
			}
			Head = Head->getNext();
		}
		reloadtimer = reloadperiod;
		return;
	}
	if (reloadtimer>0)
		reloadtimer--;
	if (freezetimer > 0)
		freezetimer--;
	updatepriority();
}




Healer::~Healer()
{
}
