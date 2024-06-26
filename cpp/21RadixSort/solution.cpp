#include <bits/stdc++.h>

using namespace std;

// O(logN) (to the base of 10)
int getDigitsCount(int val) {
  int count = 0;
  while (val > 0) {
    count++;
    val /= 10;
  }
  return count;
}


// Assume that there are N numbers in array and maximum number is M
// O(N + logM)
int getMaxDigitsCount(int arr[], int n) {
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return getDigitsCount(max);
}

void convertToCumulativeSum(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    arr[i] = sum;
  }
}


int getDigitAtPlace(int val, int place) { return (val / place) % 10; }

// 1 - units
// 10 - tens
// 100 - hundreds
void sortDigitsAtPlace(int arr[], int n, int place) {
  int count[10]{0};
  for (int i = 0; i < n; i++) {
    int digit = getDigitAtPlace(arr[i], place);
    count[digit]++;
  }
  convertToCumulativeSum(count, 10);
  int sortedArray[n];
  for (int i = n - 1; i >= 0; i--) {
    int digit = getDigitAtPlace(arr[i], place);
    int position = count[digit];
    sortedArray[position - 1] = arr[i];
    count[digit]--;
  }
  for (int i = 0; i < n; i++) {
    arr[i] = sortedArray[i];
  }
}

// Assume that there are N numbers in array and maximum number is M
// TC: O(N*logM)
// SC: O(N)
void radixSort(int arr[], int n) {
  // O(N + logM)
  int maxDigits = getMaxDigitsCount(arr, n);
  int place = 1;

    // O(N*logM)
  for (int i = 0; i < maxDigits; i++) { // logM
    sortDigitsAtPlace(arr, n, place); // O(N+9) ~ O(N)
    place *= 10;
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main() {
    int arr[]{121, 432, 564, 23, 1, 45, 788};
    radixSort(arr, 7);
    printArray(arr, 7);
}