//
// Created by Froys on 09/08/2024.
//

#include <algorithm>

#include "minHeap.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    vector<string> s = {"51", "31", "13", "41", "16", "101"};
    minHeap m(s);

    cout << "Original heap: ";
    for (int i = 0; i < m.size(); i++) {
        cout << m.getElem(i) << " ";
    }
    cout << endl;

    m.removeMin();

    cout << "Heap after removing 101: ";
    for (int i = 0; i < m.size(); i++) {
        cout << m.getElem(i) << " ";
    }
    cout << endl;

    m.removeMin();
    m.removeMin();

    cout << "Heap after removing 13, 16: ";
    for (int i = 0; i < m.size(); i++) {
        cout << m.getElem(i) << " ";
    }
    cout << endl;

    m.insert("90");
    m.insert("1");

    cout << "Heap after adding 90, 1: ";
    for (int i = 0; i < m.size(); i++) {
        cout << m.getElem(i) << " ";
    }
    cout << endl;

    s.push_back("90");
    s.push_back("1");
    sort(s.begin(), s.end(), less<string>());
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;


    s = {"aa", "cc", "bb", "ab", "ac", "abc"};
    minHeap j(s);
    m = j;

    cout << "Original heap: ";
    for (int i = 0; i < m.size(); i++) {
        cout << m.getElem(i) << " ";
    }
    cout << endl;

    m.removeMin();

    cout << "Heap after removing aa: ";
    for (int i = 0; i < m.size(); i++) {
        cout << m.getElem(i) << " ";
    }
    cout << endl;

    m.removeMin();
    m.removeMin();

    cout << "Heap after removing ab, abc: ";
    for (int i = 0; i < m.size(); i++) {
        cout << m.getElem(i) << " ";
    }
    cout << endl;

    m.insert("dc");
    m.insert("add");

    cout << "Heap after adding dc, add: ";
    for (int i = 0; i < m.size(); i++) {
        cout << m.getElem(i) << " ";
    }
    cout << endl;

    s.push_back("dc");
    s.push_back("add");
    sort(s.begin(), s.end(), less<string>());
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    return 0;
}