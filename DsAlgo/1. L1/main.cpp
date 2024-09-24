#include <bits/stdc++.h>

using namespace std;

int passByValue(int num) {
    num = num + 10;
    cout << num << endl;
    return num;
}

int passByReference(int &num) {
    num = num + 20;
    cout << num << endl;
    return num;
}

int main()
{
    int arr[2][3];
    arr[1][3] = 78;
    cout << arr[1][3] << endl;

    string str = "Animesh Lohar";
    cout << str[2] << "," << str[str.size() - 1] << endl << "Size of the string is: " << str.size() << endl;

    int num = 10;
    cout << "Original number is : " << num << endl;
    // Pass by value : Here is passing the value only
    passByValue(num);
    cout << "Pass by value performed: " << num << endl;

    // Pass by reference : Here is passing the address of the value
    passByReference(num);
    cout << "Pass by reference performed: " << num << endl;

    cout << "Hello world!" << endl;
    return 0;
}
