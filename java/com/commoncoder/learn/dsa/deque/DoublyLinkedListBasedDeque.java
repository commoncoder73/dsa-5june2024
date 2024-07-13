package com.commoncoder.learn.dsa.deque;

public class DoublyLinkedListBasedDeque implements Deque {

    private Node head;
    private Node tail;
    private int sizeValue = 0;

    @Override
    public void addFirst(int newVal) {
        addNewValueAtHead(newVal);
    }

    @Override
    public void addLast(int newVal) {
        addNewValueAtTail(newVal);
    }

    @Override
    public int peekFirst() {
        if (isEmpty()) {
            throw new RuntimeException("Deque is empty");
        }
        return head.data;
    }

    @Override
    public int peekLast() {
        if (isEmpty()) {
            throw new RuntimeException("Deque is empty");
        }
        return tail.data;
    }

    @Override
    public int pollFirst() {
        if (isEmpty()) {
            throw new RuntimeException("Deque is empty");
        }
        return removeValueFromHead().data;
    }

    @Override
    public int pollLast() {
        if (isEmpty()) {
            throw new RuntimeException("Deque is empty");
        }
        return removeValueFromTail().data;
    }

    @Override
    public int size() {
        return sizeValue;
    }

    @Override
    public boolean isEmpty() {
        return sizeValue == 0;
    }

    private static class Node {
        int data;
        Node next;
        Node prev;

        public Node(int data) {
            this.data = data;
        }

        public Node(int data, Node next, Node prev) {
            this.data = data;
            this.next = next;
            this.prev = prev;
        }
    }

    private void addNewValueAtHead(int newValue) {
        Node newNode = new Node(newValue);
        newNode.next = head;
        if (head == null) {
            this.tail = newNode;
        } else {
            head.prev = newNode;
        }
        this.head = newNode;
    }

    private void addNewValueAtTail(int newValue) {
        Node newNode = new Node(newValue);
        newNode.prev = tail;
        if (tail == null) {
            this.head = newNode;
        } else {
            tail.next = newNode;
        }
        this.tail = newNode;
    }

    private Node removeValueFromHead() {
        if (head == null) {
            return null;
        }
        Node nodeBeingDeleted = head;
        this.head = head.next;
        if (head == null) {
            this.tail = null;
        } else {
            head.prev = null;
        }
        return nodeBeingDeleted;
    }

    private Node removeValueFromTail() {
        if (tail == null) {
            return null;
        }
        Node nodeBeingDeleted = tail;
        this.tail = tail.prev;
        if (tail == null) {
            this.head = null;
        } else {
            tail.next = null;
        }
        return nodeBeingDeleted;
    }
}
