#include <bits/stdc++.h>

using namespace std;

// 4 5 1 3 2 0

class Result {
 public:
  int inversionCount;
  int* sortedArray;
  int sortedArrayLength;

  Result(int inversionCount, int* sortedArray, int sortedArrayLength) {
    this->inversionCount = inversionCount;
    this->sortedArray = sortedArray;
    this->sortedArrayLength = sortedArrayLength;
  }
};

int countInversion(int arr[], int n) {
  return countInversion(arr, 0, n - 1)->inversionCount;
}

Result* countInversion(int arr[], int start, int end) {
  if (start > end) {
    return new Result(0, new int[0], 0);
  } else if (start == end) {
    return new Result(0, new int[1]{arr[start]}, 1);
  }

  int mid = (start + end) / 2;
  Result* firstHalfResult = countInversion(arr, start, mid);
  Result* secondHalfResult = countInversion(arr, mid + 1, end);
  Result* mergedResult = mergeCountInversion(
      firstHalfResult->sortedArray, firstHalfResult->sortedArrayLength,
      secondHalfResult->sortedArray, secondHalfResult->sortedArrayLength);
  return new Result(firstHalfResult->inversionCount +
                        secondHalfResult->inversionCount +
                        mergedResult->inversionCount,
                    mergedResult->sortedArray, mergedResult->sortedArrayLength);
}

Result* mergeCountInversion(int arr1[], int n1, int arr2[], int n2) {
  int* sortedArray = new int[n1 + n2];
  int count = 0;
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < n1 && j < n2) {
    if (arr1[i] <= arr2[j]) {
      sortedArray[k++] = arr1[i++];
    } else {
      count += (n1 - i);
    }
    sortedArray[k++] = arr2[j++];
  }

  while (i < n1) {
    sortedArray[k++] = arr1[i++];
  }

  while (j < n1) {
    sortedArray[k++] = arr2[j++];
  }

  return new Result(count, sortedArray, n1 + n2);
}

// TC: O(N^2) SC: O: (1)
int inversionCountBruteForce(int arr[], int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        count++;
      }
    }
  }
  return count;
}