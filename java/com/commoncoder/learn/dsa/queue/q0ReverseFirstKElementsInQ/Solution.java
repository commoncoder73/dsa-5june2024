package com.commoncoder.learn.dsa.queue.q0ReverseFirstKElementsInQ;

import java.util.Queue;
import java.util.Stack;

// Remove values from queue and then add it in stack and then remove them from stack - order will be reversed
// Remove values from stack and add it to queue and then remove them - Same order

// 1 2 3 4 5 6 7 8 k =5
// [1]
    // 2 3 4 5 6 7 8 k = 4
    // [2]
        // 3 4 5 6 7 8 k = 3
        // [3]
            // 4 5 6 7 8 k = 2
            // ...

// 5 4 3 2 1  6 7 8
public class Solution {

    void reverse(Queue<Integer> queue, int k) {
        Stack<Integer> stack = new Stack<>();
        int i = 0;
        while (i < k) {
            stack.push(queue.poll());
            i++;
        }

        i = 0;
        while (i < k) {
            queue.add(stack.pop());
            i++;
        }

        moveNElementsAtEnd(queue, queue.size() - k);
    }

    void reverseRecursion(Queue<Integer> queue, int k) {
        if (k <= 1) {
            return;
        }
        reverseFirstKElementsAndAddThemAtEnd(queue, k);
        moveNElementsAtEnd(queue, queue.size() - k);
    }

    void reverseFirstKElementsAndAddThemAtEnd(Queue<Integer> queue, int k) {
        if (k <= 0) {
            return;
        }
        int firstValue = queue.poll();
        reverseFirstKElementsAndAddThemAtEnd(queue, k-1);
        queue.add(firstValue);
    }

    private void moveNElementsAtEnd(Queue<Integer> q, int n) {
        if (q.isEmpty() || q.size() == 1) {
            return;
        }
        n = n % q.size();
        while (n > 0) {
            int val = q.poll();
            q.add(val);
            n--;
        }
    }

}
