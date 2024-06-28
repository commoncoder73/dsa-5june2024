package com.commoncoder.learn.dsa.stack.s3nextGreaterElement;

import java.util.Arrays;
import java.util.Stack;

public class Solution {

    // T: O(N) S: O(N)
    public Integer[] nextGreaterElement(int[] arr) {
        Integer[] ans = new Integer[arr.length];
        int count = arr.length * 2;
        Stack<Integer> decreasingStack = new Stack<>();
        int ptr = arr.length - 1;
        // 2N
        while (count > 0) {
            int val = arr[ptr];

            while (!decreasingStack.empty() && decreasingStack.peek() <= val) {
                decreasingStack.pop();
            }

            if (!decreasingStack.empty()) {
                ans[ptr] = decreasingStack.peek();
            }
            decreasingStack.push(val);
            ptr = ptr == 0 ? arr.length - 1 : ptr - 1;
            count--;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = new int[]{3, 8, 7, 1, 2, 1, 4, 2};
        Integer[] ans = new Solution().nextGreaterElement(arr);
        System.out.println(Arrays.toString(ans));
    }

}
