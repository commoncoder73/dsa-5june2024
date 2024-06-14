#include <bits/stdc++.h>

using namespace std;

int max(int arr[], int n) {
  if (n == 0) {
    cout << "Empty array";
  }
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int min(int arr[], int n) {
  if (n == 0) {
    cout << "Empty array";
  }
  int min = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

int secondMax(int arr[], int n) {
  if (n == 0) {
    cout << "Empty array";
  }

  int max = INT_MIN;
  int secondMax = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      secondMax = max;
      max = arr[i];
    } else if (arr[i] > secondMax) {
      secondMax = arr[i];
    }
  }
  return secondMax;
}

int secondMin(int arr[], int n) {
  if (n == 0) {
    cout << "Empty array";
  }
  int min = INT_MAX;
  int secondMin = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (arr[i] < min) {
      secondMin = min;
      min = arr[i];
    } else if (arr[i] < secondMin) {
      secondMin = arr[i];
    }
  }
  return secondMin;
}
