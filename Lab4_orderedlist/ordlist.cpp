#include "ordlist.h"

OrdList::OrdList(int maxNumber)
{
	maxSize = maxNumber;
}

void OrdList::insert(const DataType& newDataItem)
{
	for (int i = 0; i < size; i++)
	{
		if (newDataItem.getKey() < dataItems[i].getKey())
		{
			cursor = i - 1;
			break;
		}
	}
	List::insert(newDataItem);
}

void OrdList::replace(const DataType& newDataItem)
{
	int temp;
	int p = cursor;
	List::replace(newDataItem);
	if (newDataItem.getKey() > dataItems[p + 1].getKey())
	{
		for (int i = p; i < size-1; i++)
		{
			if (dataItems[i].getKey() < dataItems[i+1].getKey())
				break;
			else
			{
				temp = dataItems[i].key;
				dataItems[i].key = dataItems[i+1].key;
				dataItems[i + 1].key = temp;
			}
		}
	}
	else
	{
		for (int j = p; j > 0; j--)
		{
			if (dataItems[j].getKey() > dataItems[j - 1].getKey())
				break;
			else
			{
				temp = dataItems[j].key;
				dataItems[j].key = dataItems[j - 1].key;
				dataItems[j - 1].key = temp;
			}
		}
	}

}

bool OrdList::retrieve(char searchKey, DataType& searchDataItem)
{
	//searchKey는 찾고싶은 값 seacrchDataItem은 그 데이터타입에 들어있는값
	for (int i = 0; i < size; i++)
	{
		if (binarySearch(searchKey, i) == true)
		{
			cursor = i;
			searchDataItem.key = dataItems[i].getKey();
			cout << "true, " << "cursor = "<< cursor << "\n";
			return true;
		}
	}
	cout << "false, " << "cursor = " << cursor << "\n";
	return false;
}

bool OrdList::binarySearch(char searchKey, int& index)
{
	//바이너리서치를 해서 key값이 인덱스에 있으면 true 없으면 false ?

	int mid;
	int first = 0;
	int last = size-1;
	bool found = false;

	while (first <= last)
	{
		mid = (first + last) / 2;
		if (dataItems[mid].getKey() > searchKey)
			last = mid - 1;
		else if (dataItems[mid].getKey() < searchKey)
			first = mid + 1;
		else
		{
			found = true;
			break;
		}
	}

	if (found == true && index == mid)
		return true;
	else
		return false;
}

//--------------------------------------------------------------------

//in-lab
//void OrdList::merge(const OrdList& fromL)
//{
//	// in-lab 2
//	cursor = size - 1;
//	for (int i = 0; i < fromL.size; i++)
//	{
//		OrdList::insert(fromL.dataItems[i]);
//		cursor = size - 1;
//	}
//}

bool OrdList::isSubset(const OrdList& subL)
{
	// in-lab 3
	int count = 0;
	if (subL.size == 0)
		return true;
	else
	{
		for (int i = 0; i < subL.size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (subL.dataItems[i].getKey() == dataItems[j].getKey())
				{
					count++;
					break;
				}
			}
		}
		if (count == subL.size)
			return true;
		else
			return false;
	}
	//다른 값이 하나라도 있으면 false 아니면 true
}