**Michael Lofton**

s218033 

Code Design and Data Structures

LinkedList

# I. Requirements
    
 1. **Description of Problem**

    **Name:** LinkedList

    **Problem Statement:** 

    Implement a Doubly Linked List.

    **Problem Specifications:**
    
    * Completion of functons given in the UML. 

 2. **Input Information:**
    * Functions can be tested in the main class.
 3. **Output Information:**
    * The results of the functions can be printed in the console window.

# II. Design
 1. *System Architecture*

 2. *Object Information*
    * **File Name:** main.cpp
        * Name: main()
            * Description: Runs the test code.
            * Visibility: public
            * Type: int
    * **File Name:** Node.h
        * **Class Name:** Node (template: typename T)
        * Name: Node()
            * Description: Node's base constructor. Initializes the node's next and previous to null pointer.
            * Visibility: public
        * Name: Node(T value)
            * Description: Constructor that sets the node's data to a given value.
            * Visibility: public
        * Name: next(Node(T)*)
            * Description: The node's next node.
            * Visibility: public
        * Name: previous(Node(T)*)
            * Description: The node's previous node.
            * Visibility: public
        * Name: data(T)
            * Description: The data the node contains.
            * Visibility: public
    * **File Name:** Iterator.h
        * **Class Name:** Iterator (template: typename T)
        * Name: Iterator()
            * Description: Iterator's base constructor. Initializes current node to null pointer.
            * Visibility: public
        * Name: Iterator(Node(T)* node)
            * Description: Constructor that sets the iterator's current node.
            * Visibility: public
        * Name: ++()
            * Description: Sends the iterator forward in the list.
            * Visibility: public
            * Type: Iterator(T) operator
        * Name: --()
            * Description: Sends the iterator backwards in the list.
            * Visibility: public
            * Type: Iterator(T) operator
        * Name: ==(const Iterator(T)& iter)
            * Description: Compares the iterator to another. Returns true if the iterators are equal.
            * Visibility: public
            * Type: const bool
        * Name: !=(const Iterator(T)& iter)
            * Description: Compares the iterator to another. Returns true if the iterators are not equal.
            * Visibility: public
            * Type: const bool
        * Name: *()
            * Description: Returns the current node's data.
            * Visibility: public
            * Type: T
        * Name: m_current(Node(T)*)
            * Description: The current node that the iterator is reading.
            * Visibility: private
    * **File Name:** List.h
        * **Class Name:** List (template: typename T)
        * Name: List()
            * Description: List's base constructor. Initializes the first and last node and the node count.
            * Visibility: public
        * Name: List(const List(T)& other)
            * Description: Constructor meant to set the list's data to equal another list's data.
            * Visibility: public
        * Name: ~List()
            * Description: Destructor that destroys all nodes in the list.
            * Visibility: public
        * Name: destroy()
            * Description: Deletes all nodes in the list.
            * Visibility: public
            * Type: void
        * Name: begin() const
            * Description: Returns an iterator pointing to the first node in the list.
            * Visibility: public
            * Type: Iterator(T)
        * Name: end() const
            * Description: Returns an iterator pointing to the next item after the last node.
            * Visibility: public
            * Type: Iterator(T)
        * Name: contains(const T object) const
            * Description: Checks to see if the given object is in the list.
            * Visibility: public
            * Type: bool
        * Name: pushFront(const T& value)
            * Description: Adds a new node to the beginning of the list.
            * Visibility: public
            * Type: void
        * Name: pushBack(const T& value)
            * Description: Adds a new node to the end of the list.
            * Visibility: public
            * Type: void
        * Name: insert(const T& value, int index)
            * Description: Adds a new node to the list at the given index.
            * Visibility: public
            * Type: bool
        * Name: remove(const T& value)
            * Description: Removes all nodes with the given value from the list.
            * Visibility: public
            * Type: void
        * Name: print() const
            * Description: Prints the values of all the nodes in the list.
            * Visibility: public
            * Type: void
        * Name: initialize()
            * Description: Sets the first and last node to null pointer. Sets the node count to zero.
            * Visibility: public
            * Type: void
        * Name: isEmpty() const
            * Description: Returns whether or not the list has any nodes in it.
            * Visibility: public
            * Type: bool
        * Name: getData(Iterator(T)& iter, int index)
            * Description: Sets the given iterator to point to a node at the given index.
            * Visibility: public
            * Type: bool
        * Name: getLength() const
            * Description: Returns the amount of nodes in the list.
            * Visibility: public
            * Type: int
        * Name: =(const List(T)& otherList)
            * Description: Copies the values of the other list into this list.
            * Visibility: public
            * Type: const List(T)& operator
        * Name: sort()
            * Description: Sorts the values in the list in numerical order using bubble sort.
            * Visibility: public
            * Type: void
        * Name: m_first(Node(T)*)
            * Description: Pointer to the first node in the list.
            * Visibility: private
        * Name: m_last(Node(T)*)
            * Description: Pointer to the last node in the list.
            * Visibility: private
        * Name: m_nodeCount(int)
            * Description: The number of nodes in the list.
            * Visibility: private