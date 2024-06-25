#include <bits/stdc++.h>

using namespace std;

void swap(int& val1, int& val2) {
  int temp = val1;
  val1 = val2;
  val2 = temp;
}

// TC: O(N^2) SC: O(1)
// Stable
void sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        // ---- > ------
        // ----- = -----
      }
    }
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