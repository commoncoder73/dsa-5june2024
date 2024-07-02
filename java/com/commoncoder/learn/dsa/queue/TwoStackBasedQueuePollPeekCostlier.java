package com.commoncoder.learn.dsa.queue;

import java.util.Stack;

public class TwoStackBasedQueuePollPeekCostlier implements Queue {

    private Stack<Integer> mainStack;
    private Stack<Integer> intermediateStack;

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
        moveAllElementsToOtherStack();
        Integer elementPolled = intermediateStack.pop();
        moveBackAllElementsToMainStack();
        return elementPolled;
    }

    // TC: O(N) SC: O(N)
    @Override
    public Integer peek() {
        if (isEmpty()) {
            return null;
        }
        moveAllElementsToOtherStack();
        Integer first = intermediateStack.peek();
        moveBackAllElementsToMainStack();
        return first;
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
