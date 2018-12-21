#pragma once
#include "Enemies\Enemy.h"
class Freezer :
	public Enemy
{
public:
	Freezer(Tower* t);
	
	void Act(Tower* &T);
	~Freezer();
};

