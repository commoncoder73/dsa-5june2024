package com.commoncoder.learn.dsa.binarysearch.b0plainAlgorithm;

public class Solution {

  public static void main(String[] args) {
    int[] arr = new int[]{-6, -5, -2, 0, 1, 2, 5, 9, 11};
    //                             e  s
    Solution solution = new Solution();
    solution.binarySearchRec(
        arr, -6, 0, arr.length - 1
    );
  }

  int binarySearch(int[] arr, int valueToSearch) {
   int start = 0;
   int end = arr.length - 1;
    while(start <= end) {
      int mid = (start + end) / 2;
      if (arr[mid] == valueToSearch) {
        return mid;
      }
      if (valueToSearch < arr[mid]) {
        end = mid - 1;
      } else { // arr[mid] < valueToSearch
        start = mid + 1;
      }
    }
    // start would be at just greater element than what we are looking for
    // end would be at just smaller element than what we are looking for
    return -1;


  }

  int binarySearchRec(int[] arr, int valueToSearch, int start, int end) {
    if (start > end) {
      return -1;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == valueToSearch) {
      return mid;
    }
    if (valueToSearch < arr[mid]) {
      return binarySearchRec(arr, valueToSearch, start, mid - 1);
    } else { // arr[mid] < valueToSearch
      return binarySearchRec(arr, valueToSearch, mid + 1, end);
    }
  }

}

// You are given a rotated array (rotation was done on sorted array)
// But you don't know how many times rotation was done.
// Given such rotated  array write algorithm to find targetElement.
// 1 2 3 4 5 6 7 - X
// 4 5 6 7 1 2 3 -
