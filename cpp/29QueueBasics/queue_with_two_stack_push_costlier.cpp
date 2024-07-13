#include <bits/stdc++.h>

using namespace std;

class Queue {
 public:
  // TC: O(N) SC: O(N)
  void push(int val) {
    moveAllElements(mainStack, intermediateStack);
    mainStack.push(val);
    moveAllElements(intermediateStack, mainStack);
  }

  // TC: O(1) SC: O(1)
  int poll() {
    if (isEmpty()) {
      throw runtime_error("Queue is empty!");
    }
    int topValue = mainStack.top();
    mainStack.pop();
    return topValue;
  }

  // TC: O(1) SC: O(1)
  int peek() {
    if (isEmpty()) {
      throw runtime_error("Queue is empty!");
    }
    return mainStack.top();
  }

  int size() { return mainStack.size(); }

  bool isEmpty() { return mainStack.empty(); }

 private:
  stack<int> mainStack;
  stack<int> intermediateStack;

  void moveAllElements(stack<int>& src, stack<int>& dest) {
    while (!src.empty()) {
      dest.push(src.top());
      src.pop();
    }
  }
};