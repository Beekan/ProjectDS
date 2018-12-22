#include "Castle.h"

#include "..\GUI\GUI.h"

Castle::Castle()
{
	killed = 0;

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
	a = Towers[0].getKELcount();
	b = Towers[1].getKELcount();
	c = Towers[2].getKELcount();
	d = Towers[3].getKELcount();

}

int Castle::getkilledenemies()
{
	int k = 0;
	for (int i = 0; i < NoOfRegions; i++) {
		k=k+Towers[i].getKELcount();
	}
	return k;
}

int Castle::getkilledtowers()
{
	return killed;
}

Tower Castle::retTower(REGION R)
{
	return Towers[R];
}

void Castle::dequeuekilled(Enemy *& E)
{
	int min = INT_MAX;
	Enemy* q;
	Enemy* k;
	for (int i = 0; i < 4; i++) {
			Towers[i].peekfront(q);
			if (q->getKTS() < min) {
				min = q->getKTS();
				E = q;
			}

		
	}
}

void Castle::rettowerdamage(double & a, double & b, double & c, double & d)
{
	a = Towers[0].gettotaldamage();
	b = Towers[1].gettotaldamage();
	c = Towers[2].gettotaldamage();
	d = Towers[3].gettotaldamage();
}

void Castle::ACT(int timestep)
{
	Enemy* E;
	int EN;
	for (int i = 0; i < NoOfRegions; i++) {
		if (!Towers[i].AELisempty()) {
			if (Towers[i].getHealth() == 0) {
				killed++;
				EN = Towers[i].getAEL().retCount();
				while (EN) {
					Towers[i].deletetower(E);
					Towers[i + 1].insertbeg(E);
					EN--;
				}	
			}
			Towers[i].AllAct(timestep);
		}
	}
}


