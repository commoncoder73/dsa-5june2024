package com.commoncoder.learn.dsa.queue;

public class LinkedListBasedQueue implements Queue {

    private static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
        }

        public Node(int data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    private Node head;
    private Node tail;
    private int sizeVal;

    // TC: O(1) SC: O(1)
    @Override
    public void push(int newVal) {
        addNewNodeAtTail(newVal);
    }

    // TC: O(1) SC: O(1)
    @Override
    public Integer poll() {
        return removeValueFromHead();
    }

    // TC: O(1) SC: O(1)
    @Override
    public Integer peek() {
        if (head == null) {
            return null;
        }
        return this.head.data;
    }

    // TC: O(1) SC: O(1)
    @Override
    public int size() {
        return sizeVal;
    }

    // TC: O(1) SC: O(1)
    @Override
    public boolean isEmpty() {
        return this.head == null;
    }

    private void addNewNodeAtTail(int newVal) {
        sizeVal++;
        Node newNode = new Node(newVal);
        // If linkedlist is currently empty
        if (head == null) {
            this.head = newNode;
            this.tail = newNode;
            return;
        }
        tail.next = newNode;
        this.tail = newNode;
    }

    private Integer removeValueFromHead() {
        if (head == null) {
            return null;
        }
        sizeVal--;
        Integer valueRemoved = head.data;
        this.head = head.next;
        // If linkedlist has been emptied
        if (head == null) {
            this.tail = null;
        }
        return valueRemoved;
    }
}
