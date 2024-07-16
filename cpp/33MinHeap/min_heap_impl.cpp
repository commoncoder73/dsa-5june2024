#include <bits/stdc++.h>

using namespace std;

class MinHeap {
 public:
  MinHeap(int heapCapacity) {
    this->heapArray = new int[heapCapacity];
    this->heapSize = 0;
  }

  MinHeap(int* heapArray, int heapSize) {
    this->heapArray = heapArray;
    this->heapSize = heapSize;
    buildHeap();
  }

  int getMin() {
    if (heapSize <= 0) {
      throw runtime_error("Heap is emtpy!");
    }
    return heapArray[0];
  }

  // addNewValue
  // deleteByIndex
  // removeMin

 private:
  int* heapArray;
  int heapSize;

  // TC: O(N) (This is closer bound)
  // SC: O(logN) because of recursion
  // SC: O(1) in iterative way
  void buildHeap() {
    int lastLeafNodeIndex = parent(heapSize - 1);
    for (int i = lastLeafNodeIndex; i >= 0; i--) {
      heapify(i);
    }
  }

  // TC: O(logN)
  // SC: O(logN) because of recursion
  // SC: O(1) in iterative way
  void heapify(int index) {
    int minValueIndex = index;

    while (index < heapSize) {
      int leftChildIndex = left(index);
      int rightChildIndex = right(index);

      if (leftChildIndex < heapSize &&
          heapArray[leftChildIndex] < heapArray[minValueIndex]) {
        minValueIndex = leftChildIndex;
      }

      if (rightChildIndex < heapSize &&
          heapArray[rightChildIndex] < heapArray[minValueIndex]) {
        minValueIndex = rightChildIndex;
      }

      if (minValueIndex != index) {
        swap(minValueIndex, index);
        index = minValueIndex;
      } else {
        break;
      }
    }
  }

  void swap(int i, int j) {
    int temp = heapArray[i];
    heapArray[i] = heapArray[j];
    heapArray[j] = temp;
  }

  int left(int i) { return 2 * i + 1; }
  int right(int i) { return 2 * i + 2; }
  int parent(int i) { return (i - 1) / 2; }
};