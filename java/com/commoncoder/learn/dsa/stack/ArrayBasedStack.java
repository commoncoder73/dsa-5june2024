package com.commoncoder.learn.dsa.stack;

import java.util.ArrayList;

public class ArrayBasedStack implements Stack {

    private ArrayList<Integer> stackArray = new ArrayList<>();


    // TC: O(1)
    // SC: O(1)
    // In a loop running n times you do push for n times
        // TC: O(n)
        // SC: O(n)
    @Override
    public void push(Integer newVal) {
        this.stackArray.add(newVal);
    }

    // TC: O(1)
    // SC: O(1)
    // In a loop running n times you do poll for n times
        // TC: O(n)
        // SC: O(1)
    @Override
    public Integer poll() {
        if (isEmpty()) {
            return null;
        }
        return stackArray.remove(size() - 1);
    }

    // TC: O(1)
    // SC: O(1)
    // In a loop running n times you do top for n times
        // TC: O(n)
        // SC: O(1)
    @Override
    public Integer top() {
        if (isEmpty()) {
            return null;
        }
        return stackArray.get(size() - 1);
    }

    // TC: O(1)
    // SC: O(1)
    // In a loop running n times you do size for n times
        // TC: O(n)
        // SC: O(1)
    @Override
    public int size() {
        return stackArray.size();
    }

    // TC: O(1)
    // SC: O(1)
    // In a loop running n times you do isEmpty for n times
        // TC: O(n)
        // SC: O(1)
    @Override
    public boolean isEmpty() {
        return stackArray.isEmpty();
    }

    @Override
    public void print() {
        for(int i=stackArray.size()-1; i>=0; i--) {
            System.out.println(stackArray.get(i));
        }
        System.out.println("---------");
    }
}
