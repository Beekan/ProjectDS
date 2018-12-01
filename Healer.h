#pragma once
#include "Enemies\Enemy.h"
class Healer :
	public Enemy
{
public:
	Healer();
	void Act();
	~Healer();
};

