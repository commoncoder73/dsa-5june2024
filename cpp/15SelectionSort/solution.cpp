#include <bits/stdc++.h>

using namespace std;

int getIndexOfMin(int arr[], int n, int start) {
  int minIndex = start;
  for (int i = start + 1; i < n; i++) {
    if (arr[i] < arr[minIndex]) {
      minIndex = i;
    }
  }
  return minIndex;
}

void swap(int& val1, int& val2) {
  int temp = val1;
  val1 = val2;
  val2 = temp;
}

// TC: O(N^2) SC: O(1)
// Unstable
void sort(int arr[], int n) {
  for (int i = 0; i < n; i++) { 
    int minIndex = i;
    for (int j = i + 1; j < n; j++) { // (n-1) + (n-2) ... + 2+ 1 + 0 = N(N-1)/2 = O(N^2)
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main() {
  int arr[]{6, 2, -1, 3, 9, -10, 9, 97};
  sort(arr, 8);
  printArray(arr, 8);
  return 0;
}