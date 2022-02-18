#pragma once
template <typename T>
class Node
{
public:

	/// <summary>
	/// Base Constructor
	/// </summary>
	Node();

	/// <summary>
	/// Sets the node's data to the given value
	/// </summary>
	/// <param name="value">The given value</param>
	Node(T value);

	Node<T>* next;
	Node<T>* previous;
	T data;
};

template<typename T>
inline Node<T>::Node()
{
	next = nullptr;
	previous = nullptr;
}

template<typename T>
inline Node<T>::Node(T value)
{
	data = value;
}
