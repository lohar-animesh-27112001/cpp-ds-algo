#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0; i<n; i++) {
        int min = i;
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j]) {
                min = j;
            }
        }
        if(i != min) {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int n = 4;
    int *arr = new int[n]{9,8,7,5};

    // Selection Sort
    selectionSort(arr, n);
    for(int i=0; i<n; i++) {
        cout << *(arr + i) << " ";
    }
    delete[] arr;
    cout << endl;
    cout << "Hello world!" << endl;
    return 0;
}
