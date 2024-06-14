package com.commoncoder.learn.dsa.array.a2SquareSortedArray;

public class Solution {

  public int[] squareSortedArray(int[] arr) {
    int left = 0;
    int right = arr.length - 1;
    int[] result = new int[arr.length];
    int resultPtr = arr.length - 1;
    while (left <= right) {
      int leftSquareVal = square(arr[left]);
      int rightSquareVal = square(arr[right]);
      if (leftSquareVal > rightSquareVal) {
        result[resultPtr--] = leftSquareVal;
        left++;
      } else {
        result[resultPtr--] = rightSquareVal;
        right--;
      }
    }
    return result;
  }

  private int square(int val) {
    return val * val;
  }

}
