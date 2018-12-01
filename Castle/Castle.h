#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"

#include "Tower.h"
#include "../Enemies/Enemy.h"
#include "../heap.h"




class Castle
{
	Tower Towers[NoOfRegions];

	//
	// TODO: Add More Data Members As Needed
	//
	
public:

	Castle();
	void SetTowerHealth(double h);
	void SetMaxEnemy(int Max);
	void SetTowerPower(int Power);
	void AddEnemy(Enemy*& E);
	void gettowerhealth(int& A, int& B, int& C, int& D);
	void retCount(int& a, int& b, int& c, int& d);
	void retKilled(int& a, int& b, int& c, int& d);
	Tower retTower(REGION R);
	void ACT(int);

	//
	// TODO: Add More Member Functions As Needed
	//
};
