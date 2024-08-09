//
// Created by Froys on 09/08/2024.
//

#include "minHeap.h"
#include <iostream>

int minHeap::leftChild(int currIndex) {
    return 2*currIndex+1;
}

int minHeap::rightChild(int currIndex) {
    return 2*currIndex+2;
}

int minHeap::parent(int currIndex) {
    return (currIndex - 1) / 2;
}

bool minHeap::hasChild(int currIndex) {
    return (heap.size() - 1) >= (2*currIndex+1);
}

// must only be called if hasChild(currIndex) == true
int minHeap::maxPriorityChild(int currIndex) {
    int indexL = leftChild(currIndex);
    int indexR = rightChild(currIndex);
    if ((heap.size()-1) <= (2*currIndex+1)) return indexL;
    if (heap[indexL] < heap[indexR]) {
        return indexL;
    } else {
        return indexR;
    }
}

void minHeap::heapifyDown(int currIndex) {
    if (!hasChild(currIndex)) {
        return;
    }
    int priority = maxPriorityChild(currIndex);
    if (heap[priority] < heap[currIndex]) {
        swap(heap[currIndex], heap[priority]);
        heapifyDown(priority);
    }
}

void minHeap::heapifyUp(int currIndex) {
    if (currIndex == 0) {
        return;
    }
    int parentIdx = parent(currIndex);
    if (heap[currIndex] < heap[parent(currIndex)]) {
        swap(heap[currIndex], heap[parent(currIndex)]);
        heapifyUp(parentIdx);
    }
}

minHeap::minHeap(vector<string>& strs) {
    heap = strs;
    if (strs.empty()) return;
    int origSize = strs.size();
    for (int i = origSize / 2; i >= 0; i--) {
        heapifyDown(i);
    }
}

string minHeap::removeMin() {
    string ret = peek();
    swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    if (heap.empty()) return ret;
    minHeap f(heap);
    *this = f;
    return ret;
}

string minHeap::peek() {
    return heap[0];
}

void minHeap::insert(string str) {
    heap.push_back(str);
    heapifyUp(heap.size()-1);
}

bool minHeap::empty() {
    return heap.empty();
}

int minHeap::size() {
    return heap.size();
}

string minHeap::getElem(int currIndex) {
    return heap[currIndex];
}




