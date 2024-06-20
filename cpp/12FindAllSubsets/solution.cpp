#include <bits/stdc++.h>

using namespace std;

void subsets(vector<int>& arr, int start, vector<int>& curResult, 
    vector<vector<int>>& finalResult) {

    if (start >= arr.size()) {
        vector<int> result(curResult);
        finalResult.push_back(result);
        return;
    }

    subsets(arr, start + 1, curResult, finalResult);
    curResult.push_back(arr[start]);
    subsets(arr, start + 1, curResult, finalResult);
    curResult.pop_back(); // curResult.remove(curResult.size()-1);

}

int main() {

}