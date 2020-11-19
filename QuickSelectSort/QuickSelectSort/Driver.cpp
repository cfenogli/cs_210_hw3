#include "QuickSelect.cpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void printVector(vector<T> vectorToPrint);

int main()
{
	cout << "Provided test cases:" << endl << "-------------------------" << endl;

	vector<int> vector1{ 2, 3, 5, 8, 12, 1, 7, 10, 13, 30, 6, 14, 15, 18, 22 };

	cout << "Test case 1:" << endl;
	printVector(vector1);

	cout << "k = 4:" << endl;
	cout << quickSelectHelper(vector1, 0, vector1.size() - 1, 4) << endl;

	cout << "k = 8:" << endl;
	cout << quickSelectHelper(vector1, 0, vector1.size() - 1, 8) << endl;

	cout << "k = 12:" << endl;
	cout << quickSelectHelper(vector1, 0, vector1.size() - 1, 12) << endl;


	cout << "\n\nOur test cases:" << endl << "-------------------------" << endl;

	vector<int> vector2{ 15, 14, 13, 20, 19, 18, 12, 11, 10, 6, 5, 4 };
	vector<int> vector3{ 20, 30, 100, 120, 110, 1, 2, 14, 15, 35, 45 };

	cout << "Test case 2:" << endl;
	printVector(vector2);

	cout << "k = 10:" << endl;
	cout << quickSelectHelper(vector2, 0, vector2.size() - 1, 10) << endl;

	cout << "k = 5:" << endl;
	cout << quickSelectHelper(vector2, 0, vector2.size() - 1, 5) << endl;

	cout << "k = 1:" << endl;
	cout << quickSelectHelper(vector2, 0, vector2.size() - 1, 1) << endl;

	cout << "\nTest case 3:" << endl;
	printVector(vector3);

	cout << "k = 1:" << endl;
	cout << quickSelectHelper(vector3, 0, vector3.size() - 1, 1) << endl;

	cout << "k = 2:" << endl;
	cout << quickSelectHelper(vector3, 0, vector3.size() - 1, 2) << endl;

	cout << "k = 3:" << endl;
	cout << quickSelectHelper(vector3, 0, vector3.size() - 1, 3) << endl;

}

//print contents of vector vectorToPrint
template<typename T>
void printVector(vector<T> vectorToPrint)
{
	for (int i = 0; i < vectorToPrint.size(); i++)
	{
		cout << vectorToPrint[i] << "\t";
	}
	cout << endl;
}