

//컴퓨터공학과 2021112045 허준상


//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

#include "listarr.h"

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).
{
	// pre-lab
	maxSize = maxNumber;
	size = 0;
	cursor = -1;
	dataItems = new DataType[maxSize]; //중요
}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	// pre-lab
	delete[] dataItems;
}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	// pre-lab
	if(isFull() == true)
		cout << "Full List\n";
	else
	{
		for (int i = cursor + 1; i < size; i++)  //내가 이 부분을 놓침... 커서뒤에 값이 있으면 뒤로 밀어줘야함...
			dataItems[i+1] = dataItems[i];
		dataItems[++cursor] = newDataItem;
		size++;
	}
}

//--------------------------------------------------------------------

void List::remove()

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	// pre-lab
	if (isEmpty() == true || size == 1)
	{
		cout << "Empty List\n";
		size = 0;
		cursor = -1;
	}
	else if(cursor == size-1)
	{
		cursor = 0;
		size -= 1;
	}
	else
	{
		for (int i = cursor; i < size; i++)
			dataItems[i] = dataItems[i+1];
		size -= 1;
	}
}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	// Requires that the list is not empty
	// pre-lab
	if (isEmpty() == true)
		cout << "Empty List\n";
	else
	{
		dataItems[cursor] = newDataItem;
	}
}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	// pre-lab
	size = 0;
	cursor = -1;
	cout << "Empty List" << "\n";
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns true if a list is empty. Otherwise, returns false.
{
	// pre-lab
	if (size == 0) return true;
	else return false;

	//return (size == 0); 이렇게 써도됨 C++는 bool형이 있으니까 알아둘것
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns true if a list is full. Otherwise, returns false.
{
	// pre-lab
	if (maxSize == size) return true;
	else return false;

	//return (maxSize == size); 이렇게 써도됨 C++는 bool형이 있으니까 알아둘것
}

//--------------------------------------------------------------------

void List::gotoBeginning()
// Moves the cursor to the beginning of the list.
{
	// pre-lab
	if (isEmpty() == true)
		cout << "Empty List\n";
	else
		cursor = 0;
}

//--------------------------------------------------------------------

void List::gotoEnd()

// Moves the cursor to the end of the list.

{
	// pre-lab
	if (isEmpty() == true)
		cout << "Empty List\n";
	else
		cursor = size-1;
}

//--------------------------------------------------------------------

bool List::gotoNext()

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	// pre-lab
	if (cursor < size-1) //검토 바람
	{	
		cursor++;
		return true;
	}
	else return false;
}

//--------------------------------------------------------------------

bool List::gotoPrior()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	// pre-lab
	if (cursor > 0) //검토 바람
	{
		cursor--;
		return true;
	}
	else return false;
}

//--------------------------------------------------------------------

DataType List::getCursor() const
// Returns the item marked by the cursor.

{
	// pre-lab
	if (isEmpty() == true)
	{
		cout << "Empty List\n";
		return NULL;
	}
	else
		return dataItems[cursor];
}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
    // pre-lab
	cout << "size = " << size << "\t" << "cursor = " << cursor << endl;
	for (int i = 0; i < maxSize; i++)
	{
		cout << "[ " << i << " ]\t";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "  " << dataItems[i] << "  \t";
	}
	cout << endl;
}

//--------------------------------------------------------------------

//in-lab
void List::moveToNth(int n)
{
	// in-lab 2
	if (size < n + 1)
		cout << "The list should be n+1 minimum" << "\n";
	else
	{
		char temp = getCursor();

		//다른값이 들어오면 조건을 넣어야 하나  질문
		if (n < cursor) //뒤로 한칸씩 밀기
		{
			for (int i = cursor; i > n; i--)
				dataItems[i] = dataItems[i - 1];
			dataItems[n] = temp;
			cursor = n;
		}
		else //앞으로 한칸씩 밀기
		{
			for (int j = cursor; j < n; j++)
				dataItems[j] = dataItems[j + 1];
			dataItems[n] = temp;
			cursor = n;
		}
	}
}

bool List::find(const DataType& searchDataItem)
{
	// in-lab 3
	if (isEmpty() == true)
	{
		cout << "Empty List" << "\n";
		return NULL;
	}
	else
	{
		for(int i=cursor;i<size;i++)
		{
			if (dataItems[i] == searchDataItem)
			{
				cursor = i;
				return true;
			}
		}
		cursor = size-1;
		return false;
	}
}