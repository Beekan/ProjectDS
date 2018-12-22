#include "Fighter.h"
#include "Castle\Tower.h"
#include "ActiveEnemyList.h"





Fighter::Fighter(Tower * t) :Enemy(t)
{
	T = t;
	Clr = DARKBLUE;
	freezetimer = 0;
	reloadtimer = 0;
	steptimer = 0;
	Priority = 1;
	firstshotdelay = 0;
	killdelay = 0;
	lifetime = 0;
	KTS = 0;
}

void Fighter::Act(Tower* &T)
{
	double k = 1;
	double health;
	if (reloadtimer == 0 && freezetimer==0) {
		if (Health / originalHealth <= 0.5)
			k = 0.5;
		health = T->GetHealth();
		health = health - (k / Distance)*power;
		T->SetHealth(health);
		reloadtimer = reloadperiod;
		return;
	}
	if(reloadtimer>0)
		reloadtimer--;
	if (freezetimer > 0)
		freezetimer--;
	updatepriority();
	
}


Fighter::~Fighter()
{
}
