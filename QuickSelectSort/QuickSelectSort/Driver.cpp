#include "QuickSelect.cpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void printVector(vector<T> vectorToPrint);

int main()
{
	cout << "Provided test cases:" << endl << endl;

	vector<int> vector1{ 2, 3, 5, 8, 12, 1, 7, 10, 13, 30, 6, 14, 15, 18, 22 };

	cout << "Test case 1:" << endl;
	printVector(vector1);

	cout << "k = 4:" << endl;
	cout << quickSelectHelper(vector1, 0, vector1.size() - 1, 4) << endl;

	cout << "k = 8:" << endl;
	cout << quickSelectHelper(vector1, 0, vector1.size() - 1, 8) << endl;

	cout << "k = 12:" << endl;
	cout << quickSelectHelper(vector1, 0, vector1.size() - 1, 12) << endl;


	cout << "Our test cases:" << endl << endl;
	
}

template<typename T>
void printVector(vector<T> vectorToPrint)
{
	for (int i = 0; i < vectorToPrint.size(); i++)
	{
		cout << vectorToPrint[i] << "\t";
	}
	cout << endl;
}