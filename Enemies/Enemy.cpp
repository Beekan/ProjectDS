#include "Enemy.h"
Enemy::Enemy(){}

Enemy::Enemy(color r_c, REGION r_region, int d)
{
	Clr = r_c;
	Region = r_region;
	SetDistance(d);
}

Enemy::~Enemy()
{
}

void Enemy::SetID(int id)
{
	ID = id;
}

void Enemy::SetHealth(int health)
{
	Health = health;
}

void Enemy::SetPriority(int pr)
{
}

void Enemy::setarrivaltime(int artime)
{
	arrivaltime = artime;
}

int Enemy::GetID()
{
	return ID;
}

double Enemy::GetHealth()
{
	return Health;
}

double Enemy::GetPriority()
{
	return Priority;
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

void Enemy::SetPower(int Power)
{
	power = Power;
}

void Enemy::SetRegion(REGION region)
{
	Region = region;
}

void Enemy::SetReloadPeriod(int Reload)
{
	reloadperiod = Reload;
}

int Enemy::GetDistance() const
{
	return Distance;
}

int Enemy::GetArrivalTime()
{
	return arrivaltime;
}
