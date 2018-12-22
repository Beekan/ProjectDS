#include "Battle.h"
#include <iostream>
#include <fstream>
#include"Fighter.h"
#include"Healer.h"
#include"Freezer.h"


Battle::Battle()
{
	totalenemycount = 0;
	EnemyCount = 0;
}

void Battle::writefile()
{
	outFile.open("output.txt");
	int killedenemies = BCastle.getkilledenemies();
	int KTS, S, FD, LT;
	double avgKTS=0, avgKD=0;
	Enemy* E;
	double totaldamage1, totaldamage2, totaldamage3, totaldamage4;
	BCastle.rettowerdamage(totaldamage1, totaldamage2, totaldamage3, totaldamage4);
	outFile << "KTS  " << "S  " << "FD  " << "LT" << endl;
	while (killedenemies) {
		killedenemies--;
		if (BCastle.dequeuekilled(E)) {
			avgKTS = avgKTS + E->getKTS();
			avgKD = avgKD + E->getKD();
			outFile << to_string(E->getKTS()) << "  " << to_string(E->GetID()) << "  " << to_string(E->getFSD()) << "  " << to_string(E->getLT()) << endl;
		}
	}
	avgKTS = avgKTS / BCastle.getkilledenemies();
	avgKD = avgKD / BCastle.getkilledenemies();
	outFile << "T1_damage  " << "T2_damage  " << "T3_damage  " << "T4_damage  " << endl;
	outFile << to_string(totaldamage1) << "  " << to_string(totaldamage2) << "  " << to_string(totaldamage3) << "  " << to_string(totaldamage4) << endl;

	if (totalenemycount == BCastle.getkilledenemies()) {
		outFile << "WIN" << endl;
		outFile << "Total Number of Enemies= " << to_string(BCastle.getkilledenemies()) << endl;
		outFile << "Average KTS= " << to_string(avgKTS) << endl;
		outFile << "Average KD= " << to_string(avgKD) << endl;
	}
	else if (4 == BCastle.getkilledtowers()) {
		outFile << "LOSE" << endl;
		outFile << "Number of killed Enemies= " << to_string(BCastle.getkilledenemies()) << endl;
		outFile << "Number of active Enemies= " << to_string(EnemyCount+IEL.retCount()) << endl;
		outFile << "Average KTS= " << to_string(avgKTS) << endl;
		outFile << "Average KD= " << to_string(avgKD) << endl;
	}
	else {
		outFile << "DRAW" << endl;
		outFile << "Total Number of Enemies= " << to_string(BCastle.getkilledenemies()) << endl;
		outFile << "Number of active Enemies= " << to_string(EnemyCount + IEL.retCount()) << endl;
		outFile << "Average KTS= " << to_string(avgKTS) << endl;
		outFile << "Average KD= " << to_string(avgKD) << endl;
	}
	outFile.close();
}

void Battle::simulateInteractive(GUI*  pGUI)
{
	//GUI*  pGUI = new GUI;
	
	double towerA, towerB, towerC, towerD;
	int enemyA, enemyB, enemyC, enemyD;
	int killedA, killedB, killedC, killedD;
	string info;
	string einfo;
	string kinfo;
	string ActiveEnemies;


	readfile(pGUI);
	pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);
	Point p;
	pGUI->GetPointClicked(p);
	for (int timestep = 0; timestep < SimulationTime; timestep++) {
		if (totalenemycount == BCastle.getkilledenemies() || 4 == BCastle.getkilledtowers()) { break; }
		BCastle.ACT(timestep);
		BCastle.gettowerhealth(towerA, towerB, towerC, towerD);
		BCastle.retCount(enemyA, enemyB, enemyC, enemyD);
		BCastle.retKilled(killedA, killedB, killedC, killedD);
		info = "Tower A health= " + to_string(towerA) + " Tower B health= " + to_string(towerB) + " Tower C health= " + to_string(towerC) + "Tower D health= " + to_string(towerD);
		einfo = "Tower A enemy= " + to_string(enemyA) + " Tower B enemy= " + to_string(enemyB) + " Tower C enemy= " + to_string(enemyC) + "Tower D enemy= " + to_string(enemyD);
		kinfo = "Tower A killed= " + to_string(killedA) + " Tower B killed= " + to_string(killedB) + " Tower C killed= " + to_string(killedC) + "Tower D killed= " + to_string(killedD);
		movetoactive(timestep);
		SortNulls(BEnemiesForDraw, EnemyCount);
		pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);

		pGUI->PrintMessage(einfo);
		pGUI->GetPointClicked(p);
	}
	writefile();


}

