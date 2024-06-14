package com.commoncoder.learn.dsa.array.a1ReverseArray;

public class Solution {

  // TC: O(N)
  // SC: O(1)
  public int[] simpleSolve(int[] arr) {
    int i = 0;
    int j = arr.length - 1;
    while(i<j) {
      swap(arr, i, j);
      i++;
      j--;
    }
    return arr;

  }

  private void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

}
