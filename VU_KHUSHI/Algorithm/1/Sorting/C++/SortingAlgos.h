#ifndef HEADER_H
#define HEADER_H

#include <bits/stdc++.h>

using namespace std;

class SortingArr {
private:
    int n;
    vector<int> arr;
public:
    SortingArr() {
        cout << "Number of elements do you want in the array: ";
        cin >> n;
        arr.resize(n);  // Allocate space for n elements
        cout << "Enter the elements: ";
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void selectionSort() {
        for(int i = 0; i < n; i++) {
            int minElement = i;
            for(int j = i + 1; j < n; j++) {
                if(arr[minElement] > arr[j]) {
                    minElement = j;
                }
            }
            if(i != minElement) {
                swap(arr[i], arr[minElement]);
            }
        }
        printArray();
    }

    void bubbleSort() {
        for(int i = 0; i < n - 1; i++) {
            bool sorted = true;
            for(int j = 0; j < n - 1 - i; j++) { // Optimized bubble sort
                if(arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    sorted = false;
                }
            }
            if(sorted) {
                break;
            }
        }
        printArray();
    }

    void insertionSort() {
        for(int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        printArray();
    }

    void mergeSort() {
        divide(0, n - 1);
        printArray();
    }
    
    void quickSort() {
    	quickSort(0, n-1);
    	printArray();
    }
    
    void countingSort() {
        int max_num = 0;
        for(int i : arr) {
            if(max_num < i) {
                max_num = i;
            }
        }
        vector<int> countArray(max_num + 1, 0);
        for(int i : arr) {
            countArray[i]++;
        }
        for(int i = 1; i <= max_num; i++) {
            countArray[i] += countArray[i - 1];
        }
        vector<int> outputArray(n);
        for(int i = n - 1; i >= 0; i--) {
            outputArray[countArray[arr[i]] - 1] = arr[i];
            countArray[arr[i]]--;
        }
        arr = outputArray;
        printArray();
    }

    
private:

    void divide(int left, int right) {
        if(left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        divide(left, mid);
        divide(mid + 1, right);
        mergeArray(left, mid, right);
    }

    void mergeArray(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for(int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }
        for(int i = 0; i < n2; i++) {
            R[i] = arr[mid + 1 + i];
        }

        int i = 0, j = 0, k = left;
        while(i < n1 && j < n2) {
            if(L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while(i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while(j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
    void quickSort(int start, int end) {
    	if(start >= end) return;
    	int pivot = partition(start, end);
    	quickSort(start, pivot - 1);
    	quickSort(pivot + 1, end);
    }
    
    int partition(int start, int end) {
    	int pivot = end;
	end--;
    	while(start <= end) {
    		while(arr[start] < arr[pivot] && start <= end) {
    			start++;
    		}
    		while(arr[end] > arr[pivot] && start <= end) {
    			end--;
    		}
    		if(start < end) {
    			swapValue(start, end);
    			start++;
    			end--;
    		}
    	}
    	swapValue(start, pivot);
    	return start;
    }
    
    void swapValue(int i, int j) {
    	int temp = arr[i];
    	arr[i] = arr[j];
    	arr[j] = temp;
    }

    void printArray() {
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

#endif // HEADER2_H
#pragma once