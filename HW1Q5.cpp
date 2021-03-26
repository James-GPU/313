#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <utility>
#include <chrono>
#include <vector>
#include <list>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using namespace std;
//James Ng CSCI 313 Question 5
template <typename Func>
long long TimeFunc(Func f)
{
    auto begin = steady_clock::now();
    f();
    auto end = steady_clock::now();

    return duration_cast<milliseconds>(end - begin).count();
}
int Partition(int arr[],int startIndex,int endIndex){
    // Set the first item as pivot
    int pivot = arr[startIndex];

    // Left sublist and right sublist
    // are initially empty
    int middleIndex = startIndex;

    // Iterate through arr[1 ... n - 1]
    for (int i = startIndex + 1; i <= endIndex; ++i)
    {
        if (arr[i] < pivot)
        {
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

void QuickSort(int arr[],int startIndex,int endIndex){
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
void SortY(int* arr, int size) {
    cout << endl;
    auto start = chrono::high_resolution_clock::now();//Starts a timer
    cout << "Sorted Y:" << endl;
    QuickSort(arr,0,size);//This sorts everything
    for (int i = size; i >size-10; i--) {// This is the rest of the array
        cout << arr[i] << " ";
    }
    cout << endl;
    auto end = chrono::high_resolution_clock::now();//Ends the timer so we know the duration
    chrono::duration<float, milli> duration = end - start;// We subtract the end with the beginning points to see how long it lasts.

    cout << "The time it took to sort Y was " << duration.count() << " milliseconds." << endl;//Prints in milliseconds

}
void SortX(int* arr, int size){
    cout << "Sorted X: " << endl;
    auto start = chrono::high_resolution_clock::now();//Starts a timer
    QuickSort(arr,0,size-1);//This sorts everything 
    for (int i = 0; i < size; i++) {//Prints the Sorted X list
        cout << arr[i] << " ";
        if (size - i ==11) {// check this out for switching over to Y, size - i < 7 apparently works perfectly and i >10 works somewhat right, so if it is equal to 11, it'll display the last 10, which we are looking for.
            SortY(arr, size-1);//So this only sorts the first 10 number, we want to sort last 10 number*****************
            break;//Prevents the function from going back here and repeating SortY
        }
    }
    
    auto end = chrono::high_resolution_clock::now();//Ends the timer so we know the duration
    chrono::duration<float, milli> duration = end - start;//We subtract the end with the beginning points to see how long it lasts.

    cout << "The time it took to sort X was " << duration.count() << " milliseconds." << endl;//Prints in milliseconds

}

int main() {
    srand(time(nullptr));
    const int size = 15;//Declares size
    const int size2 = 22;//Declares size2
    int* arr = new int[size];
    
    cout << "Unsorted Array: " << endl;
    for (int i = 0; i < size; i++){//Makes random numbers for the whole array
        arr[i] = (rand()% 100) + 1;
        cout << arr[i] << " ";
    }
    cout << endl;
    int* arr2 = new int[size2];
    
    QuickSort(arr, 0, size-1);
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < size; i++) {//Makes random numbers for the whole array
        cout << arr[i] << " ";
    }
    cout << endl;
    if (size> 10) {
        SortX(arr, size);//Test these two arrays with sorts
    }
    else {
        SortY(arr, size);
    }
    cout << "Unsorted Array: " << endl;
    for (int i = 0; i < size2; i++) {//Makes random numbers for the whole array
        arr2[i] = (rand() % 100) + 1;
        cout << arr2[i] << " ";
    }
        cout << endl;

    QuickSort(arr2, 0, size2 - 1);
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < size2; i++) {//Makes random numbers for the whole array
        cout << arr2[i] << " ";
    }
    cout << endl;
    if (size2 > 10) {
        SortX(arr2, size2);//Test these two arrays with sorts
    }
    else {
        SortY(arr2, size2);
    }
}
