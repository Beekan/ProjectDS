#include "Castle.h"

#include "..\GUI\GUI.h"

Castle::Castle()
{
	

}

void Castle::SetTowerHealth(double h)
{
	for(int i = 0; i < NoOfRegions; i++) {
		Towers[i].SetHealth(h);
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

Tower Castle::retTower(REGION R)
{
	return Towers[R];
}

void Castle::ACT()
{
	for (int i = 0; i < NoOfRegions; i++) {
		if (!Towers[i].AELisempty()) {
			Towers[i].AllAct();
		}
	}
}


