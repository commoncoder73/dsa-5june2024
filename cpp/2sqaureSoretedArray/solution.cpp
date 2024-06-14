#include <bits/stdc++.h>

int square(int val) { return val * val; }

void sqaureSortedArray(int arr[], int res[], int n) {
  int start = 0;
  int end = n - 1;
  int i = n - 1;
  while (start <= end) {
    int startSquare = square(arr[start]);
    int endSquare = square(arr[end]);
    if (startSquare >= endSquare) {
      res[i--] = startSquare;
    } else {
      res[i--] = endSquare;
    }
  }
}
