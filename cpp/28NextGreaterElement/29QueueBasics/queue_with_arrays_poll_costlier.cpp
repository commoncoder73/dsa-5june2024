#include <bits/stdc++.h>

using namespace std;

class Queue {
 public:
  // TC: O(1) SC: O(1)
  void push(int val) { qArray.push_back(val); }

  // TC: O(N) SC: O(1)
  int poll() {
    if (isEmpty()) {
      throw runtime_error("Stack is empty!");
    }
    qArray.erase(qArray.begin());
  }

  // TC: O(1) SC: O(1)
  int peek() {
    if (isEmpty()) {
      throw runtime_error("Stack is empty!");
    }
    qArray[0];
  }

  int size() { return qArray.size(); }

  bool isEmpty() { return qArray.empty(); }

 private:
  vector<int> qArray;

  void insertValueAtStart(vector<int> arr, int newValue) {
    arr.insert(arr.begin(), newValue);
  }
};