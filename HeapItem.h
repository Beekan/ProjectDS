#ifndef Heapitem_H
#define Heapitem_H
#include"Enemies/Enemy.h"

class Heapitem
{
private:
	int m_iKey;                              // Heap item priority key
	Enemy* m_dData;                         // Dummy data value

public:
	Heapitem();                              // Default constructor
	Heapitem(int key, Enemy* data);     // Constructor
	~Heapitem();                         // Destructor
	int getKey();                         // Return item priority
	void setKey(int key);               // Set the priority key value
	Enemy* getData();                    // Return data item
	void setData(Enemy* data);          // Set the data item value
};
#endif


