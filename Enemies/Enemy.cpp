#include "Enemy.h"
#include "..\Castle\Tower.h"
#include "..\ActiveEnemyList.h"
Enemy::Enemy(Tower* t){
	T = t;
}

Enemy::Enemy(color r_c, REGION r_region, int d)
{
	Clr = r_c;
	Region = r_region;
	SetDistance(d);
}

Enemy::~Enemy()
{
}

void Enemy::setFSD(int f)
{
	firstshotdelay = f;
}

void Enemy::setKD(int k)
{
	killdelay = k;
	lifetime = killdelay + firstshotdelay;
}

void Enemy::setTowerpointer(Tower * t)
{
	T = t;
}

void Enemy::setOriginalhealth(int OR)
{
	originalHealth = OR;
}

void Enemy::SetID(int id)
{
	ID = id;
}

void Enemy::SetHealth(double health)
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

int Enemy::Getfreezetimer()
{
	return freezetimer;
}

int Enemy::GetOriginalHealth()
{
	return originalHealth;
}

double Enemy::Getpriority()
{
	return Priority;
}

double Enemy::GetHealth()
{
	return Health;
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

void Enemy::updatepriority()
{
	if (freezetimer != 0)
		Priority = 0;
	Priority = (1 / Distance) + Health + (reloadperiod - reloadtimer);
}

void Enemy::setsteptimer(int s)
{
	steptimer = s;
}

void Enemy::setfreezetimer(int f)
{
	freezetimer = f;
}

int Enemy::getFSD()
{
	return firstshotdelay;
}

int Enemy::getKD()
{
	return killdelay;
}

int Enemy::getLT()
{
	return lifetime;
}

int Enemy::getsteptimer()
{
	return steptimer;
}

int Enemy::GetDistance() const
{
	return Distance;
}

int Enemy::GetArrivalTime()
{
	return arrivaltime;
}
