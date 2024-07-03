package com.commoncoder.learn.dsa.queue;

public class ArrayBasedBoundedQueue implements Queue {

    private int[] qArray;
    private int last = -1;
    private int first = 0;
    private int capacity;
    int length = 0;

    public ArrayBasedBoundedQueue(int capacity) {
        this.qArray = new int[capacity];
        this.capacity = capacity;
    }

    @Override
    public void push(int newVal) {
        if (isFull()) {
            throw new RuntimeException("Queue is full");
        }
        last = (last + 1) % capacity;
    }

    @Override
    public Integer poll() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        int firstValue = peek();
        length--;
        first = (first + 1) % capacity;
        return firstValue;
    }

    @Override
    public Integer peek() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        return qArray[first];
    }

    @Override
    public int size() {
        return length;
    }

    @Override
    public boolean isEmpty() {
        return length == 0;
    }

    public boolean isFull() {
        return (last + 1) % capacity == first;
    }

    private boolean onlySingleElementInQ() {
        return last == first;
    }


}
