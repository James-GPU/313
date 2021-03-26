#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <utility>
#include <chrono>
#include "LinkedList.h"
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
#include <vector>
#include <list>
using namespace std;
//James Ng CSCI 313 Question 2
template <typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();
}
int Partition(int arr[], int startIndex, int endIndex) {
	// Set the first item as pivot
	int pivot = arr[startIndex];
	// Left sublist and right sublist
	// are initially empty
	int middleIndex = startIndex;
	// Iterate through arr[1 ... n - 1]
	for (int i = startIndex + 1; i <= endIndex; ++i) {
		if (arr[i] < pivot) {
			// the current item is on the left sublist
			// prepare a seat by shifting middle index
			++middleIndex;
			// the arr[middleIndex] is
			// the member of right sublist,
			// swap it to the current item which is
			// member of left list
			swap(arr[i], arr[middleIndex]);
		}
	}
	// By now, the arr[middleIndex] item is
	// member of left sublist.
	// We can swap it with the pivot
	// so the pivot will be in the correct position
	// which is between left sublist and right sublist
	swap(arr[startIndex], arr[middleIndex]);
	// return the index of pivot
	// to be used by next quick sort
	return middleIndex;
}

void QuickSort(int arr[], int startIndex, int endIndex)
{
	// Only perform sort process
	// if the end index is higher than start index
	if (startIndex < endIndex)
	{
		// Retrieve pivot position from Partition() function
		// This pivotIndex is the index of element that is already
		// in correct position
		int pivotIndex = Partition(arr, startIndex, endIndex);

		// Sort left sublist
		// arr[startIndex ... pivotIndex - 1]
		QuickSort(arr, startIndex, pivotIndex - 1);

		// Sort right sublist
		// arr[pivotIndex + 1 ... endIndex]
		QuickSort(arr, pivotIndex + 1, endIndex);
	}
}


template <typename T>
constexpr bool is_lvalue(T& obj) {
	return true;
}

