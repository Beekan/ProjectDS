#include "Enemy.h"
Enemy::Enemy(){}

Enemy::Enemy(color r_c, REGION r_region, int d)
{
	Clr = r_c;
	Region = r_region;
	SetDistance(d);
}
Enemy::Enemy()
{
}
Enemy::~Enemy()
{
}

void Enemy::SetID(int id)
{
}

void Enemy::SetHealth(double health)
{
}

void Enemy::SetPriority(double pr)
{
}

int Enemy::GetID()
{
	return ID;
}

double Enemy::GetHealth()
{
	return 0.0;
}

double Enemy::GetPriority()
{
	return 0.0;
}

color Enemy::GetColor() const
{
	return Clr;
}

REGION Enemy::GetRegion() const
{
	return Region;
}

void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}
