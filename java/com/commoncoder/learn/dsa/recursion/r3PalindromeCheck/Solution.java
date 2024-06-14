package com.commoncoder.learn.dsa.recursion.r3PalindromeCheck;

public class Solution {

  // abcsscba - palindrome
  // abcsscba
  // abcba
  // abcba
  // TC: O(N)
  // SC: O(1)
  boolean isPalindrome(String str) {
    int start = 0;
    int end = str.length();

    while (start < end) {
      if (str.charAt(start) != str.charAt(end)) {
        return false;
      }
    }
    return true;
  }

  boolean palindromeCheck(String str, int start, int end) {
    if (start >= end) {
      return true;
    }
    if (
        str.charAt(start) != str.charAt(end)
    ) {
      return false;
    }
    return palindromeCheck(
        str,
        start + 1,
        end - 1
    );
  }

  boolean palindromeCheckWithSubstring(String str) {
    int stringLength = str.length();
    if (stringLength == 0 || stringLength == 1) {
      return true;
    }
    if (
        str.charAt(0) != str.charAt(stringLength - 1)
    ) {
      return false;
    }
    return palindromeCheckWithSubstring(
        // b c d d c b
        str.substring(1, stringLength - 1)
    );
  }

}
