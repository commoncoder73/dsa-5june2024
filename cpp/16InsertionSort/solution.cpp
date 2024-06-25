#include <bits/stdc++.h>

using namespace std;

// TC: O(N^2) SC: O(1)
// Stable
void sort(int arr[], int n) {
  for (int i = 1; i<n; i++) {  // n-1
    int valToInsert = arr[i];
    int ptr = i - 1;
    while (ptr >= 0 && arr[ptr] > valToInsert) {  //1 2 3 4 5 n-1 ... O(N^2)
        arr[ptr+1] = arr[ptr];
        ptr--;
    }
    arr[ptr + 1] = valToInsert;
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