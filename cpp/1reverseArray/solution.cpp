#include <bits/stdc++.h>

using namespace std;

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void reverseArray(int arr[], int n) {
  int left = 0;
  int right = n - 1;
  while (left < right) {
    swap(arr[left], arr[right]);
    left++;
    right--;
  }
}

int main() {
  int arr[6] = {1, 2, 3, 4, 5, 6};
  int n = 6;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  reverseArray(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
