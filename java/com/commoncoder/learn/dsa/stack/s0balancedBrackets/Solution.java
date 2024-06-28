package com.commoncoder.learn.dsa.stack.s0balancedBrackets;

import java.util.Stack;

public class Solution {

    private boolean isOpeningBracket(char c) {
        return c == '(' || c == '{' || c == '[';
    }

    private char getMatchingOpeningBracket(char c) {
        if (c == ')') {
            return '(';
        } else if (c == '}') {
            return '}';
        } else {
            return ']';
        }
    }

    public boolean areBracketsBalanced(String brackets) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < brackets.length(); i++) {
            char bracket = brackets.charAt(i);
            if (isOpeningBracket(bracket)) {
                stack.push(bracket);
                continue;
            }

            if (stack.empty()) {
                return false;
            }
            char expectedOpeningBracket = getMatchingOpeningBracket(bracket);
            if (stack.peek() != expectedOpeningBracket) {
                return false;
            } else {
                stack.pop();
            }
        }
        return stack.empty();

    }

}
