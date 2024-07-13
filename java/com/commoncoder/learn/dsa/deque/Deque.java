package com.commoncoder.learn.dsa.deque;

public interface Deque {

    void addFirst(int newVal);

    void addLast(int newVal);

    int peekFirst();

    int peekLast();

    int pollFirst();

    int pollLast();

    int size();

    boolean isEmpty();

}
