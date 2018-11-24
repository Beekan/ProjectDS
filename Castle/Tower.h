#pragma once
#include "..\Defs.h"
class Tower
{
	double Health;

	//
	// TODO: Add More Data Members As Needed
	//

public:

	Tower();
	void SetHealth(double h);
	double GetHealth() const;
	void attack(Enemy* ActEnemies); //Added by me
	//
	// TODO: Add More Member Functions As Needed
	//

};

