package com.commoncoder.learn.dsa.array.a3TwoPairSumSorted;

import java.util.Arrays;

public class Solution {

  public int[] findPairWithTargetSum(int[] arr, int targetSum) {
    int left = 0;
    int right = arr.length-1;
    while (left < right) {
      int sum = arr[left] + arr[right];
      if (sum == targetSum) {
        return new int[]{left, right};
      }
      if (sum > targetSum) {
        right--;
      } else {
        left++;
      }
    }
    return new int[]{};
  }

}
