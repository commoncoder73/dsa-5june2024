#include <bits/stdc++.h>

using namespace std;

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

// TC: O(N) SC: O(k)
void reverse(queue<int>& q, int k) {
    stack<int> s;
    int i=0;
    // from q to stack
    while(i<k) {
        s.push(q.front());
        q.pop();
        i++;
    }

    i=0;
    // from stack to q
    while(i<k) {
        q.push(s.top());
        s.pop();
        i++;
    }

    moveElementsBack(q, q.size() - k);

}

void reverseRec(queue<int>& q, int k) {
    // 1 2 3 4 5 6 7 8
    // 5 4 3 2 1 6 7 8
    reverseKElementsAndAddAtEndOfQ(q, k); //   5 4 3 2 1 6 7 8 
    moveElementsBack(q, q.size() - k);
}

void reverseKElementsAndAddAtEndOfQ(queue<int>& q, int k) {
    if (k <= 0) {
        return;
    }
    int firstVal = q.front(); 
    q.pop();
    reverseKElementsAndAddAtEndOfQ(q, k-1);
    q.push(firstVal);

}

  