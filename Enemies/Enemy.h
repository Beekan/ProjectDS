#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
//#include "..\Castle\Tower.h"

//Enemies colors for next phases
//You can choose whatever colors you like for your enemies

// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Tower;
class ActiveEnemyList;

class Enemy
{

protected:
	Tower * T;
	int ID;         //Each enemy has a unique ID (sequence number)
	color Clr;	    //Color of the enemy (will be set depending on the enemy type: Paver, ...etc.)
	REGION Region;  //Region of this enemy
	int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	double Health;	    //Enemy health
	int originalHealth;
	double Priority;
	int arrivaltime;
	int power;
	int reloadperiod;
	int reloadtimer;
	int freezetimer;
	int steptimer;
	State Currentstate;
	int firstshotdelay;
	int killdelay;
	int lifetime;


	//
	// TODO: Add More Data Members As Needed
	//

public:
	Enemy(Tower* t);
	Enemy(color r_c, REGION r_region, int d = MaxDistance);
	virtual ~Enemy();
	void setTowerpointer(Tower* t);
	void setOriginalhealth(int OR);
	void SetID(int id);
	void SetHealth(double health);
	void SetPriority(int pr);
	void setarrivaltime(int arrivaltime);
    void SetDistance(int d);
	void SetPower(int Power);
	void SetRegion(REGION region);
	void SetReloadPeriod(int Reload);
	void updatepriority();
	void setsteptimer(int s);
	void setfreezetimer(int f);
	int getsteptimer();
	int  GetDistance() const;
	int GetArrivalTime();
	int  GetID();
	int Getfreezetimer();
	int GetOriginalHealth();
	double Getpriority();
	double GetHealth();

	color GetColor() const;
	REGION GetRegion() const;

	void DecrementDist();


	// Virtual Functions: ----------------

	//virtual void Move() = 0;	//All enemies can move
	virtual void Act(Tower* &T) = 0;	//Acting means fighting or healing

	//
	// TODO: Add More Member Functions As Needed
	//

};

