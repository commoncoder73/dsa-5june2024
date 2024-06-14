package com.commoncoder.learn.dsa.array.a9DuplicateZeros;

public class Solution {

  public void duplicateZeros(int[] arr, int len) {
    int zeroCount = 0;
    for (int val : arr) {
      if (val == 0) {
        zeroCount++;
      }
    }
    int ptr = len - 1;
    while (zeroCount>0) {
      arr[ptr+zeroCount] = arr[ptr];
      ptr--;
      if (arr[ptr] == 0) {
        arr[ptr] = 0; // duplicated zero
        zeroCount--;
        ptr--;
      }
    }
  }

}
