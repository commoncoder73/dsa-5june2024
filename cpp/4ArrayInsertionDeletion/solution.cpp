#include <bits/stdc++.h>

using namespace std;

/**
 * 1 2 0 9 3 _ _ _ _
 * 0 1 2 3 4 5 6 7 8 9
 *
 * TC: O(N)
 * SC: O(1)
 */
void addToArray(int arr[], int length, int capacity, int newValue, int index) {
  if (length == capacity) {
    cout << "Array is full";
    return;
  }
  if (index < 0 || index > length) {
    cout << "Index is invalid";
    return;
  }

  int ptr = length - 1;
  while (ptr >= index) {
    arr[ptr + 1] = arr[ptr];
    ptr--;
  }
  arr[index] = newValue;
}

// We are returning new length
// 1 2 7 9 3 0 _ _ _ _ _
// 0 1 2 3 4 5 6 7 8 9
// length 5

int deleteFromArray(int arr[], int length, int index) {
  if (length == 0) {
    cout << "Nothing to delete";
    return 0;
  }
  int ptr = index;
  while (ptr < length - 1) {
    arr[ptr] = arr[ptr + 1];
  }
  arr[length - 1] = 0;
  return length - 1;
}

