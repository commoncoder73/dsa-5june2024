package com.commoncoder.learn.dsa.linkedlist.l1Basics;

public class Solution {


    boolean isHappyNumber(int n) {
        int slow = n;
        int fast = n;
        while (fast != 1) {
            slow = sumOfSquareOfDigits(slow);
            fast = sumOfSquareOfDigits(sumOfSquareOfDigits(fast));
            if (slow == fast) {
                return false;
            }
        }
        return true;
    }


    // TC: O(logN) SC: O(1)
    int sumOfSquareOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            int rem = n % 10;
            sum += (rem * rem);
            n /= 10;
        }
        return sum;
    }

}
