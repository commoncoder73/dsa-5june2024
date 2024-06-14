package com.commoncoder.learn.dsa.recursion.r2AtToThePowerOfB;

public class Solution {

  // TC: O(N)
  // SC: O(N)
  double aToPowerB(int a, int b) {
    if (b >= 0) {
      return positiveAToPowerB(a, b);
    } else {
      return 1.0 / positiveAToPowerB(a, -b);
    }
  }

  // a^b = a^(b-1) * a
  long positiveAToPowerB(int a, int b) {
    if (b < 0) {
      throw new IllegalArgumentException("This function only supports non negative value of n");
    }
    if (b == 0) {
      return 1;
    }
    return positiveAToPowerB(a, b - 1) * a;
  }


}
