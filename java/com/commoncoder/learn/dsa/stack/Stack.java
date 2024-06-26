package com.commoncoder.learn.dsa.stack;

public interface Stack {

    void push(Integer newVal);

    Integer poll();

    Integer top();

    int size();

    boolean isEmpty();

    // This is just for testing
    void print();

}
