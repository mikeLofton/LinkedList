#pragma once
#include "Iterator.h"
template <typename T>
class List
{
public:
	List();
	List(const List<T>& other);
	~List();

	/// <summary>
	/// Deletes all nodes in the list
	/// </summary>
	void destroy();

	/// <returns>An iterator pointing to the first node in the list</returns>
	Iterator<T> begin() const;

	/// <returns>The next item after the last node in the list</returns>
	Iterator<T> end() const;

	/// <summary>
	/// Checks to see if the given item is in the list
	/// </summary>
	/// <param name="object"></param>
	bool contains(const T object) const;

	/// <summary>
	/// Adds a new node to the beginning of the list
	/// </summary>
	/// <param name="value"></param>
	void pushFront(const T& value) const;

	/// <summary>
	/// Adds a new node to the end of the list
	/// </summary>
	/// <param name="value"></param>
	void pushBack(const T& value) const;

	/// <summary>
	/// Adds a new node at the given index
	/// </summary>
	/// <param name="value"></param>
	/// <param name="index"></param>
	bool insert(const T& value, int index);

	/// <summary>
	/// Remove all nodes with the given value
	/// </summary>
	/// <param name="value"></param>
	void remove(const T& value);

	/// <summary>
	/// Prints the values of all the nodes
	/// </summary>
	void print() const;

	/// <summary>
	/// Set the default values for the first node pointer, last node pointer, and the node count
	/// </summary>
	void initialize();

	/// <returns>Whether or not the list has any nodes in it</returns>
	bool isEmpty() const;

	/// <summary>
	/// Sets the given iterator to point to a node at the given index
	/// </summary>
	/// <param name="iter"></param>
	/// <param name="index"></param>
	bool getData(Iterator<T>& iter, int index);

	/// <returns>The amount of nodes in the list</returns>
	int getLength() const;

	const List<T>& operator =(const List<T>& otherList);

	/// <summary>
	/// Bubble Sort
	/// </summary>
	void sort();

private:
	Node<T>* m_first;
	Node<T>* m_last;
	int m_nodeCount;
};

template<typename T>
inline List<T>::List()
{
	initialize();
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
	m_first = other.m_first;
	m_last = other.m_last;
	m_nodeCount = other.m_nodeCount;
}

template<typename T>
inline void List<T>::destroy()
{
	
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>(m_first);
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>(m_last);
}

template<typename T>
inline bool List<T>::contains(const T object) const
{
	return false;
}

template<typename T>
inline void List<T>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}
