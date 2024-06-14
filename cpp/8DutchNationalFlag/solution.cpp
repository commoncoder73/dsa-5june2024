#include <bits/stdc++.h>

using namespace std;

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

// TC: O(N)
// SC: O(1)
void sortColors(int arr[], int n) {
  int zerosEndPtr = -1;
  int twosStartPtr = n;
  int checkingPtr = 0;  // till
  while (checkingPtr < twosStartPtr) {
    if (arr[checkingPtr] == 0) {
      zerosEndPtr++;
      swap(arr[zerosEndPtr], arr[checkingPtr]);
    } else if (arr[checkingPtr] == 2) {
      twosStartPtr--;
      swap(arr[twosStartPtr], arr[checkingPtr]);
    } else {
      checkingPtr++;
    }
  }
}
