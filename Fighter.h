#pragma once
#include "Enemies\Enemy.h"
class Fighter :public Enemy
{
	
public:
	Fighter(Tower* t);
	void Act(Tower* &T);
	~Fighter();
};

