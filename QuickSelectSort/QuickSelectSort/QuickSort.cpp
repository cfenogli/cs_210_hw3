#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void printVectorMidway(vector<T> vectorToPrint)
{
	for (int i = 0; i < vectorToPrint.size(); i++)
	{
		cout << vectorToPrint[i] << "\t";
	}
	cout << endl;
}

//select new partition for quickSort
template<typename T>
int partitionMedian(vector<T>& thisVector, int low, int high)
{
	int medianIndex = (high + low) / 2;
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

template<typename T>
void quickSort(vector<T>& thisVector, int low, int high)
{
	int pivot;

	if (high > low)
	{
		printVectorMidway(thisVector);
		pivot = partitionMedian(thisVector, low, high);

		quickSort(thisVector, low, pivot - 1);
		quickSort(thisVector, pivot + 1, high);
	}
}