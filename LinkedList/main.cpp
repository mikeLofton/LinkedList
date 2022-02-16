#include <iostream>
#include "List.h"

int main()
{
	List<int> testList = List<int>();

	testList.pushBack(6);
	testList.pushBack(10);
	testList.pushBack(34);
	testList.pushBack(3);
	testList.pushBack(19);

	testList.print();

	system("pause");

	testList.sort();
	testList.remove(7);

	testList.print();

	return 0;
}