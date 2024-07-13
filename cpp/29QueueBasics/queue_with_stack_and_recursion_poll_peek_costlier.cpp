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
    return removeBottomElement(mainStack);
  }

  // TC: O(N) SC: O(N)
  int peek() {
    if (isEmpty()) {
      throw runtime_error("Queue is empty!");
    }
    return getBottomElement(mainStack);
  }

  int size() { return mainStack.size(); }

  bool isEmpty() { return mainStack.empty(); }

 private:
  stack<int> mainStack;

  int getBottomElement(stack<int>& s) {
    if (s.size() == 1) {
      return s.top();
    }
    int topValue = s.top();
    s.pop();
    int bottomElement = getBottomElement(s);
    s.push(topValue);
    return bottomElement;
  }

  int removeBottomElement(stack<int>& s) {
    if (s.size() == 1) {
      int bottomElement = s.top();
      s.pop();
      return bottomElement;
    }
    int topValue = s.top();
    s.pop();
    int bottomElement = getBottomElement(s);
    s.push(topValue);
    return bottomElement;
  }
};