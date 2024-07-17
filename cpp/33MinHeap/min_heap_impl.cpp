#include <bits/stdc++.h>

using namespace std;

class MinHeap {
 public:
  MinHeap(int heapCapacity) {
    this->heapArray = new int[heapCapacity];
    this->heapSize = 0;
    this->heapCapacity;
  }

  MinHeap(int* heapArray, int heapSize, int heapCapacity) {
    this->heapArray = heapArray;
    this->heapSize = heapSize;
    this->heapCapacity;
    buildHeap();
  }

  int getMin() {
    if (heapSize <= 0) {
      throw runtime_error("Heap is emtpy!");
    }
    return heapArray[0];
  }

  void printHeap() {
    for (int i = 0; i < heapSize; i++) {
      cout << heapArray[i] << " ";
    }
    cout << endl;
  }

  // TC: O(logN)
  // SC: O(1)
  void add(int newValue) {
    if (heapSize == heapCapacity) {
      throw runtime_error("Heap is full!");
    }
    heapSize++;
    int index = heapSize - 1;
    heapArray[index] = newValue;
    while (index > 0 && heapArray[parent(index)] > heapArray[index]) {
      swap(parent(index), index);
      index = parent(index);
    }
  }

  // TC: O(logN)
  // SC: O(1)
  int deleteByIndex(int indexToDelete) {
    if (!(0 <= indexToDelete && indexToDelete < heapSize)) {
      throw runtime_error("Valid index to delete not provided!");
    }
    int valToDelete = heapArray[indexToDelete];
    swap(indexToDelete, heapSize - 1);
    heapArray[heapSize - 1] = 0;  // optionally
    heapSize--;
    heapify(indexToDelete);
  }

// TC: O(logN)
  // SC: O(1)
  int removeMin() {
    // we know index of min value in min heap and that is 0
    // We also know how to delete value by its index. deleteByIndex
    return deleteByIndex(0);
  }

  int size() {
    return heapSize;
  }

  bool isEmpty() {
    return size() == 0;
  }

 private:
  int* heapArray;
  int heapSize;
  int heapCapacity;

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

int main() {
  int arr[]{25, 20, 11, 15, 13, 12, 15, 19, 9, 8, 7, 7, 0, 0};
  MinHeap* minHeap = new MinHeap(arr, 12, 14);
  minHeap->add(9);
  minHeap->add(-1);
  minHeap->printHeap();
  return 0;
}