#include <iostream>
#include "List.h"

int main()
{
	List<int> testList = List<int>();

	testList.pushFront(7);
	//testList.pushFront(8);

	testList.print();

	return 0;
}