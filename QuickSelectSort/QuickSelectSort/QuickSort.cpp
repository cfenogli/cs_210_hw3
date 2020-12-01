#include "QuickSelect.cpp"

#include <vector>
#include <iostream>

using namespace std;

//debug function used to print vector during sorting
template<typename T>
void printVectorMidway(vector<T> vectorToPrint)
{
	for (int i = 0; i < vectorToPrint.size(); i++)
	{
		cout << vectorToPrint[i] << "\t";
	}
	cout << endl;
}

//unused in final version
/*
//select new partition for quickSort
template<typename T>
int partitionMedian(vector<T>& thisVector, int low, int high)
{
	int medianIndex = quickSelect(thisVector, low, high, (high+low)/2);
	T pivotItem = thisVector[medianIndex];

	T tempKey = thisVector[medianIndex];
	thisVector[medianIndex] = thisVector[low];
	thisVector[low] = tempKey;

	int left = low;
	int right = high;

	while (left < right)
	{
		while (thisVector[left] < pivotItem && left < right)
		{
			left++;
		}
		while (thisVector[right] > pivotItem)
		{
			right--;
		}
		if (left < right)
		{
			tempKey = thisVector[left];
			thisVector[left] = thisVector[right];
			thisVector[right] = tempKey;
		}
	}

	tempKey = thisVector[low];
	thisVector[low] = thisVector[right];
	thisVector[right] = tempKey;

	return right;
}
*/

//sort thisVector in ascending order from index low to index high
template<typename T>
void quickSort(vector<T>& thisVector, int low, int high)
{
	int pivot = 0;

	if (high > low)
	{
		partition(thisVector, low, high, pivot);

		
		//debugging
		//cout << "\npivot: " << pivot << " - high index: " << high << " - low index: " << low << " - vector to be sorted:\n";
		//printVectorMidway(thisVector);
		

		quickSort(thisVector, low, pivot - 1);
		quickSort(thisVector, pivot + 1, high);
	}
}