#ifndef HEAPITEM_H
#define HEAPITEM_H
template <class T>
class HeapItem
{
private:
	int m_iKey;                              // Heap item priority key
	T m_dData;                         // Dummy data value

public:
	HeapItem();                              // Default constructor
	HeapItem(int key, T data);     // Constructor
	~HeapItem();                         // Destructor
	int getKey();                         // Return item priority
	void setKey(int key);               // Set the priority key value
	double getData();                    // Return data item
	void setData(T data);          // Set the data item value
};


//-----------------------------------
// Default constructor
//-----------------------------------
template <class T>
HeapItem<T>::HeapItem()
{
	m_iKey = 0;
}

//-----------------------------------
// Constructor
//-----------------------------------
template <class T>
HeapItem<T>::HeapItem(int key, T data)
{
	m_iKey = key;
	m_dData = data;
}

//-----------------------------------
// Destructor
//-----------------------------------
template <class T>
HeapItem<T>::~HeapItem()
{
}

//-----------------------------------
// Return item priority
//-----------------------------------
template <class T>
int HeapItem<T>::getKey()
{
	return m_iKey;
}

//-----------------------------------
// Set the priority key value
//-----------------------------------
template <class T>
void HeapItem<T>::setKey(int key)
{
	m_iKey = key;
}

//-----------------------------------
// Return data item
//-----------------------------------
template <class T>
double HeapItem<T>::getData()
{
	return m_dData;
}

//-----------------------------------
// Set the data item value
//-----------------------------------
template <class T>
void HeapItem<T>::setData(T data)
{
	m_dData = data;
}
#endif