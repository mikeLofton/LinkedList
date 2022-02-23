#include <iostream>
#include "List.h"

int main()
{
	List<int> testList = List<int>(); //Test List

	//Push Front/Back Test
	testList.pushBack(6);
	testList.pushBack(10);
	testList.pushBack(34);
	testList.pushBack(3);
	testList.pushBack(19);

	testList.print(); //Print

	system("pause"); //Pause

	testList.destroy();

	testList.contains(6);

	List<int> testList2 = List<int>(testList);
	testList.print();
	testList2.print();

	return 0;
}