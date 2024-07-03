#include <bits/stdc++.h>

using namespace std;

class Stack {
 public:
  // TC: O(1) SC: O(1)
  void push(int val) { mainQ.push(val); }

  // TC: O(N) SC: O(1)
  int pop() {
    if (isEmpty()) {
      throw runtime_error("Stack is empty!");
    }
    moveElementsBack(mainQ, size() - 1);
    int lastElement = mainQ.front();
    mainQ.pop();
    return lastElement;
  }

  // TC: O(N) SC: O(1)
  int top() {
    if (isEmpty()) {
      throw runtime_error("Stack is empty!");
    }
    moveElementsBack(mainQ, size() - 1);
    int lastElement = mainQ.front();
    moveElementsBack(mainQ, 1);
    return lastElement;
  }

  int size() { return mainQ.size(); }

  bool isEmpty() { return size() == 0; }

 private:
  queue<int> mainQ;

  void moveElementsBack(queue<int>& q, int n) {
    if (q.size() <= 1) {
      return;
    }
    n = n % q.size();
    while ((n > 0)) {
      int val = q.front();
      q.pop();
      q.push(val);
      n--;
    }
  }
};