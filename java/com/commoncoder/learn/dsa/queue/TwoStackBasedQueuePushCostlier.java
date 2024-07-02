package com.commoncoder.learn.dsa.queue;

import java.util.Stack;

public class TwoStackBasedQueuePushCostlier implements Queue {

    private Stack<Integer> mainStack;
    private Stack<Integer> intermediateStack;

    // TC: O(N) SC: O(N)
    @Override
    public void push(int newVal) {
        moveAllElementsToOtherStack();
        mainStack.push(newVal);
        moveBackAllElementsToMainStack();
    }

    // TC: O(1) SC: O(1)
    @Override
    public Integer poll() {
        if (isEmpty()) {
            return null;
        }
        return mainStack.pop();
    }

    // TC: O(1) SC: O(1)
    @Override
    public Integer peek() {
        if (isEmpty()) {
            return null;
        }
        return mainStack.peek();
    }

    @Override
    public int size() {
        return mainStack.size();
    }

    @Override
    public boolean isEmpty() {
        return mainStack.isEmpty();
    }

    private void moveAllElementsToOtherStack() {
        while (!mainStack.empty()) {
            intermediateStack.push(
                    mainStack.pop()
            );
        }
    }

    private void moveBackAllElementsToMainStack() {
        while (!intermediateStack.empty()) {
            mainStack.push(
                    intermediateStack.pop()
            );
        }
    }

}
