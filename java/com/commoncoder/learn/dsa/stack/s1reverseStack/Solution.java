package com.commoncoder.learn.dsa.stack.s1reverseStack;

import java.util.Stack;

public class Solution {

    // TC: O(N) SC: O(N)
    public void insertValueAtBottom(Stack<Integer> stack, int valToAdd) {
        if (stack.empty()) {
            stack.push(valToAdd);
            return;
        }
        int topValue = stack.pop();
        insertValueAtBottom(stack, valToAdd);
        stack.push(topValue);
    }

    // TC: O(N^2) SC: O(N)
    public void reverseStack(Stack<Integer> stack) {
        if (stack.empty()) {
            return;
        }
        int valAtTop = stack.pop();
        reverseStack(stack);
        insertValueAtBottom(stack, valAtTop);
    }

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);
        Solution solution = new Solution();
        solution.reverseStack(stack);
        System.out.println(stack);
    }

}
