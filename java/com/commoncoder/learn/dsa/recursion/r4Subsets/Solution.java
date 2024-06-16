package com.commoncoder.learn.dsa.recursion.r4Subsets;

import java.util.ArrayList;
import java.util.Collections;

public class Solution {

  public static void main(String[] args) {
    ArrayList<Character> currentResult = new ArrayList<>();
    ArrayList<ArrayList<Character>> finalResult = new ArrayList<>();
    Solution solution = new Solution();
    solution.subsets(new char[]{'a', 'b', 'c'}, 0, currentResult, finalResult);
    System.out.println(finalResult);
  }

  public void subsets(char[] arr,
      int currentIndex,
      ArrayList<Character> currentResult,
      ArrayList<ArrayList<Character>> finalResult) {
    if (currentIndex >= arr.length) {
      finalResult.add(new ArrayList<>(currentResult));
      return;
    }

    subsets(arr, currentIndex + 1, currentResult, finalResult);
    currentResult.add(arr[currentIndex]);
    subsets(arr, currentIndex + 1, currentResult, finalResult);
    currentResult.remove(currentResult.size() - 1);
  }

}
