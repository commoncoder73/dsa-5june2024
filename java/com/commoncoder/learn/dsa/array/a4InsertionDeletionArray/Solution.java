package com.commoncoder.learn.dsa.array.a4InsertionDeletionArray;

public class Solution {

  // TC: O(N)
  // SC: O(1)
  public int insert(int[] arr, int length, int val, int index) {
    if (length == arr.length) {
      throw new IllegalArgumentException("Array is full!");
    }

    if (index > length || index < 0) {
      throw new IllegalArgumentException("Provide valid index");
    }
    int itr = length-1;
    while(itr >= index) {
      arr[itr+1] = arr[itr];
      itr--;
    }
    arr[index] = val;
    length++;
    return length;
  }

  // TC: O(N)
  // SC: O(1)
  public int delete(int[] arr, int length, int index) {
    if (length == 0) {
      throw new IllegalArgumentException("Array is empty!");
    }
    if (index >= length || index < 0) {
      throw new IllegalArgumentException("Provide valid index");
    }

    int itr = index;
    while(itr < length - 1) {
      arr[itr] = arr[itr+1];
      itr++;
    }
    arr[index] = 0;
    length--;
    return length;
  }

}
