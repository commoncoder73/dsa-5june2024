#include <bits/stdc++.h>

using namespace std;

class Queue {
 public:
  // TC: O(N) SC: O(N)
  void push(int val) { insertAtBottom(mainStack, val); }

  // TC: O(1) SC: O(1)
  int poll() {
    if (isEmpty()) {
      throw runtime_error("Stack is empty!");
    }
    int top = mainStack.top();
    mainStack.pop();
    return top;
  }

  // TC: O(1) SC: O(1)
  int peek() {
    if (isEmpty()) {
      throw runtime_error("Stack is empty!");
    }
    return mainStack.top();
  }

  int size() { return mainStack.size(); }

  bool isEmpty() { return mainStack.empty(); }

 private:
  stack<int> mainStack;

  void insertAtBottom(stack<int>& s, int valToAdd) {
    if (s.empty()) {
      s.push(valToAdd);
      return;
    }

    // keep top value aside
    int topVal = s.top();
    s.pop();

    // insert new value at bottom
    insertAtBottom(s, valToAdd);

    s.push(topVal);
  }
};