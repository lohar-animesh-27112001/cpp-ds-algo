#include <bits/stdc++.h>

using namespace std;

void sum(int n, int &s) {
    if(n == 0) {
        s = s + 0;
    } else {
        s = s + n;
        sum(n-1, s);
    }
}

int sum(int n) {
    if(n == 0) {
        return 0;
    } else {
        return n + sum(n-1);
    }
}

void swap_element(int arr[], int i, int r) {
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
}

void swapArr(int arr[], int i, int r) {
    if(i < r) {
        swap_element(arr, i, r);
        swapArr(arr, i+1, r-1);
    }
}

void swapArr(int arr[], int r) {
    swapArr(arr, 0, r-1);
}

bool checkPalindrome(int ind, string s) {
    if(ind > (s.size()/2)) {
        return true;
    } else if(s[ind] != s[s.size()-1-ind]) {
        return false;
    }
    return checkPalindrome(ind+1, s);
}

bool checkPalindrome(string s) {
    return checkPalindrome(0, s);
}

int main()
{
    int s = 0;
    int n;
    cout << "Enter the number for getting sum: ";
    cin >> n;
    sum(n, s);
    cout << s << endl;
    cout << sum(n) << endl;

    int r = 5;
    int *arr = new int[r]{1,2,3,4,5};
    swapArr(arr, r);
    for(int i = 0; i < r; i++) {
        cout << arr[i] << endl;
    }
    delete[] arr;

    string *str = new string();
    cout << "Enter the string to check palindrome: ";
    cin >> *str;
    string str2 = *str;
    for(int i=0; i<str2.size(); i++) {
        str2[i] = toupper(str2[i]);
    }
    *str = str2;
    if(checkPalindrome(*str) == true) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << str2 << " " << *str << endl;
    delete str;

    cout << "Hello world!" << endl;
    return 0;
}
