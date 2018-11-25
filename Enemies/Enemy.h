#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

//Enemies colors for next phases
//You can choose whatever colors you like for your enemies
const color FIGHTER_CLR = DARKBLUE;
const color HEALER_CLR = ORANGERED;
const color FREEZER_CLR = WHITE;

// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Enemy
{

protected:
	int ID;         //Each enemy has a unique ID (sequence number)
	color Clr;	    //Color of the enemy (will be set depending on the enemy type: Paver, ...etc.)
	REGION Region;  //Region of this enemy
	int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	double Health;	//Enemy health
	double Priority;
	int arrivaltime;
	int power;
	int reloadperiod;
	State Currentstate;
	EnemyType type;

	//
	// TODO: Add More Data Members As Needed
	//

public:
	Enemy();
	Enemy(color r_c, REGION r_region, int d = MaxDistance);
	virtual ~Enemy();

	void SetID(int id);
	void SetHealth(double health);
	void SetPriority(double pr);

	int GetID();
	double GetHealth();
	double GetPriority();

	color GetColor() const;
	REGION GetRegion() const;

	void DecrementDist();

	void SetDistance(int d);
	int GetDistance() const;

	// Virtual Functions: ----------------

	//virtual void Move() = 0;	//All enemies can move
	//virtual void Act() = 0;	//Acting means fighting or healing

	//
	// TODO: Add More Member Functions As Needed
	//

};

