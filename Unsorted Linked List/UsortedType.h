#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include <string>

using namespace std;

typedef int ItemType;
enum RelationType
{
	Less,
	Greater,
	Equal
};

struct Node
{
	ItemType info;
	Node* next;
};


class UnsortedType
{
public:

	UnsortedType();
	~UnsortedType();

	void InsertItem(ItemType value);
	void DeleteItem(ItemType value);
	ItemType GetNextItem();
	void MakeEmpty();
	bool IsFull();
	void ResetList();
	int GetLength();
	Node* search(ItemType value);
	UnsortedType Union(UnsortedType List2);
	RelationType ComparedTo(ItemType value1, ItemType value2);

private:
	int length;
	Node* head;
	Node* Pos;	
	const ItemType Max = 100000000;
};

#endif UNSORTEDTYPE_H