#include <bits/stdc++.h>

using namespace std;

// TC: O(N)
// SC: O(1)
int duplicateZeros(int arr[], int length) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    if (arr[i] == 0) {
      count++;
    }
  }
  int newLength = length + count;
  // count would have zero count - how many zeros are there in array
  int ptr = length - 1;
  while (count > 0) {
    if (arr[ptr] != 0) {
      arr[ptr + count] = arr[ptr];
      ptr--;
    } else {
      arr[ptr + count] = arr[ptr];
      count--;
      arr[ptr + count] = 0;  // duplicate zero
      ptr--;
    }
  }
  return newLength;
}
