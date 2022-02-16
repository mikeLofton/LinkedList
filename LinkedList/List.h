#pragma once
#include "Iterator.h"
#include <iostream>
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
	void pushFront(const T& value);

	/// <summary>
	/// Adds a new node to the end of the list
	/// </summary>
	/// <param name="value"></param>
	void pushBack(const T& value);

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
	int getLength() const { return m_nodeCount; }

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
	*this = other;
}

template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline void List<T>::destroy()
{
	Node<T>* temp2; //Create a temp2 node

	//Create a temp node and set it to first
	// While the temp node does not equal null pointer loop
	//Set temp to temp2
	for (Node<T>* temp = m_first; temp != nullptr; temp = temp2 )
	{
		//Set temp2 to equal temp's next
		temp2 = temp->next;
		//Delete temp
		delete temp;
	}
	initialize(); //Initialize the list
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>(m_first);
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>(m_last->next);
}

template<typename T>
inline bool List<T>::contains(const T object) const
{
	for (Iterator<T> iter = begin(); iter != end(); ++iter)
	{
		if (*iter == object) //If the data the iterator is looking at equals the object
			return true; //Return true
		return false; //Otherwise return false
	}
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Node<T>* newNode = new Node<T>(value); //Create a new node 

	if (m_first != nullptr) //If first is not null
	{
		m_first->previous = newNode; //Set first's previous node to be the new node
		newNode->next = m_first; //Set the new node's next node to be first
	}

	m_first = newNode; //Set newNode to be first

	if (m_last == nullptr) //If last is null
	{
		m_last = newNode; //Set last to be the newNode
	}

	m_nodeCount++; //Increment the node count
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	Node<T>* newNode = new Node<T>(value); //Create a new node

	if (m_last != nullptr) //If last is not null
	{
		m_last->next = newNode; //Set last's next node to be the new node
		newNode->previous = m_last; //Set the new node's previous node to be last
	}

	m_last = newNode; //Set newNode to be last

	if (m_first == nullptr) //If the first is null
	{
		m_first = newNode; //Set first to be the newNode
	}

	m_nodeCount++; //Increment the node count
	
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	//If the given index is less than zero or more than the number of nodes return false
	if (index < 0 || index > m_nodeCount)
		return false;

	if (isEmpty() || index == 0) //If the list is empty or the given index is zero
	{
		pushFront(value); //Push the value to the front
		return true; //Return true
	}
	else if (index == m_nodeCount) //If the given index equals the total node count 
	{
		pushBack(value); //Push the value to the back
		return true; //Return true
	}

	Node<T>* newNode = new Node<T>(value); //Create a new node
	Node<T>* currentNode = new Node<T>(); //Create a current node

	currentNode = m_first; //Set current node to first

	for (int i = 0; i < index; i++) //While i is less than the given index
	{
		currentNode = currentNode->next; //Set current node to its next
	}

	newNode->next = currentNode; //Set the new node's next to current node
	newNode->previous = currentNode->previous; //Set the new node's previous to the current node's previous
	currentNode->previous->next = newNode; //Set the currentNode's previous node's next to newNode
	currentNode->previous = newNode; //Set the currentNode's previous to be the newNode
	m_nodeCount++; //Increment the node count
}

template<typename T>
inline void List<T>::remove(const T& value)
{
	if (isEmpty()) //If the list is empty return
		return;
	else if (!contains(value)) //If the list doesn't contain the value return
		return;

	Node<T>* nodeToRemove = new Node<T>(); //The node you want to remove

	nodeToRemove = m_first; //Set nodeToRemove to first

	for (Iterator<T> iter = begin(); *iter != value; ++iter) //While the iter's data does not equal value
	{
		nodeToRemove = nodeToRemove->next; //Set the nodeToRemove to its next
	}

	if (nodeToRemove->previous == nullptr) //If the nTR's previous is null
	{
		nodeToRemove->next->previous = nullptr; //Set nTR's next's previous to nullptr
		m_first = nodeToRemove->next; //Set first to nTR's next
		delete nodeToRemove; //Delete nodeToRemove
		m_nodeCount--; //Decrement the node count
	}
	else if (nodeToRemove->next == nullptr) //If nTR's next is null
	{
		nodeToRemove->previous->next = nullptr; //Set nTR's previous' next to nullptr
		m_last = nodeToRemove->previous; //Set last to nTR's previous
		delete nodeToRemove; //Delete nodeToRemove
		m_nodeCount--; //Decrement the node count
	}
	else
	{
		nodeToRemove->next->previous = nodeToRemove->previous; //Set nTR's next's previous to nTR's previous
		nodeToRemove->previous->next = nodeToRemove->next; //Set nTR's previous' next to nTR's next
		delete nodeToRemove; //Delete nodeToRemove
		m_nodeCount--; //Decrement the node count 
	}
}

template<typename T>
inline void List<T>::print() const
{
	if (isEmpty()) //If the list is empty return
		return;

	for (Iterator<T> iter = begin(); iter != end(); ++iter)
	{
		std::cout << *iter << std::endl; //Print the data the iterator is looking at
	}
}

template<typename T>
inline void List<T>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	if (m_first == nullptr && m_last == nullptr) //If the first node and last node are null
		return true; //Return true
	else
		return false;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	iter = begin();

	for (int i = 0; i < index; i++)
		++iter;

	return *iter;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	destroy(); //Destroy the list's data

	//Iterate through the other list's data
	for (Iterator<T> iter = otherList.begin(); iter != otherList.end(); ++iter)
	{
		pushBack(*iter); //Copy the otherlist's data into this list
	}

	return *this; //Return this list
}

template<typename T>
inline void List<T>::sort()
{
	T temp;

	for (int i = 0; i < getLength() - 1; i++)
	{
		for (int j = 0; j < getLength() - i - 1; j++)
		{
			
		}
	}
}
