#include <bits/stdc++.h>

using namespace std;

class Queue {
 public:
  Queue(int capacity) {
    this->arr = new int[capacity];
    this->capacity = capacity;
  }

  // TC: O(1) SC: O(1)
  void push(int val) {
    if (length == capacity) {
      throw runtime_error("Queue is full!");
    }
    length++;
    last = (last + 1) % capacity;
    arr[last] = val;
  }

  // TC: O(1) SC: O(1)
  int poll() {
    if (isEmpty()) {
      throw runtime_error("Queue is empty!");
    }
    length--;
    int polledValue = peek();
    first = (first + 1) % capacity;
    return polledValue;
  }

  // TC: O(1) SC: O(1)
  int peek() {
    if (isEmpty()) {
      throw runtime_error("Queue is empty!");
    }
    return arr[first];
  }

  int size() { return length; }

  bool isEmpty() { return length == 0; }

 private:
  int* arr;
  int capacity;
  int length = 0;
  int last = -1;
  int first = 0;
};