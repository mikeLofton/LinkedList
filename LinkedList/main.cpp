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

	List<int> test2List = List<int>(testList);
	/*test2List.sort();*/
	test2List.destroy();
	test2List.print();

	system("pause");

	return 0;
}