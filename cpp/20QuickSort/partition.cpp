#include <bits/stdc++.h>

using namespace std;

void swap(int& i, int& j) {
  int temp = i;
  i = j;
  j = temp;
}

// TC: O(N) SC:O(1)
int partition(int arr[], int start, int end, int pivot) {
  int boundary = start - 1;
  int checkingPtr = start;
  while (checkingPtr <= end) {
    if (arr[checkingPtr] > pivot) {
      checkingPtr++;
      continue;
    }
    boundary++;
    swap(arr[boundary], arr[checkingPtr]);
    checkingPtr++;
  }
  return boundary;
}

void quickSort(int arr[], int start, int end) {
  if (start >= end) {
    return;
  }
  int& pivot = arr[start];
  int boundary = partition(arr, start, end, pivot);
  swap(arr[boundary], pivot);
  quickSort(arr, start, boundary - 1);
  quickSort(arr, boundary + 1, end);
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main() {
  int arr[]{10, 11, 2, 5, 12, 4, 20, -1, 8, 15, -100};
  quickSort(arr, 0, 10);
  printArray(arr, 11);
}