package com.commoncoder.learn.dsa.deque.dq0MinMaxQueue;


import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

public class MinMaxQueue {

    private Queue<Integer> mainQueue = new LinkedList<>();
    private Deque<Integer> maxTrackingDeque = new ArrayDeque<>();
    private Deque<Integer> minTrackingDeque = new ArrayDeque<>();

    public void push(int newVal) {
        while (!maxTrackingDeque.isEmpty() && maxTrackingDeque.peekLast() < newVal) {
            maxTrackingDeque.pollLast();
        }
        maxTrackingDeque.addLast(newVal);

        while (!minTrackingDeque.isEmpty() && minTrackingDeque.peekLast() > newVal) {
            minTrackingDeque.pollLast();
        }
        minTrackingDeque.addLast(newVal);

        mainQueue.add(newVal);
    }

    public int poll() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        int valueBeingPolled = peek();
        if (valueBeingPolled == getMax()) {
            maxTrackingDeque.pollFirst();
        }
        if (valueBeingPolled == getMin()) {
            minTrackingDeque.pollFirst();
        }
        mainQueue.poll();
        return valueBeingPolled;
    }

    public int peek() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        return mainQueue.peek();
    }

    public int getMin() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        return minTrackingDeque.peekFirst();
    }

    public int getMax() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        return maxTrackingDeque.peekFirst();
    }

    public int size() {
        return mainQueue.size();
    }

    public boolean isEmpty() {
        return mainQueue.isEmpty();
    }
    
}
