#include <iostream>
#include "List.h"

int main()
{
	List<int> testList = List<int>();

	testList.pushBack(1);
	testList.pushBack(2);
	testList.pushBack(3);
	testList.pushBack(4);
	testList.pushBack(5);

	testList.print();

	system("pause");

	testList.remove(6);

	testList.print();

	return 0;
}