#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
 public:
  MaxHeap(int heapCapacity) {
    this->heapArray = new int[heapCapacity];
    this->heapSize = 0;
  }

  MaxHeap(int* heapArray, int heapSize) {
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

   void printHeap() {
    for (int i = 0; i < heapSize; i++) {
      cout << heapArray[i] << " ";
    }
    cout << endl;
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
    int maxValueIndex = index;

    while (index < heapSize) {
      int leftChildIndex = left(index);
      int rightChildIndex = right(index);

      if (leftChildIndex < heapSize &&
          heapArray[leftChildIndex] > heapArray[maxValueIndex]) {
        maxValueIndex = leftChildIndex;
      }

      if (rightChildIndex < heapSize &&
          heapArray[rightChildIndex] > heapArray[maxValueIndex]) {
        maxValueIndex = rightChildIndex;
      }

      if (maxValueIndex != index) {
        swap(maxValueIndex, index);
        index = maxValueIndex;
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
    int arr[]{25, 20, 11, 15, 13, 12, 15, 19, 9, 8, 7, 7};
    MaxHeap* maxHeap = new MaxHeap(arr, 12);
    maxHeap->printHeap();
    return 0;
}