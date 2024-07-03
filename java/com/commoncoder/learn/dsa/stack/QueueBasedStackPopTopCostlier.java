package com.commoncoder.learn.dsa.stack;

import java.util.LinkedList;
import java.util.Queue;

public class QueueBasedStackPopTopCostlier implements Stack {

    private Queue<Integer> queue = new LinkedList<>();

    // TC: O(1) SC: O(1)
    @Override
    public void push(Integer newVal) {
        queue.add(newVal);
    }

    // TC: O(N) SC: O(1)
    @Override
    public Integer poll() { // pop
       if (isEmpty()) {
           return null;
       }
        moveNElementsAtEnd(queue, size() - 1);
        return queue.poll();
    }

    // TC: O(N) SC: O(1)
    @Override
    public Integer top() {
        if (isEmpty()) {
            return null;
        }
        moveNElementsAtEnd(queue, size() - 1);
        int topValue = queue.peek();
        moveNElementsAtEnd(queue, 1);
        return topValue;
    }

    @Override
    public int size() {
        return queue.size();
    }

    @Override
    public boolean isEmpty() {
        return queue.isEmpty();
    }

    @Override
    public void print() {
        System.out.println(queue);
    }

    private void moveNElementsAtEnd(Queue<Integer> q, int n) {
        if (q.isEmpty() || q.size() == 1) {
            return;
        }
        n = n % q.size();
        while (n>0) {
            int val = q.poll();
            q.add(val);
            n--;
        }
    }
}
