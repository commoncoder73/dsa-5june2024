package com.commoncoder.learn.dsa.stack;

import java.util.Stack;

public class MinStackUsingTwoStacks  {

    Stack<Integer> mainStack = new Stack<>();
    Stack<Integer> minStack = new Stack<>();

    public void push(Integer newVal) {
        mainStack.push(newVal);
        if (minStack.empty() || getMin() >= newVal) {
            minStack.push(newVal);
        }
    }

    public int getMin() {
        return minStack.peek(); // top
    }

    public Integer pop() { // pop
        Integer val = mainStack.pop();
        if (val == getMin()) {
            minStack.pop();
        }
        return val;
    }

    public Integer top() {
        return mainStack.peek();
    }

    public int size() {
        return mainStack.size();
    }

    public boolean isEmpty() {
        return mainStack.isEmpty();
    }

    public void print() {
        System.out.println(mainStack);
    }
}
