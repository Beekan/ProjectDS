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