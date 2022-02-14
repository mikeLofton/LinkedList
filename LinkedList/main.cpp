#include <iostream>
#include "List.h"

int main()
{
	List<int> testList = List<int>();

	testList.pushFront(7);
	testList.pushFront(8);
	testList.pushBack(10);
	testList.pushBack(23);

	testList.print();

	system("pause");

	testList.destroy();

	testList.print();

	return 0;
}