package com.commoncoder.learn.dsa.array.a5MoveNumToEnd;

public class Solution {

  public void moveGivenNumToEnd(int[] arr, int numToMove) {
    int copyPtr = 0;
    int checkingPtr = 0;
    while(checkingPtr < arr.length) {
      if (arr[checkingPtr] != numToMove) {
        arr[copyPtr] = arr[checkingPtr];
        copyPtr++;
      }
      checkingPtr++;
    }
    while (copyPtr < arr.length) {
      arr[copyPtr] = numToMove;
      copyPtr++;
    }
  }

}
