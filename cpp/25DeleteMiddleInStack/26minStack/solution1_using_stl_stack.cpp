#include <bits/stdc++.h>

using namespace std;


class MinStack {

public:

    void push(int val) {
        stackForAllValues.push(val);
        if (stackForMin.empty() || getMin() >= val) {
            stackForMin.push(val);
        }
    }

    int pop() {
        int valToPop = top();
        stackForAllValues.pop();
        if (getMin() == valToPop) {
            stackForMin.pop();
        }
        return valToPop;
    }

    int top() {
        return stackForAllValues.top();
    }

    int getMin() {
        return stackForMin.top();
    }

    int size() {
        return stackForAllValues.size();
    }

    bool isEmpty() {
        return stackForAllValues.empty();
    }

private:
    stack<int> stackForAllValues;
    stack<int> stackForMin;


};