void Battle::simulateSilent(GUI*  pGUI)
{


	//GUI*  pGUI = new GUI;
	double towerA, towerB, towerC, towerD;
	int enemyA, enemyB, enemyC, enemyD;
	int killedA, killedB, killedC, killedD;
	string info;
	string einfo;
	string kinfo;
	string ActiveEnemies;


	readfile(pGUI);
	pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);
	Point p;
	pGUI->GetPointClicked(p);
	for (int timestep = 0; timestep < SimulationTime; timestep++) {
		if (totalenemycount == BCastle.getkilledenemies() || 4 == BCastle.getkilledtowers()) { break; }
		BCastle.ACT(timestep);
		BCastle.gettowerhealth(towerA, towerB, towerC, towerD);
		BCastle.retCount(enemyA, enemyB, enemyC, enemyD);
		BCastle.retKilled(killedA, killedB, killedC, killedD);
		info = "Tower A health= " + to_string(towerA) + " Tower B health= " + to_string(towerB) + " Tower C health= " + to_string(towerC) + "Tower D health= " + to_string(towerD);
		einfo = "Tower A enemy= " + to_string(enemyA) + " Tower B enemy= " + to_string(enemyB) + " Tower C enemy= " + to_string(enemyC) + "Tower D enemy= " + to_string(enemyD);
		kinfo = "Tower A killed= " + to_string(killedA) + " Tower B killed= " + to_string(killedB) + " Tower C killed= " + to_string(killedC) + "Tower D killed= " + to_string(killedD);
		movetoactive(timestep);
		SortNulls(BEnemiesForDraw, EnemyCount);
//
		pGUI->PrintMessage(einfo);
//
	}
	writefile();


}


void Battle::readfile(GUI* pGUI)
{
	
	pGUI->PrintMessage("Please, Enter the File name.");
	string FileName = pGUI->GetString();
	LoadFile.open(FileName); 
	while (!LoadFile) { pGUI->PrintMessage("File name does not exist. Please enter a correct one"); FileName = pGUI->GetString(); LoadFile.open(FileName); }
	int MaxEnemy, TowerPower, EnemyID,EnemyType,EnemyHealth,EnemyPower,Reloadperiod,Arrivaltime,TowerHealth;
	REGION EnemyRegion;
	char Region;
	Enemy* Enemy;
	string line;
	Tower* T;
	LoadFile >> TowerHealth;
	LoadFile >> MaxEnemy;
	LoadFile >> TowerPower;
	BCastle.SetTowerHealth(TowerHealth);
	BCastle.SetMaxEnemy(MaxEnemy);
	BCastle.SetTowerPower(TowerPower);
	while(1) 
	{
		
		LoadFile >> EnemyID;
		if (EnemyID == -1) { break; }
		LoadFile >> EnemyType;
		LoadFile >> Arrivaltime;
		LoadFile >> EnemyHealth;
		LoadFile >> EnemyPower;
		LoadFile >> Reloadperiod;
		LoadFile >> Region;
		totalenemycount++;
		EnemyRegion = static_cast<REGION>(Region-65);
		Fighter* Fight = new Fighter(&BCastle.retTower(EnemyRegion));
		Healer * Heal = new Healer(&BCastle.retTower(EnemyRegion));
		Freezer * Freeze = new Freezer(&BCastle.retTower(EnemyRegion));
		switch (EnemyType) {
		case 1:
			
			Enemy = Fight;
			break;
		case 2:
			
			Enemy = Heal;
		    break;
		case 3:
			
			Enemy = Freeze;
            break;
		default:
			break;
		}
		Enemy->setarrivaltime(Arrivaltime);
		Enemy->setOriginalhealth(EnemyHealth);
		Enemy->SetHealth(EnemyHealth);
		Enemy->SetID(EnemyID);
		Enemy->SetPower(EnemyPower);
		Enemy->SetRegion(EnemyRegion);
		Enemy->SetReloadPeriod(Reloadperiod);
		IEL.enqueue(Enemy);
	}
	
}

