//
// Created by Froys on 09/08/2024.
//

#ifndef MINHEAP_H
#define MINHEAP_H
#include <string>
#include <vector>

using namespace std;

// 0-indexed minHeap
class minHeap {
public:
    minHeap() = default;
    explicit minHeap(vector<string>& strs);
    void insert(string str);
    string peek();
    string removeMin();
    bool empty();
    static int leftChild(int currIndex);
    static int rightChild(int currIndex);
    static int parent(int currIndex);
    bool hasChild(int currIndex);
    int maxPriorityChild(int currIndex);
    void heapifyDown(int currIndex);
    void heapifyUp(int currIndex);
    int size();
    string getElem(int currIndex);
private:
    vector<string> heap;
};



#endif //MINHEAP_H
