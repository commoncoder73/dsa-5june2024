package com.commoncoder.learn.dsa.array.a7MovingAvg;

public class Solution {

  // TC: O(N)
  // SC: O(N-k)
  public int[] movingAvg(int[] arr, int k) {
    int sum = 0;
    for(int i=0; i<k; i++) {
      sum+=arr[i];
    }
    int[] res = new int[arr.length - k + 1];
    int start = 0;
    int end = k-1;
    res[start] = sum / k;

    while(end+1 < arr.length) {
      end++;
      sum += arr[end];
      sum -= arr[start];
      start++;
      res[start] = sum/k;
    }
    return res;

  }


  // TC: O(N*k)
  // SC: O(N-k)
  public int[] movingAvgBruteForce(int[] arr, int k) {
    int[] res = new int[arr.length - k + 1];

    for(int i=0; i<arr.length-k; i++) {
      int sum = 0;
      for (int j=0; j<k; j++) {
        sum += arr[i+j];
      }
      res[i] = sum/k;
    }
    return res;
  }

}
