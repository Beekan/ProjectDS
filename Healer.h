#pragma once
#include "Enemies\Enemy.h"
class Healer :
	public Enemy
{
public:
	Healer(Tower* t);
	void Act(Tower* &T);
	~Healer();
};

