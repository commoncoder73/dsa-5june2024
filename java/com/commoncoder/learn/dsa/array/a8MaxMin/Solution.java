package com.commoncoder.learn.dsa.array.a8MaxMin;

public class Solution {

  public int max(int[] arr) {
    int max = Integer.MIN_VALUE; // arr[0]
    for(int i=0; i<arr.length; i++) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
    return max;
  }

  public int min(int[] arr) {
    int min = Integer.MAX_VALUE; // arr[0]
    for(int i=0; i<arr.length; i++) {
      if (arr[i] < min) {
        min = arr[i];
      }
    }
    return min;
  }

  public int secondMax(int[] arr) {
    int max = Integer.MIN_VALUE;
    int secondMax = Integer.MIN_VALUE;
    for (int i=0; i<arr.length; i++) {
      if (arr[i] > max) {
        secondMax = max;
        max = arr[i];
      } else if (arr[i] > secondMax) {
        secondMax = arr[i];
      }
    }
    return secondMax;
  }

  public int secondMin(int[] arr) {
    int min = Integer.MAX_VALUE;
    int secondMin = Integer.MAX_VALUE;
    for (int i=0; i<arr.length; i++) {
      if (arr[i] < min) {
        secondMin = min;
        min = arr[i];
      } else if (arr[i] < secondMin) {
        secondMin = arr[i];
      }
    }
    return secondMin;
  }

}
