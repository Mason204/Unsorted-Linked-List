/*
Mason Henry
Data Structures
Due: February 11th

*/

#include <iostream>
#include "UsortedType.h"

using namespace std;

int main()
{
	UnsortedType List1;
	UnsortedType List2;

	List1.InsertItem(30);
	List1.InsertItem(42);
	List1.InsertItem(2);
	List1.InsertItem(66);
	List2.InsertItem(77);
	List2.InsertItem(23);
	List2.InsertItem(99);

	List1.Union(List1, List2);

	for(int i = 0; i < 10; i++)
		List1.GetNextItem();
	List1.MakeEmpty();
	List2.MakeEmpty();

	return 0;
}