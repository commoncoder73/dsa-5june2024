#include <bits/stdc++.h>

using namespace std;

void reverseStack(stack<int> s) {
    if (s.empty()) {
        return;
    }
    // keep top value aside
    int topVal = s.top();
    s.pop();

    // reverse the remaining part of stack
    reverseStack(s);

    // insert top value at bottom
    insertAtLast(s, topVal);

}

void insertAtLast(stack<int> s, int valToAdd) {
    if (s.empty()) {
        s.push(valToAdd);
        return;
    }

    // keep top value aside
    int topVal = s.top();
    s.pop();

    // insert new value at bottom
    insertAtLast(s, valToAdd);

    s.push(topVal);

}