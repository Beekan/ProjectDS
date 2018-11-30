#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"

#include "Tower.h"
#include "Enemies\Enemy.h"
#include "Heap.h"




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

	//
	// TODO: Add More Member Functions As Needed
	//
};
