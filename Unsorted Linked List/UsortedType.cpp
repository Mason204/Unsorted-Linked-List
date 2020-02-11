#include "UsortedType.h"

//class constructor
UnsortedType::UnsortedType()
{
	length = 0;
	head = nullptr;
}

UnsortedType::~UnsortedType()
{
	MakeEmpty();
}

//Pre:value has been entered
//Post:Inserts value into list and increases list length.
void UnsortedType::InsertItem(ItemType value)
{
	Node* loc;

	//creates a new address
	loc = new Node;
	//Sets the value that was entered into the new node spot.
	loc->info = value;
	//Sets Next equal to the next item of the list or null if it is the first item added to the list.
	loc->next = head;
	//moves the head to the new beginning of the list.
	head = loc;
	//Increases the length of the list.
	length++;
}

//Pre:Value to search for has been entered.
//Post:Removes said value from the list if it contained in it.
void UnsortedType::DeleteItem(ItemType value)
{
	Node* loc = head;
	Node* prev = head;
	//If the value is the first in line it moves head to the next value and deletes the first one.
	if (loc->info == value)
	{
		//Moves the head to next node.
		head = loc->next;
		delete loc;
		length--;
	}
	else
	{
		//Searches for the value that is in the list until it finds it or until it reaches the end of the list if it doesn't exist.
		while (loc->info != value && loc->next != nullptr)
		{
			prev = loc;
			loc = loc->next;
		}
		if (loc->info == value)
		{
			//If the is not last in line it links the previous node to the node after the value and then deletes it.
			if(loc->next != nullptr)
				prev->next = loc->next;
			delete loc;
			length--;
		}
	}
}
//Pre:
//Post:The next item in the list is return or if it is at the end return the item at the beginninig of the list.
ItemType UnsortedType::GetNextItem()
{
	//Moves the position pointer to the next node.
	if (Pos != nullptr)
		Pos = Pos->next;
	//If the position pointer has not been set or has reached the end of the list it starts at the beginning of the list.
	else
		Pos = head;
	//Returns the info inside the node that the pointer is looking at.
	return Pos->info;
}

//Post:Deletes all the information from the list and sets the length to be 0.
void UnsortedType::MakeEmpty()
{
	Node* loc;
	//While head equals a node that has a value sets head to the next node in line and deletes the beginning node.
	while (head != nullptr)
	{
		loc = head;
		head = head->next;
		delete loc;
	}
	length = 0;
}

bool UnsortedType::IsFull()
{
	if (length == Max)
		return true;
	else
		return false;
}

void UnsortedType::ResetList()
{
	Pos = head;
}

int UnsortedType::GetLength()
{
	return length;
}

Node* UnsortedType::search(ItemType value)
{
	Pos = head;
	while (Pos->info != value && Pos != nullptr)
		Pos = Pos->next;
	return Pos;
}

UnsortedType UnsortedType::Union(UnsortedType List2)
{
	ResetList();
	Node* Combine = Pos;
	UnsortedType Combined;	
	Combined.InsertItem(Pos->info);
	Pos = Pos->next;
	do
	{
		ComparedTo(Pos->info, )
	} while ();

	while (loc->next != nullptr)
		loc = loc->next;
	loc->next = List2.head;
	List1.length += List2.length;

	return Combined;
}

RelationType UnsortedType::ComparedTo(ItemType value1, ItemType value2)
{
	if (value1 < value2)
		return Less;
	else if (value1 == value2)
		return Equal;
	else if (value1 > value2)
		return Greater;
}


