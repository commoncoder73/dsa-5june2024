package com.commoncoder.learn.dsa.queue;

import java.util.ArrayList;

public class ArrayBasedQueue implements Queue {

    private ArrayList<Integer> qArray = new ArrayList<>();

    @Override
    public void push(int newVal) {
        qArray.add(newVal);
    }

    @Override
    public Integer poll() {
        Integer valToBePolled = peek();
        removeFirstElement(qArray);
        return valToBePolled;
    }

    @Override
    public Integer peek() {
        if (isEmpty()) {
            return null;
        }
        return qArray.get(0);
    }

    @Override
    public int size() {
        return qArray.size();
    }

    @Override
    public boolean isEmpty() {
        return qArray.isEmpty();
    }

    private void removeFirstElement(ArrayList<Integer> arr) {
        for (int i = 1; i < arr.size(); i++) {
            arr.set(i - 1, arr.get(i));
        }
        arr.remove(arr.size() - 1);
    }

}
