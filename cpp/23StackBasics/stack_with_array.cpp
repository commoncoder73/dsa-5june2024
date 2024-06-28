#include <bits/stdc++.h>

using namespace std;

class Stack {

public:
    void push(int val) {
        stackArr.push_back(val);
    }

    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty!");
        }
        int topValue = top();
        stackArr.pop_back(); // remove last element
        return topValue;
    }

    int top() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty!");
        }
        return stackArr.at(stackArr.size() - 1);
    }

    int size() {
        return stackArr.size();
    }

    bool isEmpty() {
        return size() == 0;
    }

private:
    vector<int> stackArr;
    
};