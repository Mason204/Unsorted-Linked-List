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
//Post: returns true if list is full and returns false if it is not.
bool UnsortedType::IsFull()
{
	if (length == Max)
		return true;
	else
		return false;
}
//Post: Sets the position pointer back to head.
void UnsortedType::ResetList()
{
	Pos = head;
}
//Post: Returns the list length.
int UnsortedType::GetLength()
{
	return length;
}
//Pre: value must be givenl.
//Post: Returns the Pos pointer that has that value. If the value is not in the list returns nul
Node* UnsortedType::search(ItemType value)
{
	Pos = head;
	while (Pos->info != value && Pos != nullptr)
		Pos = Pos->next;
	return Pos;
}
//Pre: There must be two lists given with items in them.
//Post: Combines two lists into a new one and returns it.
UnsortedType UnsortedType::Union(UnsortedType List2)
{
	bool equal = false;
	ResetList();
	//Creates a new node that will be used to check to see if values are repeated.
	Node* Combine = Pos;
	//New list
	UnsortedType Combined;	
	//Inserted the first item into the new list
	Combined.InsertItem(Pos->info);
	Combine = Pos->next;
	//Runs throught the whole first list checking for duplicates.
	while(Combine != nullptr)
	{
		ResetList();
		do
		{
			if (ComparedTo(Pos->info, Combine->info) != Equal)
			{
				Pos = Pos->next;
			}
			else if (ComparedTo(Pos->info, Combine->info == Equal))
			{
				equal = true;
				if (Pos == Combine)
					equal = false;
				break;
			}			
		} while (Pos->next != nullptr);
		if (equal != true)
		{
			Combined.InsertItem(Combine->info);
			Combine = Combine->next;
		}
		else
		{ 
			Combine = Combine->next;
		}
	}
	List2.ResetList();
	Combined.InsertItem(Pos->info);
	Combine = Combine->next;
	while (Combine != nullptr)
	{
		List2.ResetList();
		do
		{
			if (ComparedTo(Pos->info, Combine->info) != Equal)
			{
				Pos = Pos->next;
			}
			else if (ComparedTo(Pos->info, Combine->info == Equal))
			{
				equal = true;
				if (Pos == Combine)
					equal = false;
				break;
			}
		} while (Pos->next != nullptr);
		if (equal != true)
		{
			Combined.InsertItem(Combine->info);
			Combine = Combine->next;
		}
		else
		{
			Combine = Combine->next;
		}
	}	
	return Combined;
}
//Pre:Two values are given.
//Post:Returns less, equal, or greater.
RelationType UnsortedType::ComparedTo(ItemType value1, ItemType value2)
{
	if (value1 < value2)
		return Less;
	else if (value1 == value2)
		return Equal;
	else if (value1 > value2)
		return Greater;
}


