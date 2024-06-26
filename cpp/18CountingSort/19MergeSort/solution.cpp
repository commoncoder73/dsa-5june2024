#include <bits/stdc++.h>

using namespace std;

// T: O(N1+N2) 
// but in case of merge sort N1=N2 = N/2
// TC in case of merge sort for this function is O(N)
int* mergeSortedArrays(int arr1[], int n1, int arr2[], int n2) {
  int i = 0;
  int j = 0;
  int k = 0;
  int* mergedArray = new int[n1+n2];
  while (i < n1 && j < n2) {
    if (arr1[i] <= arr2[j]) {
      mergedArray[k++] = arr1[i++];
    } else {
      mergedArray[k++] = arr2[j++];
    }
  }

  while (i < n1) {
    mergedArray[k++] = arr1[i++];
  }

  while (j < n2) {
    mergedArray[k++] = arr2[j++];
  }
  return mergedArray;
}

// TC: O(NlogN)
// SC: O(N)
// stability: stable
int* mergeSort(int arr[], int start, int end) {
  if (start > end) {
    return new int[0]{};
  } else if (start == end) {
    return new int[1]{start};
  }
  int mid = (start + end) / 2;
  int len1 = mid - start + 1;
  int* sortedFirstHalf = mergeSort(arr, start, mid);
  int len2 = end - mid;
  int* sortedSecondHalf = mergeSort(arr, mid + 1, end);
  // O(N)
  return mergeSortedArrays(sortedFirstHalf, len1, sortedSecondHalf, len2);
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main() {
  int arr[]{6, 2, -1, 3, 9, -10, 9, 97};
  int* sortedArray = mergeSort(arr, 0, 7);
  printArray(sortedArray, 8);
  return 0;
}