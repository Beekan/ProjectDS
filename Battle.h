#pragma once

#include "Enemies\Enemy.h"
#include "Castle\Castle.h"
#include "InactiveEnemyList.h"
#include <fstream>

// it is the controller of the project
class Battle
{
private:
	Castle BCastle;
	GUI* pGUI;
	InactiveEnemyList IEL;
	int EnemyCount;	//the actual number of enemies in the game
	Enemy * BEnemiesForDraw[MaxEnemyCount]; // This Array of Pointers is used for drawing elements in the GUI
								  			// No matter what list type you are using to hold enemies, 
											// you must pass the enemies to the GUI function as an array of enemy pointers. 
											// At every time step, you should update those pointers 
											// to point to the current active enemies 
											// then pass the pointers list to the GUI function

	//
	// TODO: Add More Data Members As Needed
	//

public:
	
	Battle();
	ifstream LoadFile;
	void readfile(GUI* pGUI);
	void AddEnemy(Enemy*& Ptr);
	Castle * GetCastle();
	void movetoactive(int simulationtick);
	void RunSimulation();

	void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2

	//
	// TODO: Add More Member Functions As Needed
	//
};

