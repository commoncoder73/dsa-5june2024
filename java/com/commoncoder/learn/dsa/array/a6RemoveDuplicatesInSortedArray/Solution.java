package com.commoncoder.learn.dsa.array.a6RemoveDuplicatesInSortedArray;

import java.util.Arrays;

public class Solution {

  // TC: O(N)
  // SC: O(1)
  public int removeDuplicatesFromSortedArray(int[] arr) {
    if (arr.length == 0) {
      return 0;
    }
    int arrayFilledPointer = 0;
    int checkingPointer = 1;
    while (checkingPointer < arr.length) {

      if (arr[checkingPointer] == arr[checkingPointer - 1]) {
        checkingPointer++;
        continue;
      }
      arrayFilledPointer++;
      arr[arrayFilledPointer] = arr[checkingPointer];
      checkingPointer++;
    }
    return arrayFilledPointer + 1;
  }

}
