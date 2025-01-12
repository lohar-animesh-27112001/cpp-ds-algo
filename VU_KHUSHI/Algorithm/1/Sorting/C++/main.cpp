#include <iostream>
#include <vector>
#include <cmath>  // For abs()
#include "SortingAlgos.h"

using namespace std;

int main() {
    // Selection Sort
    cout << "Selection Sort: " << endl;
    SortingArr arr1;
    arr1.selectionSort();

    // Bubble Sort
    cout << "Bubble Sort: " << endl;
    SortingArr arr2;
    arr2.bubbleSort();

    // Insertion Sort
    cout << "Insertion Sort: " << endl;
    SortingArr arr3;
    arr3.insertionSort();

    // Merge Sort
    cout << "Merge Sort: " << endl;
    SortingArr arr4;
    arr4.mergeSort();
    
    // Quick Sort
    cout << "Quick Sort: " << endl;
    SortingArr arr5;
    arr5.quickSort();
    
    // Counting Sort
    cout << "Counting Sort: " << endl;
    SortingArr arr6;
    arr6.countingSort();

    return 0;
}
