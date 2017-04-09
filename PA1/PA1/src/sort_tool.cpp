// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2015/03/02 Yu-Hao Ho]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    SortSubVector(data, 0, data.size() - 1);
}

// Sort subvector
void SortTool::SortSubVector(vector<int>& data, int low, int high) {
    // Function : Sort subvector
    // TODO : Please complete SortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    Build_Max_Heap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        Max_Heapify(data,0);
    }
}

//Max heapify
void SortTool::Max_Heapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
}

//Build max heap
void SortTool::Build_Max_Heap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete Build_Max_Heap code here
}
