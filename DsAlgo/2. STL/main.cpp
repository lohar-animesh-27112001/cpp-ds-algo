#include <bits/stdc++.h>

using namespace std;

void explainPair() {
    pair<int, int> p1 = {1, 3};
    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};

    cout << p1.first << ", " << p1.second << endl;
    cout << p2.first << ", " << p2.second.first << ", " << p2.second.second << endl;
    cout << arr[2].second << endl;
}

void explainVector() {
    // dynamic array
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.emplace_back(3);
    v1.emplace_back(4);
    v1.insert(v1.begin(), 5);
    v1.insert(v1.begin()+2, 3, 100);
    // emplace_back is generally faster than push_back
    vector<pair<int, int>> v_pair;
    v_pair.push_back({1,2});
    v_pair.emplace_back(3,4);
    // This is the different syntax b/w push_back and emplace_back

    vector<int> v2(5, 100); // {100, 100, 100, 100, 100}
    vector<int> v3(5); // {0, 0, 0, 0, 0}
    vector<int> v4(v3); // v4 = v3

    //for(long long i=0; i < v1.size(); i++) {
    //    cout << v1[i] << " ";
    //}
    for(auto it : v2) {
        cout << it << " ";
    }
    cout << endl;
    v1.erase(v1.begin()+2, v1.begin()+4);
    //for(long long i=0; i < v1.size(); i++) {
    //   cout << v1[i] << " ";
    //}
    for(auto it : v2) {
        cout << it << " ";
    }
    cout << endl;
    v1.clear();
    for(auto it : v2) {
        cout << it << " ";
    }
    cout << endl;
}

void explainList() {
    list<int> ls;
    ls.push_back(1);
    ls.push_back(2);
    ls.emplace_back(3);
    ls.push_front(4);
    ls.emplace_front(5);
    ls.emplace_front();
    for(auto it : ls) {
        cout << it << " ";
    }
    cout << endl;
}

// Set: push values in unique and sorted order, time complexity O(logn)
void explainMultiSet() {
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    for(auto element:ms) {
        cout << element << " ";
    }
    cout << endl << "Number of 1's is: " << ms.count(1) << endl;
    ms.erase(1);
    for(auto element:ms) {
        cout << element << " ";
    }
    cout << endl << "Number of 1's is: " << ms.count(1) << endl;
}

void explainMap() {
    // map<key, value>
    map<int, int> mpp;

    // Map stores unique keys in sorted order
    mpp[1] = 1;
    mpp.insert({3, 1});
    mpp.insert({2, 3});
    for(auto pairs:mpp) {
        cout << pairs.first << ": " << mpp[pairs.first] << endl;
        cout << pairs.first << ": " << pairs.second << endl;
    }
    cout << mpp[3] << endl;
}

int main()
{
    cout << "Explain Pair: " << endl;
    explainPair();
    cout << endl;

    cout << "Explain Vector: " << endl;
    explainVector();
    cout << endl;

    cout << "Explain List: " << endl;
    explainList();
    cout << endl;

    cout << "Explain Multi Set: " << endl;
    explainMultiSet();
    cout << endl;

    cout << "Explain Map: " << endl;
    explainMap();
    cout << endl;

    cout << "Hello world!" << endl;
    return 0;
}
