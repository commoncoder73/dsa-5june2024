#include <bits/stdc++.h>

using namespace std;

// TC: O(N)
// SC: O(N)
void moveAllInstanceToEndSimpleSolve(int arr[], int res[], int n,
                                     int numToMove) {
  int storingPtr = 0;
  int checkingPtr = 0;
  while (checkingPtr < n) {
    if (arr[checkingPtr] != numToMove) {
      res[storingPtr] = arr[checkingPtr];
      storingPtr++;
    }
    checkingPtr;
  }
  // 8 2 1 5 9 _ _ _ _
  while (storingPtr < n) {
    res[storingPtr] = numToMove;
  }
}

void moveAllInstancesToEndOptimal(int arr[], int n, int numToMove) {
  int blue = 0;
  int red = 0;
  while (red < n) {
    if (arr[red] != numToMove) {
      arr[blue] = arr[red];
      blue++;
    }
    red++;
  }
  while (red < n) {
    arr[red] = numToMove;
  }
}
