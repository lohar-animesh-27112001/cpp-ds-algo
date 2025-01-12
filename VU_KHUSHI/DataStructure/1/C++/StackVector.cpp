#include <bits/stdc++.h>

using namespace std;

class StackVector {
private:
    vector<int> v;
public:
    StackVector() {
        v = {};
    }
    void push(int value) {
        v.push_back(value);
        cout << value << " pushed successfully" << endl;
        return;
    }
    void pop() {
        if(v.size() == 0) {
            cout << "No element to pop, Underflow" << endl;
            return;
        }
        cout << v[v.size() - 1] << " value popped succesfully" << endl;
        v.pop_back();
    }
    int peek() {
        if(v.size() == 0) {
            cout << "No element in the stack" << endl;
            return INT_MIN;
        }
        cout << "Last element of the stack is: " << v[v.size() - 1] << endl;
        return v[v.size() - 1];
    }
    int stackSize() {
        cout << "The size of the stack is: " << v.size() << endl;
        return v.size();
    }
    bool isEmpty() {
        if(v.size() == 0) {
            cout << "The stack is empty" << endl;
            return true;
        } else {
            cout << "The stack is not empty" << endl;
            return false;
        }
    }
    void printStack() {
        cout << "[ ";
        for(int i : v) {
            cout << i << ", ";
        }
        cout << "]" << endl;
        return;
    }
};
int main() {
    StackVector sv;
    sv.isEmpty();
    sv.push(12);
    sv.push(10);
    sv.push(11);
    sv.isEmpty();
    sv.printStack();
    sv.peek();
    sv.pop();
    sv.peek();
    sv.printStack();
    return 0;
}