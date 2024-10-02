#include <iostream>
#include <vector>
#include <cmath>  // For abs()

using namespace std;

class SortingArr {
private:
    int n;
    vector<int> arr;
public:
    SortingArr() {
        cout << "Number of elements do you want in the array: ";
        cin >> n;
        arr.resize(n);
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
    }

    void bubbleSort() {
        for(int i = 0; i < n - 1; i++) {
            bool sorted = true;
            for(int j = 0; j < n - 1 - i; j++) {
                if(arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    sorted = false;
                }
            }
            if(sorted) {
                break;
            }
        }
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
    }

    void mergeSort() {
        divide(0, n - 1);
        printArray();
    }

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

    void printArray() {
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Selection Sort
    cout << "Selection Sort: " << endl;
    SortingArr arr1;
    arr1.selectionSort();
    arr1.printArray();

    // Bubble Sort
    cout << "Bubble Sort: " << endl;
    SortingArr arr2;
    arr2.bubbleSort();
    arr2.printArray();

    // Insertion Sort
    cout << "Insertion Sort: " << endl;
    SortingArr arr3;
    arr3.insertionSort();
    arr3.printArray();

    // Merge Sort
    cout << "Merge Sort: " << endl;
    SortingArr arr4;
    arr4.mergeSort();

    return 0;
}
