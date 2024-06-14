package com.commoncoder.learn.dsa.recursion.r1PowersOfTwo;

public class Solution {

  // TC: O(N)
  // SC: O(N)
  double powersOfTwo(int n) {
    if (n >= 0) {
      return positivePowersOfTwo(n);
    }
    else {
      return 1.0/positivePowersOfTwo(-n);
    }
  }

  long positivePowersOfTwo(int n) {
    if (n < 0 ) {
      throw new IllegalArgumentException("This function only supports non negative value of n");
    }
    if (n == 0) {
      return 1;
    }
    return positivePowersOfTwo(n-1) * 2;
  }



}
