package com.commoncoder.learn.dsa.queue;

import java.util.Stack;

public class SingleStackBasedQueuePollPeekCostlier implements Queue {

    private Stack<Integer> mainStack;

    // TC: O(1) SC: O(1)
    @Override
    public void push(int newVal) {
        mainStack.push(newVal);
    }

    // TC: O(N) SC: O(N)
    @Override
    public Integer poll() {
        if (isEmpty()) {
            return null;
        }
        return removeBottomElement(mainStack);
    }

    // TC: O(N) SC: O(N)
    @Override
    public Integer peek() {
        if (isEmpty()) {
            return null;
        }
        return getBottomElement(mainStack);

    }

    @Override
    public int size() {
        return mainStack.size();
    }

    @Override
    public boolean isEmpty() {
        return mainStack.isEmpty();
    }

    private int getBottomElement(Stack<Integer> stack) {
        if (stack.size() == 1) {
            return stack.peek();
        }
        int topValue = stack.pop();
        int bottomValue = getBottomElement(stack);
        stack.push(topValue);
        return bottomValue;
    }

    private int removeBottomElement(Stack<Integer> stack) {
        if (stack.size() == 1) {
            return stack.pop();
        }
        int topValue = stack.pop();
        int bottomRemovedValue = removeBottomElement(stack);
        stack.push(topValue);
        return bottomRemovedValue;
    }
}
