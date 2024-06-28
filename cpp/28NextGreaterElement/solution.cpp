#include <bits/stdc++.h>

using namespace std;

vector<int>* nextGreaterElements(int arr[], int n) {
    vector<int>* ans = new vector<int>(n, -1);
    int count = n*2;
    int ptr = n-1;
    stack<int> s;
    while(count > 0) {
        int val = arr[ptr];
        while(!s.empty() && s.top() <= val) {
            s.pop();
        }

        if (!s.empty()) {
            ans->at(ptr) = s.top();
        }
        s.push(val);
        count--;
        ptr = ptr == 0 ? n-1 : ptr - 1;
    }
    return ans;
}

int main() {
    int arr[]{3,8,7,1,2,4,2};
    vector<int>* ans = nextGreaterElements(arr, 7);
    for(auto val: *ans) {
        cout << val << " ";
    }
}