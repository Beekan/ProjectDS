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
	int killed;

	//
	// TODO: Add More Data Members As Needed
	//
	
public:

	Castle();
	void SetTowerHealth(double h);
	void SetMaxEnemy(int Max);
	void SetTowerPower(int Power);
	void AddEnemy(Enemy*& E);
	void gettowerhealth(double& A, double& B, double& C, double& D);
	void retCount(int& a, int& b, int& c, int& d);
	void retKilled(int& a, int& b, int& c, int& d);
	int getkilledenemies();
	int getkilledtowers();
	Tower retTower(REGION R);
	bool dequeuekilled(Enemy*&E);
	void rettowerdamage(double&a, double&b, double&c, double&d);
	void ACT(int);

	//
	// TODO: Add More Member Functions As Needed
	//
};
