package com.commoncoder.learn.dsa.queue;

public interface Queue {

    void push(int newVal);

    Integer poll();

    Integer peek();

    int size();

    boolean isEmpty();

}
