#include "Freezer.h"
#include "Castle\Tower.h"
#include "ActiveEnemyList.h"





void Freezer::Act(Tower* &T)
{
	double k = 1;
	double freezelimit;
	double freezevalue;
	int p;
	if (reloadtimer == 0 && freezetimer == 0) {
		freezelimit = T->getfreezelimit();
		freezevalue = T->getfreezevalue();
		if (freezelimit<power)
			k = 0.5;
		freezevalue = freezevalue + k*power;
		T->setfreezevalue(freezevalue);
		reloadtimer = reloadperiod;
		updatepriority();
		return;
	}
	if (reloadtimer>0)
		reloadtimer--;
	if (freezetimer > 0)
		freezetimer--;
	updatepriority();
}


Freezer::Freezer(Tower * t) :Enemy(t)
{
	T = t;
	Clr = WHITE;
	freezetimer = 0;
	reloadtimer = 0;
	steptimer = 0;
	Priority = 2;
	firstshotdelay = 0;
	killdelay = 0;
	lifetime = 0;
	KTS = 0;
}

Freezer::~Freezer()
{
}
