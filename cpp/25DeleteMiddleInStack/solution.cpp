#include <bits/stdc++.h>

using namespace std;


// TC: O(N) SC: O(N)
void deleteMiddleFromStack(stack<int> s) {
    if (s.empty()) {
        return;
    }
    int mid = s.size()/2;
    deleteNthElementFromTop(s, mid);
}

// 0 based position
void deleteNthElementFromTop(stack<int> s, int n) {

    if (n == 0) {
        s.pop();
        return;
    }

    int topVal = s.top();
    s.pop();
    deleteNthElementFromTop(s, n-1);

    s.push(topVal);

}
