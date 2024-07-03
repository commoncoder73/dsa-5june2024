package com.commoncoder.learn.dsa.queue;

public class PriorityQueue {

    private Node head = null;
    private int sizeVal = 0;


    // TC: O(N) SC: O(1)
    public void push(Value value) {
        sizeVal++;
        insertValueBasedOnHigherPriority(value);
    }

    // TC: O(1) SC: O(1)
    public Value poll() {
        if (isEmpty()) {
            throw new RuntimeException("PQ is empty!");
        }
        sizeVal--;
        return removeValueFromHead();
    }

    //TC: O(1) SC: O(1)
    public Value peek() {
        if (isEmpty()) {
            throw new RuntimeException("PQ is empty!");
        }
        return head.value;
    }

    public int size() {
        return sizeVal;
    }

    public boolean isEmpty() {
        return head == null;
    }

    public static class Value {
        int data;
        int priority;

        public Value(int data, int priority) {
            this.data = data;
            this.priority = priority;
        }
    }

    private static class Node {
        Value value;
        Node next;

        public Node(Value value) {
            this.value = value;
        }

        public Node(Value value, Node next) {
            this.value = value;
            this.next = next;
        }
    }

    // TC: O(N) SC: O(1)
    private void insertValueBasedOnHigherPriority(Value newValue) {
        Node temp = head;
        Node prev = null;

        while (temp != null && temp.value.priority >= newValue.priority) {
            prev = temp;
            temp = temp.next;
        }
        Node newNode = new Node(newValue);
        newNode.next = temp;
        if (prev == null) {
            this.head = newNode;
        } else {
            prev.next = newNode;
        }

    }

    private Value removeValueFromHead() {
        if (head == null) {
            return null;
        }

        Value valueRemoved = head.value;
        this.head = head.next;
        return valueRemoved;
    }
}
