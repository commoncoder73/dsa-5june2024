package com.commoncoder.learn.dsa.array.a10maxSubArraySumPositive;

public class Solution {

  static class Answer {

    int maxSum;
    int start;
    int end;

    public Answer(int maxSum, int start, int end) {
      this.maxSum = maxSum;
      this.start = start;
      this.end = end;
    }
  }

  Answer maxWindowSum(int[] arr, int k) {
    if (k > arr.length) {
      throw new IllegalArgumentException("Not possible!");
    }
    int sum = 0;
    for (int i = 0; i < k; i++) {
      sum += arr[i];
    }
    int maxSum = sum;
    int start = 0;
    int end = k - 1;
    for (int i = k; i < arr.length; i++) {
      sum += arr[i];
      sum -= arr[i - k];

      if (sum > maxSum) {
        end = i;
        start = i - k + 1;
        maxSum = sum;
      }
    }
    return new Answer(maxSum, start, end);
  }


}
