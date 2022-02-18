#pragma once
#include "Node.h"
template <typename T>
class Iterator
{
public:

	/// <summary>
	/// Base Constructor
	/// </summary>
	Iterator();

	/// <summary>
	/// Constructor that sets the iterator's current node
	/// </summary>
	/// <param name="node">The given node</param>
	Iterator(Node<T>* node);

	/// <summary>
	/// Sends the iterator forward
	/// </summary>
	/// <returns>This iterator's new position</returns>
	Iterator<T> operator ++();

	/// <summary>
	/// Sends the iterator backwards
	/// </summary>
	/// <returns>This iterator's new position</returns>
	Iterator<T> operator --();

	/// <summary>
	/// Compares the iterator to another
	/// </summary>
	/// <param name="iter">The iterator to compare to</param>
	/// <returns>True if the iterators are equal</returns>
	const bool operator ==(const Iterator<T>& iter);

	/// <summary>
	/// Compares the iterator to another
	/// </summary>
	/// <param name="iter">The iterator to compare to</param>
	/// <returns>True if the iterators are not equal</returns>
	const bool operator !=(const Iterator<T>& iter);

	/// <summary>
	/// Dereferences the iterator
	/// </summary>
	/// <returns>The data of the current node</returns>
	T operator *();

private:
	Node<T>* m_current;
};

template<typename T>
inline Iterator<T>::Iterator()
{
	m_current = nullptr; //Set the current node to null pointer
}

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	m_current = node; //Set current node to the given node
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
		m_current = m_current->next; //Set current node to its next then return the dereferenced iterator
		return *this;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	m_current = m_current->previous; //Set the current node to its previous then return the dereferenced iterator
	return *this;
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	if (m_current == iter.m_current) //If current equals the other iterator's current return true
		return true;
	else
		return false; //Else return false
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	if (m_current != iter.m_current) //If the current does not equal the other iterator's current return true
		return true;
	else
		return false; //Else return false
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return m_current->data; //Return the current node's data
}
