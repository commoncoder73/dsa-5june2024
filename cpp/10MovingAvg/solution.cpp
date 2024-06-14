#include <bits/stdc++.h>

using namespace std;

// res should be of size n-k+1
// TC: O(N)
// SC: O(N-k)
void movingAvg(int arr[], int n, int res[], int k) {
  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += arr[i];
  }
  int resPtr = 0;
  res[resPtr++] = sum / k;
  // 0   1  2  3  4  5  6  7  8
  // v1 v2 v3 v4 v5 v6 v7 v8 v9
  for (int i = k; i < n; i++) {
    sum += arr[i];
    sum -= arr[i - k];
    res[resPtr++] = sum / k;
  }
}
