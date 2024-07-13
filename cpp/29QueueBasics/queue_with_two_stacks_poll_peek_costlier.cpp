#include <bits/stdc++.h>

using namespace std;

class Queue {
 public:
  // TC: O(1) SC: O(1)
  void push(int val) { mainStack.push(val); }

  // TC: O(N) SC: O(N)
  int poll() {
    if (isEmpty()) {
      throw runtime_error("Queue is empty!");
    }
    moveAllElements(mainStack, intermediateStack);
    int topValue = intermediateStack.top();
    intermediateStack.pop();
    moveAllElements(intermediateStack, mainStack);
    return topValue;
  }

  // TC: O(N) SC: O(N)
  int peek() {
    if (isEmpty()) {
      throw runtime_error("Queue is empty!");
    }
    moveAllElements(mainStack, intermediateStack);
    int topValue = intermediateStack.top();
    moveAllElements(intermediateStack, mainStack);
    return topValue;
  }

  int size() { return mainStack.size(); }

  bool isEmpty() { return mainStack.empty(); }

 private:
  stack<int> mainStack;
  stack<int> intermediateStack;

  void moveAllElements(stack<int>& src, stack<int>& dest) {
    while(!src.empty()) {
        dest.push(src.top());
        src.pop();
    }
  }
};