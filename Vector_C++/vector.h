#ifndef VECTOR_H
#define VECTOR_H

#define VECT_CAPACITY_SPREAD 4
#define VECT_CAPACITY_INCREMENT 2

template <typename Object>
class Vector
{
public:
	/* The Big 5 */
	explicit Vector(int initSize = 0);
	Vector(const Vector&);
	Vector(Vector &&);
	Vector& operator=(const Vector&);
	Vector& operator=(Vector &&);
	~Vector();


	/* operator[] overloading */
	Object& operator[](int index)
	{
		return this->m_VectObjects[index];
	}
	const Object& operator[](int index) const
	{
		return this->m_VectObjects[index];
	}
	
	/* "inline methods": */
	inline bool empty() const { return size() == 0; }
	inline int size() const { return this->m_VectSize; }
	inline int capacity() const { return this->m_VectCapacity; }

	/* Vect. specific methods */
	void vDoResize(int newSize);
	void vDoReserve(int newCapacity);

	void push_back(const Object& v);
	void push_back(Object && v);
	void pop_back();
	const Object& back() const;

	typedef Object* iterator;
	typedef const Object* const_iterator;

	iterator begin() { return &m_VectObjects[0]; }
	const_iterator begin() const { return &m_VectObjects[0]; }

	iterator end() { return &m_VectObjects[size()]; }
	const_iterator end() const { return &m_VectObjects[size()]; }

private:
	int m_VectSize;
	int m_VectCapacity;
	Object* m_VectObjects;
};



/* vector.cpp file */
#include "vector.h"

/* The Big 5 */
template<typename Object>
Vector<Object>::Vector(int initSize)
	:m_VectSize{ initSize }, m_VectCapacity{ initSize + VECT_CAPACITY_SPREAD }, m_VectObjects{ nullptr }
{
	m_VectObjects = new Object[m_VectCapacity];
}

template<typename Object>
Vector<Object>::Vector(const Vector& v)
	:m_VectSize{ v.m_VectSize }, m_VectCapacity{ v.m_VectCapacity }, m_VectObjects{ nullptr }
{
	m_VectObjects = new Object[m_VectCapacity];
	for (short i = 0; i < m_VectSize; i++)
	{
		this->m_VectObjects[i] = v.m_VectObjects[i];
	}
}

template<typename Object>
Vector<Object>& Vector<Object>::operator=(const Vector& v)
{
	Vector copy = v;
	std::swap(*this, copy);
	return *this;
}

template<typename Object>
Vector<Object>::Vector(Vector&& v)
	:m_VectSize{ v.m_VectSize }, m_VectCapacity{ v.m_VectCapacity }, m_VectObjects{ v.m_VectObjects }
{
	v.m_VectObjects = nullptr;
	v.m_VectSize = 0;
	v.m_VectCapacity = 0;
}

template<typename Object>
Vector<Object>& Vector<Object>::operator=(Vector&& v)
{
	std::swap(this->m_VectSize, v.m_VectSize);
	std::swap(this->m_VectCapacity, v.m_VectCapacity);
	std::swap(this->m_VectObjects, v.m_VectObjects);

	return *this;
}

template<typename Object>
Vector<Object>::~Vector()
{
	delete[] this->m_VectObjects;
}


/* Function m */
template<typename Object>
void Vector<Object>::vDoResize(int newSize)
{
	if (newSize > this->m_VectCapacity)
	{
		vDoReserve(newSize * VECT_CAPACITY_INCREMENT);
	}

	this->m_VectSize = newSize;
}

template<typename Object>
void Vector<Object>::vDoReserve(int newCapacity)
{
	if (newCapacity < this->m_VectSize)
		return;

	Object* tempObjectArray = new Object[newCapacity];
	for (int i = 0; i < this->m_VectSize; i++)
	{
		tempObjectArray[i] = std::move(this->m_VectObjects[i]);
	}

	this->m_VectCapacity = newCapacity;
	std::swap(m_VectObjects, tempObjectArray);

	delete[] tempObjectArray;
}

template <typename Object>
void Vector<Object>::push_back(const Object& v)
{
	if (m_VectSize == m_VectCapacity)
	{
		vDoReserve(VECT_CAPACITY_INCREMENT * m_VectCapacity + 1);
		m_VectObjects[m_VectSize++] = v;
	}
}

template <typename Object>
void Vector<Object>::push_back(Object&& v)
{
	if (m_VectSize == m_VectCapacity)
	{
		vDoReserve(VECT_CAPACITY_INCREMENT * m_VectCapacity + 1);
	}
	m_VectObjects[m_VectSize++] = std::move(v);
}

template<typename Object>
void Vector<Object>::pop_back()
{
	--m_VectSize;
}

template<typename Object>
const Object& Vector<Object>::back() const
{
	return m_VectObjects[m_VectSize - 1];
}

#endif
