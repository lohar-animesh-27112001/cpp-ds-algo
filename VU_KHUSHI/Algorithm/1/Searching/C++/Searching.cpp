#include <bits/stdc++.h>

using namespace std;

class SearchingAlgos {
private:
    int n = 100;
    int arr[100];
public:
    SearchingAlgos() {
        for(int i = 0; i < n; i++) {
            arr[i] = i;
        }
    }
    void printArray() {
        cout << "[ ";
        for(int i = 0; i < n; i++) {
            cout << arr[i] << ", ";
        }
        cout << " ]" << endl;
    }
    int binarySearch(int data) {
        cout << "Binary search ongoing..." << " for:" << data << endl;
        int i = 0;
        int j = (sizeof(arr) / sizeof(arr[0])) - 1;
        int ind = -1;
        int loop = 0;
        while(i < j) {
            loop++;
            if(arr[i] == data) {
                ind = i;
                break;
            }
            if(arr[j] == data) {
                ind = j;
                break;
            }
            int mid = (i + j) / 2;
            if(arr[mid] == data) {
                ind = mid;
                break;
            }
            if(data < arr[mid]) {
                j = mid;
            } else {
                i = mid;
            }
        }
        if(ind == -1) {
            cout << "Element does not exist in the array" << endl;
        } else {
            cout << "Number of iteration: " << loop << endl;
            cout << "Element exist in the index: " << ind << endl;
        }
        cout << "...Binary search ended" << " for:" << data << endl;
        return ind;
    }
    int binarySearch(int arr_inp[], int size, int data) {
        cout << "Binary search ongoing..." << " for:" << data << endl;
        int i = 0;
        int j = size - 1;
        int ind = -1;
        int loop = 0;
        while(i < j) {
            loop++;
            if(arr_inp[i] == data) {
                ind = i;
                break;
            }
            if(arr_inp[j] == data) {
                ind = j;
                break;
            }
            int mid = (i + j) / 2;
            if(arr_inp[mid] == data) {
                ind = mid;
                break;
            }
            if(data < arr_inp[mid]) {
                j = mid;
            } else {
                i = mid;
            }
        }
        if(ind == -1) {
            cout << "Element does not exist in the array" << endl;
        } else {
            cout << "Number of iteration: " << loop << endl;
            cout << "Element exist in the index: " << ind << endl;
        }
        cout << "...Binary search ended" << " for:" << data << endl;
        return ind;
    }
    int linearSearch(int element) {
        cout << "Linear search ongoing..." << " for:" << element << endl;
        int size = (sizeof(arr) / sizeof(arr[0]));
        for(int i = 0; i < size; i++) {
            if(arr[i] == element) {
                cout << "Number of iteration: " << i + 1 << endl;
                cout << "Element exist in the index: " << i << endl;
                return i;
            }
        }
        cout << "Element does not exist in the array" << endl;
        cout << "...Linear search ended" << " for:" << element << endl;
        return -1;
    }
    int linearSearch(int arr_inp[], int size, int element) {
        cout << "Linear search ongoing..." << " for:" << element << endl;
        for(int i = 0; i < size; i++) {
            if(arr_inp[i] == element) {
                cout << "Number of iteration: " << i + 1 << endl;
                cout << "Element exist in the index: " << i << endl;
                return i;
            }
        }
        cout << "Element does not exist in the array" << endl;
        cout << "...Linear search ended" << " for:" << element << endl;
        return -1;
    }
};

int main() {
    SearchingAlgos s1;
    s1.printArray();
    s1.binarySearch(59);
    s1.linearSearch(59);
    int arr[] = {1, 2, 3, 7, 8, 10, 19};
    int size = (sizeof(arr) / sizeof(arr[0]));
    s1.binarySearch(arr, size, 3);
    s1.linearSearch(arr, size, 3);
    return 0;
}