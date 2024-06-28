#include <bits/stdc++.h>

using namespace std;


class MinStack {

public:

    void push(int val) {
        stackForAllValues.push_back(val);
        if (stackForMin.empty() || getMin() >= val) {
            stackForMin.push_back(val);
        }
    }

    int pop() {
        int valToPop = top();
        stackForAllValues.pop_back();
        if (getMin() == valToPop) {
            stackForMin.pop_back();
        }
        return valToPop;
    }

    int top() {
        return stackForAllValues.back();
    }

    int getMin() {
        return stackForMin.back();
    }

    int size() {
        return stackForAllValues.size();
    }

    bool isEmpty() {
        return stackForAllValues.empty();
    }

private:
    vector<int> stackForAllValues;
    vector<int> stackForMin;

};

// s: 5 4 3 2 1