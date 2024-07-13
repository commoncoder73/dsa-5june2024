#include <bits/stdc++.h>

using namespace std;

class MinMaxQ {
 public:
  // TC: O(N) but amortized time complexity is O(1)
  void push(int val) {
    mainQ.push(val);
    while (!maxDeque.empty() && maxDeque.back() < val) {
      maxDeque.pop_back();
    }
    maxDeque.push_back(val);

    while (!minDeque.empty() && minDeque.back() > val) {
      minDeque.pop_back();
    }
    minDeque.push_back(val);
  }

  // TC: O(1)
  int poll() {
    if (isEmpty()) {
      throw runtime_error("Q is empty!");
    }
    int valBeingPolled = peek();
    mainQ.pop();
    if (valBeingPolled == getMax()) {
      maxDeque.pop_front();
    }

    if (valBeingPolled == getMin()) {
      minDeque.pop_front();
    }
  }
  // TC: O(1)
  int peek() {
    if (isEmpty()) {
      throw runtime_error("Q is empty!");
    }
    return mainQ.front();
  }
  // TC: O(1)
  int getMin() {
    if (isEmpty()) {
      throw runtime_error("Q is empty!");
    }
    return minDeque.front();
  }
  // TC: O(1)
  int getMax() {
    if (isEmpty()) {
      throw runtime_error("Q is empty!");
    }
    return maxDeque.front();
  }

  int size() { return mainQ.size(); }

  bool isEmpty() { return mainQ.empty(); }

 private:
  queue<int> mainQ;
  deque<int> maxDeque;
  deque<int> minDeque;
};