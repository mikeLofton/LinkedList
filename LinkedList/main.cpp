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

	testList.sort();

	testList.remove(10);

	testList.print();

	system("pause");

	testList.insert(45, 2);

	testList.print();

	List<int> testList2 = testList;

	system("pause");
	
	return 0;
}