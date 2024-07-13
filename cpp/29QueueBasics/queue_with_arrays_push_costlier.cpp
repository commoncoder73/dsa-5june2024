#include <bits/stdc++.h>

using namespace std;

class Queue {
 public:
  // TC: O(N) SC: O(1)
  void push(int val) { insertValueAtStart(qArray, val); }

  // TC: O(1) SC: O(1)
  int poll() {
    if (isEmpty()) {
      throw runtime_error("Queue is empty!");
    }
    qArray.pop_back();
  }

  // TC: O(1) SC: O(1)
  int peek() {
    if (isEmpty()) {
      throw runtime_error("Queue is empty!");
    }
    qArray[size() - 1];
  }

  int size() { return qArray.size(); }

  bool isEmpty() { return qArray.empty(); }

 private:
  vector<int> qArray;

  void insertValueAtStart(vector<int> arr, int newValue) {
    arr.insert(arr.begin(), newValue);
  }
};