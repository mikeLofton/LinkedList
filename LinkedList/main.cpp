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

	//Sort Test
	testList.sort(); 
	//Remove Test
	testList.remove(10);

	testList.print();	

	system("pause");
	//Insert test
	testList.insert(45, 2);

	testList.print();

	system("pause");

	return 0;
}