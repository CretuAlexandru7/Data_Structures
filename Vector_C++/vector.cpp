//#include "vector.h"
//
///* The Big 5 */
//template<typename Object>
//Vector<Object>::Vector(int initSize)
//	:m_VectSize{ initSize }, m_VectCapacity{initSize + VECT_CAPACITY_SPREAD }, m_VectObjects{ nullptr }
//{
//	m_VectObjects = new Object[m_VectCapacity];
//}
//
//template<typename Object>
//Vector<Object>::Vector(const Vector& v)
//	:m_VectSize{ v.m_VectSize }, m_VectCapacity { v.m_VectCapacity }, m_VectObjects{nullptr}
//{
//	m_VectObjects = new Object[m_VectCapacity];
//	for (short i = 0; i < m_VectSize; i++)
//	{
//		this->m_VectObjects[i] = v.m_VectObjects[i];
//	}
//}
//
//template<typename Object>
//Vector<Object>& Vector<Object>::operator=(const Vector& v)
//{
//	Vector copy = v;
//	std::swap(*this, copy);
//	return *this;
//}
//
//template<typename Object>
//Vector<Object>::Vector(Vector&& v)
//	:m_VectSize{ v.m_VectSize }, m_VectCapacity{ v.m_VectCapacity }, m_VectObjects{ v.m_VectObjects }
//{
//	v.m_VectObjects = nullptr;
//	v.m_VectSize = 0;
//	v.m_VectCapacity = 0;
//}
//
//template<typename Object>
//Vector<Object>& Vector<Object>::operator=(Vector&& v)
//{
//	std::swap(this->m_VectSize, v.m_VectSize);
//	std::swap(this->m_VectCapacity, v.m_VectCapacity);
//	std::swap(this->m_VectObjects, v.m_VectObjects);
//
//	return *this;
//}
//
//template<typename Object>
//Vector<Object>::~Vector()
//{
//	delete[] this->m_VectObjects;
//}
//
//
///* Function m */
//template<typename Object>
//void Vector<Object>::vDoResize(int newSize)
//{
//	if (newSize > this->m_VectCapacity)
//	{
//		vDoReserve(newSize * VECT_CAPACITY_INCREMENT);
//	}
//
//	this->m_VectSize = newSize;
//}
//
//template<typename Object>
//void Vector<Object>::vDoReserve(int newCapacity)
//{
//	if (newCapacity < this->m_VectSize)
//		return;
//
//	Object* tempObjectArray = new Object[newCapacity];
//	for (int i = 0; i < this->m_VectSize; i++)
//	{
//		tempObjectArray[i] = std::move(this->m_VectObjects[i]);
//	}
//
//	this->m_VectCapacity = newCapacity;
//	std::swap(m_VectObjects, tempObjectArray);
//
//	delete[] tempObjectArray;
//}
//
//template <typename Object>
//void Vector<Object>::push_back(const Object& v)
//{
//	if (m_VectSize == m_VectCapacity)
//	{
//		vDoReserve(VECT_CAPACITY_INCREMENT * m_VectCapacity + 1);
//		m_VectObjects[m_VectSize++] = v;
//	}
//}
//
//template <typename Object>
//void Vector<Object>::push_back(Object&& v)
//{
//	if (m_VectSize == m_VectCapacity)
//	{
//		vDoReserve(VECT_CAPACITY_INCREMENT * m_VectCapacity + 1);
//		m_VectObjects[m_VectSize++] = std::move( v );
//	}
//}
//
//template<typename Object>
//void Vector<Object>::pop_back()
//{
//	--m_VectSize;
//}
//
//template<typename Object>
//const Object& Vector<Object>::back() const
//{
//	return m_VectObjects[m_VectSize - 1];
//}