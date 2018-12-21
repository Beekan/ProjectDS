#include "Heapitem.h"



Heapitem::Heapitem()
{
	m_iKey = 0;
}

//-----------------------------------
// Constructor
//-----------------------------------

Heapitem::Heapitem(double key, Enemy* data)
{
	m_iKey = key;
	m_dData = data;
}

//-----------------------------------
// Destructor
//-----------------------------------

Heapitem::~Heapitem()
{
}

//-----------------------------------
// Return item priority
//-----------------------------------

int Heapitem::getKey()
{
	return m_iKey;
}

//-----------------------------------
// Set the priority key value
//-----------------------------------

void Heapitem::setKey(double key)
{
	m_iKey = key;
}

//-----------------------------------
// Return data item
//-----------------------------------

Enemy* Heapitem::getData()
{
	return m_dData;
}

//-----------------------------------
// Set the data item value
//-----------------------------------

void Heapitem::setData(Enemy* data)
{
	m_dData = data;
}
