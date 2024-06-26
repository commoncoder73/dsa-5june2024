#include <bits/stdc++.h>

using namespace std;

// 4 3 2 5 1
// 0 0 0 0 1 1 1 2 2 3 3 3 3 3 4
void countToSortedArray(int arr[], int n, int count[], int c) {
  int i = 0;
  for (int j = 0; j < c; j++) {
    for (int k = 0; k < count[j]; k++) {  // j=1  count[j]=3 k - 012
      arr[i++] = j;
    }
  }
  // finally arr would be sorted
}

int max(int arr[], int n) {
  int maxVal = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
  }
  return maxVal;
}

void countInstances(int arr[], int n, int count[]) {
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }
}

void convertToCumulativeSum(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    arr[i] = sum;
  }
}


void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

// T:O(M+N) S:O(N)
// Assume that size of input array is N and size of count array is M
void countToSortedArrayUsingCumulativeSum(int arr[], int n, int count[],
                                          int c) {
  // T:O(M) S:O(1)
  convertToCumulativeSum(count, c);
  //        S:O(N)
  int sortedArray[n];

  // T:O(N)
  for (int i = n - 1; i >= 0; i--) {
    int positionToInsertAt = count[arr[i]];
    sortedArray[positionToInsertAt - 1] = arr[i];
    count[arr[i]]--;
  }
  for (int i = 0; i < n; i++) {
    arr[i] = sortedArray[i];
  }
}


// Assume that array size is of length N and max value in this array is M
// T: O(N+N+M+N = 3N+M) ~ O(N+M)
// S: O(1+M+1+N = N+M+2) ~ O(M+N)
// stability: stable
// Counting sort is more better if you have more repeating numbers in smaller range
void countingSort(int arr[], int n) {
  //T:O(N) S:O(1)
  int maxVal = max(arr, n);

  //        S: O(M)
  int count[maxVal + 1]{0};
  //T:O(N)  S:O(1)
  countInstances(arr, n, count);
  // T:O(M+N)  S:O(N)
  countToSortedArrayUsingCumulativeSum(arr, n, count, maxVal + 1);
}


int main() {
  int arr[]{5, 6, 1, 1, 5, 6, 6, 0, 2, 1};
  countingSort(arr, 10);
  printArray(arr, 10);
  return 0;
}