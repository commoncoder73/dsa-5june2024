#include <bits/stdc++.h>

using namespace std;

// TC: O(N)
// SC: O(N)
void removeDuplicatesWithNewArray(int arr[], int n, int res[]) {
  int newArrayPtr = 0;
  int oldArrayPtr = 0;
  while (oldArrayPtr < n) {
    if (oldArrayPtr == 0 || arr[oldArrayPtr] != arr[oldArrayPtr - 1]) {
      res[newArrayPtr] = arr[oldArrayPtr];
      newArrayPtr++;
    }
    oldArrayPtr++;
  }
}

// TC: O(N)
// SC: O(1)
// 2 2 3 3 4 5 5 5 6 7 7 8  -- 2 3 5 7  2 3  5 5 7
//               .
// 2 3 4 5 6 7 8 _ _ _ _ _
int removeDuplicatesWithSameArray(int arr[], int n) {
  if (n == 0) {
    return;
  }
  int red = 1;
  int blue = 1;
  while (red < n) {
    if (arr[red] != arr[red - 1]) {
      arr[blue] = arr[red];
      blue++;
    } else {
      cout << "New duplicating element: " << arr[red];
    }
    red++;
  }
  return blue;
}
