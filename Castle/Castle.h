#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"

#include "Tower.h"
#include "A:\zewailcity\year 3\fall\CIE205\project\CIE205-Project-F2018-std\DSProject_Code_S2018\Enemies\Enemy.h"
#include "A:\zewailcity\year 3\fall\CIE205\project\CIE205-Project-F2018-std\DSProject_Code_S2018\Heap.h"




class Castle
{
	Tower Towers[NoOfRegions];

	//
	// TODO: Add More Data Members As Needed
	//
	
public:

	Castle();
	void SetTowerHealth(REGION TowerRegion, double h);

	//
	// TODO: Add More Member Functions As Needed
	//
};
