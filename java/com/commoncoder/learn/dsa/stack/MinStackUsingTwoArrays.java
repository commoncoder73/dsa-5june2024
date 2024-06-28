package com.commoncoder.learn.dsa.stack;

import java.util.ArrayList;

public class MinStackUsingTwoArrays {

    private ArrayList<Integer> mainStack = new ArrayList<>();
    private ArrayList<Integer> minStack = new ArrayList<>();


    public void push(Integer newVal) {
        mainStack.add(newVal);
        if (minStack.isEmpty() || getMin() >= newVal) {
            minStack.add(newVal);
        }
    }

    public int getMin() {
        return minStack.get(minStack.size() - 1);
    }

    public Integer pop() { // pop
        int val = mainStack.remove(mainStack.size() - 1);
        if (val == getMin()) {
            minStack.remove(minStack.size() - 1);
        }
        return val;
    }

    public Integer top() {
        return mainStack.get(mainStack.size() - 1);
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
