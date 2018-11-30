#include "Battle.h"

#include <iostream>
#include <fstream>
#include"Fighter.h"
#include"Healer.h"
#include"Freezer.h"

Battle::Battle()
{
	EnemyCount = 0;
}

void Battle::readfile()
{
	pGUI->PrintMessage("Please, Enter the File name.");
	string FileName = pGUI->GetString();
	LoadFile.open(FileName);
	double TowerHealth; 
	int MaxEnemy, TowerPower, EnemyID,EnemyType,EnemyHealth,EnemyPower,Reloadperiod,Arrivaltime;
	REGION EnemyRegion;
	char Region;
	Enemy* Enemy;
	string line;
	LoadFile >> TowerHealth;
	LoadFile >> MaxEnemy;
	LoadFile >> TowerPower;
	BCastle.SetTowerHealth(TowerHealth);
	BCastle.SetMaxEnemy(MaxEnemy);
	BCastle.SetTowerPower(TowerPower);
	while(1) 
	{
		LoadFile >> EnemyID;
		LoadFile >> EnemyType;
		LoadFile >> Arrivaltime;
		LoadFile >> EnemyHealth;
		LoadFile >> EnemyPower;
		LoadFile >> Reloadperiod;
		LoadFile >> Region;
		EnemyRegion = static_cast<REGION>(Region);
		if (EnemyID = -1) { break; }
		switch (EnemyType) {
		case 1:
			Fighter * Fighter;
			Enemy = Fighter;
			break;
		case 2:
			Healer * Healer;
			Enemy = Healer;
		    break;
		case 3:
			Freezer * Freezer;
			Enemy = Freezer;
            break;
		default:
			break;
		}
		Enemy->setarrivaltime(Arrivaltime);
		Enemy->SetHealth(EnemyHealth);
		Enemy->SetID(EnemyID);
		Enemy->SetPower(EnemyPower);
		Enemy->SetRegion(EnemyRegion);
		Enemy->SetReloadPeriod(Reloadperiod);
		IEL.enqueue(Enemy);
	}
}

void Battle::AddEnemy(Enemy* Ptr)
{
	if (EnemyCount < MaxEnemyCount) 
		BEnemiesForDraw[EnemyCount++] = Ptr;

	// Note that this function doesn't allocate any enemy objects
	// It only makes the first free pointer in the array
	// points to the same enemy pointed to by "Ptr"
}


Castle * Battle::GetCastle()
{
	return &BCastle;
}






void Battle::RunSimulation()
{
	Just_A_Demo();
}


//This is just a demo function for project introductory phase
//It should be removed in phases 1&2
void Battle::Just_A_Demo()
{
	
	std::cout<<"\nWelcome to Castle Battle:\n";
	std::cout<<"\nIn phase2, you will be asked to select game mode\n";
	std::cout<<"\nFor now just press ENTER key to continue...";
	
	//char tmp[10];
	//std::cin.getline(tmp,10);
	//
	// THIS IS JUST A DEMO
	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
	//
	
	GUI * pGUI = new GUI;

	pGUI->PrintMessage("This is Just a Demo. It should be changed ib phase1 & phase2. Click to move to next step");

	
	 
	// Declare some enemies and fill their data
	// In the game, enemies should be loaded from an input file
	// and should be dynamically allocated
	
	/*Enemy e1(DARKBLUE, A_REG, 6);
	Enemy e2(DARKBLUE, D_REG, 60);
	Enemy e3(DARKOLIVEGREEN, B_REG, 60); 
	Enemy e4(DARKOLIVEGREEN, A_REG, 4);
	Enemy e5(ORANGERED, C_REG, 19); 
	Enemy e6(ORANGERED, C_REG, 30); 
	Enemy e7(ORANGERED, A_REG, 2);
	Enemy e8(DARKOLIVEGREEN, C_REG, 7); 
	Enemy e9(ORANGERED, A_REG, 30); 
	Enemy e10(DARKBLUE, C_REG, 4);
	Enemy e11(GREEN, A_REG, 20);*/
	

	// Adding the enemies to the battle
	/*AddEnemy(&e1);
	AddEnemy(&e2);
	AddEnemy(&e3);
	AddEnemy(&e4);
	AddEnemy(&e5);
	AddEnemy(&e6);
	AddEnemy(&e7);
	AddEnemy(&e8);
	AddEnemy(&e9);
	AddEnemy(&e10);
	AddEnemy(&e11);*/

	// Drawing the battle
	pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);

	Point p;
	pGUI->GetPointClicked(p);

	// Now a demo to move enemies some time steps
	// TimeStep is a normal integer that is incremented each time by 1
	for(int TimeStep = 1 ; TimeStep <= 30 ; TimeStep++)
	{

		// Decrement the distance of each enemy. Just for the sake of demo
		/*e1.DecrementDist();
		e2.DecrementDist();
		e3.DecrementDist();
		e4.DecrementDist();
		e5.DecrementDist();
		e6.DecrementDist();
		e7.DecrementDist();
		e8.DecrementDist();
		e9.DecrementDist();
		e10.DecrementDist();*/

		// Redraw the enemies
		pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);

		pGUI->GetPointClicked(p);
	}

	delete pGUI;
}