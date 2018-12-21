#include "Castle.h"

#include "..\GUI\GUI.h"

Castle::Castle()
{
	

}

void Castle::SetTowerHealth(double h)
{
	for(int i = 0; i < NoOfRegions; i++) {
		Towers[i].SetHealth(h);
		Towers[i].SetFreezelimit(h);
	}
}
void Castle::SetMaxEnemy(int Max) {
	for (int i = 0; i < NoOfRegions; i++) {
		Towers[i].SetEnemy(Max);
	}
}
void Castle::SetTowerPower(int Power) {
	for (int i = 0; i < NoOfRegions; i++) {
		Towers[i].SetPower(Power);
	}
}

void Castle::AddEnemy(Enemy *& E)
{
	REGION R = E->GetRegion();
	Towers[R].AddEnemy(E);
}

void Castle::gettowerhealth(double & A, double & B, double & C, double & D)
{
	A = Towers[0].GetHealth();
	B= Towers[1].GetHealth();
	C= Towers[2].GetHealth();
	D= Towers[3].GetHealth();

}

void Castle::retCount(int& a,int& b,int& c,int& d)
{
	a = Towers[0].getAELcount();
	b = Towers[1].getAELcount();
	c = Towers[2].getAELcount();
	d = Towers[3].getAELcount();
		
}

void Castle::retKilled(int & a, int & b, int & c, int & d)
{
	a = Towers[0].getKilled();
	b = Towers[1].getKilled();
	c = Towers[2].getKilled();
	d = Towers[3].getKilled();

}

Tower Castle::retTower(REGION R)
{
	return Towers[R];
}

void Castle::ACT(int timestep)
{
	for (int i = 0; i < NoOfRegions; i++) {
		if (!Towers[i].AELisempty()) {
			Towers[i].AllAct(timestep);
		}
	}
}


