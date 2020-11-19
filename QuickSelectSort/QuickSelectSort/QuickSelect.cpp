#include <vector>

using namespace std;

template<typename T>
void partition(vector<T>& thisVector, int low, int high, int& pivot)
{
	int j;
	T pivotItem;

	pivotItem = thisVector[low];
	j = low;

	for (int i = low + 1; i <= high; i++)
	{
		if (thisVector[i] < pivotItem)
		{
			j++;
			T tempKey = thisVector[j];
			thisVector[j] = thisVector[i];
			thisVector[i] = tempKey;
		}
	}
	pivot = j;
	T tempKey = thisVector[pivot];
	thisVector[pivot] = thisVector[low];
	thisVector[low] = tempKey;
}

template<typename T>
T quickSelect(vector<T> thisVector, int low, int high, int k)
{
	int pivot;

	if (low == high)
	{
		return thisVector[low];
	}
	else
	{
		partition(thisVector, low, high, pivot);
		if (k == pivot)
		{
			return thisVector[pivot];
		}
		else if (k < pivot)
		{
			return quickSelect(thisVector, low, pivot - 1, k);
		}
		else
		{
			return quickSelect(thisVector, pivot + 1, high, k);
		}
	}
}

template<typename T>
T quickSelectHelper(vector<T> thisVector, int low, int high, int k)
{
	return quickSelect(thisVector, low, high, k - 1);
}