template <typename T>
constexpr bool is_lvalue(T&& obj) {
	return false;
}
//itterative Binary Search
bool IterativeBinarySearch(int* arr, int left, int right, int target) {

	while (right != left) {
		int mid = (right + left) / 2;

		if (arr[mid] == target) {

			return true;
		}
		else if (target > arr[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return false;
}

//Recursive Binary Search
bool RecursiveBinarySearch(int* arr, int left, int right, int target)
{
	static int counter = 0;
	counter++;
	cout << "Left: " << arr[left] << "\tRight: " << arr[right] << "\tFunction call #: " << counter << endl;

	int mid = (right + left) / 2;

	//check mid for positive stop
	if (arr[mid] == target)
		return true;
	//check mid for negative stop
	if (mid == right || mid == left) {
		return false;
	}

	if (target < arr[mid])
		return RecursiveBinarySearch(arr, left, mid, target);
	else if (target > arr[mid])
		return RecursiveBinarySearch(arr, mid, right, target);
}
void IterativeOneMilSearch() {
	srand(time(nullptr));
	int mil = 1000000;
	int* arr1 = new int[1000000];//This first array is for 1 million numbers. whenever I put 1 million it would come out as nothing, sort cannot handle 1 million numbers
	for (int i = 0; i < mil; i++) {
		arr1[i] = (rand() % 1000000) + 1;//Assigns each element in the array a random number between 0 and 1000000
	}
	QuickSort(arr1, 0, mil - 1);//Sorts the array, I subtract one so that it wouldn't give a random negative integer

	cout << endl;
	int number = 0;
	cout << "What is the number you are looking for? " << endl; //Asks user what number 
	cin >> number; //Takes in the value
	auto start = chrono::high_resolution_clock::now();//Starts a timer
	if (IterativeBinarySearch(arr1, 0, mil, number) == true) {//First is array, second is the starting point, third is the endpoint and 4th is the number we are looking for.
		cout << "There is a number that you have searched for" << endl;//Number must be replaced with the value 
	}
	else {
		cout << "There is no number that you have searched for" << endl;//If there is no number in the array, we print that there is no number
	}
	auto end = chrono::high_resolution_clock::now();//Ends the timer so we know the duration
	chrono::duration<float, milli> duration = end - start;//We subtract the end with the beginning points to see how long it lasts.

	cout << "The time it took to search by Iterative Binary Search through 1 million integers was " << duration.count() << " milliseconds." << endl;//Prints in milliseconds

	delete[]arr1;//Deletes the array
}
void IterativeTenMilSearch() {
	srand(time(nullptr));
	int tenmil = 10000000;
	int* arr2 = new int[10000000];//This second array is for 10 million numbers 
	for (int i = 0; i < tenmil; i++) {
		arr2[i] = (rand() % 10000000) + 1;//Assigns each element in the array a random number between 0 and 10000000
	}
	QuickSort(arr2, 0, tenmil - 1);

	int number = 0;

	cout << "What is the number you are looking for? " << endl; //Asks user what number 
	cin >> number; //Takes in the value
	auto start = chrono::high_resolution_clock::now();//Starts a timer

	if (IterativeBinarySearch(arr2, 0, tenmil, number) == true) {//First is array, second is the starting point, third is the endpoint and 4th is the number we are looking for.
		cout << "There is a number that you have searched for" << endl;//Number must be replaced with the value 
	}
	else {
		cout << "There is no number that you have searched for" << endl;//If there is no number in the array, we print that there is no number
	}
	auto end = chrono::high_resolution_clock::now();//Ends the timer so we know the duration
	chrono::duration<float, milli> duration = end - start;//We subtract the end with the beginning points to see how long it lasts.

	cout << "The time it took to search by Iterative Binary Search through 10 million integers was " << duration.count() << " milliseconds." << endl;//Prints in milliseconds


	delete[]arr2;
}
void RecursiveOneMilSearch() {//Recursive for 1 million integers
	srand(time(nullptr));
	int* arr3 = new int[1000000];//This second array is for 1 million numbers 
	int mil = 1000000;
	for (int i = 0; i < mil; i++) {
		arr3[i] = (rand() % 1000000) + 1;//Assigns each element in the array a random number between 0 and 1000000
	}
	QuickSort(arr3, 0, mil - 1);
	int number = 0;
	cout << "What is the number you are looking for? " << endl; //Asks user what number 
	cin >> number; //Takes in the value
	auto start = chrono::high_resolution_clock::now();//Starts a timer
	if (RecursiveBinarySearch(arr3, 0, mil, number) == true) {
		cout << "There is a number that you have searched for" << endl;//Number must be replaced with the value 

	}
	else {
		cout << "There is no number that you are looking for " << endl;//If there is no number in the array, we print that there is no number
	}
	auto end = chrono::high_resolution_clock::now();//Ends the timer so we know the duration
	chrono::duration<float, milli> duration = end - start;//We subtract the end with the beginning points to see how long it lasts.
	cout << "The time it took search by Recursive Binary Search through 1 million integers was " << duration.count() << " milliseconds." << endl;//Prints in milliseconds
	delete[]arr3;
}
void RecursiveTenMilSearch() {//Recursive for 1 million integers
	srand(time(nullptr));
	int* arr4 = new int[10000000];//This second array is for 1 million numbers 
	int tenmil = 10000000;
	for (int i = 0; i < tenmil; i++) {
		arr4[i] = (rand() % 1000000) + 1;//Assigns each element in the array a random number between 0 and 1000000
	}
	QuickSort(arr4, 0, tenmil - 1);
	int number = 0;
	cout << "What is the number you are looking for? " << endl; //Asks user what number 
	cin >> number; //Takes in the value
	auto start = chrono::high_resolution_clock::now();//Starts a timer
	if (RecursiveBinarySearch(arr4, 0, tenmil, number) == true) {
		cout << "There is a number that you have searched for" << endl;//Number must be replaced with the value 

	}
	else {
		cout << "There is no number that you are looking for " << endl;//If there is no number in the array, we print that there is no number
	}
	auto end = chrono::high_resolution_clock::now();//Ends the timer so we know the duration
	chrono::duration<float, milli> duration = end - start;//We subtract the end with the beginning points to see how long it lasts.
	cout << "The time it took search by Recursive Binary Search through 10 million integers was " << duration.count() << " milliseconds." << endl;//Prints in milliseconds
	delete[]arr4;
}
void LinkedOneMilSearch() {
	buildListForwardOneMillion();
	int number = 0;
	cout << "What is the number you are looking for? " << endl; //Asks user what number 
	cin >> number; //Takes in the value
	auto start = chrono::high_resolution_clock::now();//Starts a timer
	if (LLsearch(number) == true) {//Insert LL
		cout << "There is a number that you have searched for" << endl;//number must be replaced with the value 
	}
	else {
		cout << "There is no number that you are looking for " << endl;//If there is no number in the array, we print that there is no number
	}
	auto end = chrono::high_resolution_clock::now();//Ends the timer so we know the duration
	chrono::duration<float, milli> duration = end - start;//We subtract the end with the beginning points to see how long it lasts.

	cout << "The time it took search by Linked Binary Search through 1 million integers was " << duration.count() << " milliseconds." << endl;//Prints in milliseconds

}
void LinkedTenMilSearch() {
	buildListForwardTenMillion();
	int number = 0;

	cout << "What is the number you are looking for? " << endl; //Asks user what number 
	cin >> number; //Takes in the value
	auto start = chrono::high_resolution_clock::now();//Starts a timer, credit to The Cherno's Youtube Video "Timing in C++"

	if (LLsearch(number)== true) {//Insert LL
	cout << "There is a number that you have searched for" << endl;//Number must be replaced with the value 
	}
	else {
		cout << "There is no number that you are looking for " << endl;
	}
	auto end = chrono::high_resolution_clock::now();//Ends the timer so we know the duration
	chrono::duration<float, milli> duration = end - start;//We subtract the end with the beginning points to see how long it lasts.
	cout << "The time it took search by Linked Binary Search through 10 million integers was " << duration.count() << " milliseconds." << endl;//Prints in milliseconds
}

int main() {
	IterativeOneMilSearch();
	IterativeTenMilSearch();
	RecursiveOneMilSearch();
	RecursiveTenMilSearch();
	LinkedOneMilSearch();
	LinkedTenMilSearch();
	return 0;
}