void Battle::AddEnemy(Enemy*& Ptr)
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

void Battle::movetoactive(int simulationtick)
{
	Enemy* Enemy;
	if (IEL.peekFront(Enemy))
	{
        if (Enemy->GetArrivalTime() <= simulationtick)
		{
			IEL.dequeue(Enemy);
			Enemy->SetDistance(MaxDistance);
			BCastle.AddEnemy(Enemy);
			this->AddEnemy(Enemy);
		}
	}
	if (IEL.peekFront(Enemy)) 
	{
	    if (Enemy->GetArrivalTime() <= simulationtick) 
		{
			movetoactive(simulationtick);
		}
	}
}






void Battle::RunSimulation()
{
	GUI*  pGUI = new GUI;

	string Mode = pGUI->GetString();
	
	if (Mode == "1")
	{
		simulateInteractive(pGUI);

	}

	else 

	{
		simulateSilent(pGUI);
		// call silent
	}

	
	
	
	
	/*GUI*  pGUI = new GUI;
	double towerA, towerB, towerC, towerD;
	int enemyA, enemyB, enemyC, enemyD;
	int killedA, killedB, killedC, killedD;
	string info;
	string einfo;
	string kinfo;
	string ActiveEnemies;


	readfile(pGUI);
	pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);
	Point p;
	pGUI->GetPointClicked(p);
	for (int timestep = 0; timestep < SimulationTime; timestep++) {
		if (totalenemycount == BCastle.getkilledenemies() || 4 == BCastle.getkilledtowers()) { break; }
		BCastle.ACT(timestep);
		BCastle.gettowerhealth(towerA, towerB, towerC, towerD);
		BCastle.retCount(enemyA, enemyB, enemyC, enemyD);
		BCastle.retKilled(killedA, killedB, killedC, killedD);
		info = "Tower A health= " + to_string(towerA) + " Tower B health= " + to_string(towerB) + " Tower C health= " + to_string(towerC) + "Tower D health= " + to_string(towerD);
		einfo = "Tower A enemy= " + to_string(enemyA) + " Tower B enemy= " + to_string(enemyB) + " Tower C enemy= " + to_string(enemyC) + "Tower D enemy= " + to_string(enemyD);
		kinfo = "Tower A killed= " + to_string(killedA) + " Tower B killed= " + to_string(killedB) + " Tower C killed= " + to_string(killedC) + "Tower D killed= " + to_string(killedD);
		movetoactive(timestep);
		SortNulls(BEnemiesForDraw, EnemyCount);
		pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);

		pGUI->PrintMessage(einfo);
		pGUI->GetPointClicked(p);
	}
	writefile();
	*/
}

void Battle::SortNulls(Enemy* arr[], int &size)
{
	Enemy* arr2[MaxEnemyCount];
	Enemy * temp;
	int s = size;
	int c = 0;
	for (int i = 0; i < s; i++)
	{
		if (size > 0) {
			if (arr[i]->GetHealth()==0)
			{
				temp = arr[size-1];
				arr[size-1] = arr[i];
				arr[i] = temp;
				c++;
				
				//EnemyCount--;
			}
		}
	}
	size=size-c/2;
}