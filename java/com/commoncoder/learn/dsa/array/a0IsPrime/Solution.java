package com.commoncoder.learn.dsa.array.a0IsPrime;

public class Solution {

  public boolean isPrime(int num) {
    for (int i=2; i*i<=num; i++) {
      if (num % i == 0) {
        return false;
      }
    }
    return true;
  }





}
