package com.commoncoder.learn.dsa.stack;

public class LinkedListBasedStack implements Stack {

    private static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }

        Node(int data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    private Node head = null;
    private int size = 0;

    private void insertAtHead(int newVal) {
        this.size++;
        Node newNode = new Node(newVal);
        if (this.head == null) {
            this.head = newNode;
            return;
        }
        newNode.next = head;
        this.head = newNode;
    }

    private Node removeFromHead() {
        this.size--;
        if (this.head == null) {
            return null;
        }
        Node nodeToDelete = this.head;
        this.head = this.head.next;
        return nodeToDelete;
    }

    @Override
    public void push(Integer newVal) {
        insertAtHead(newVal);
    }

    @Override
    public Integer poll() {
        Node nodeDeleted = removeFromHead();
        if (nodeDeleted == null) {
            return null;
        }
        return nodeDeleted.data;
    }

    @Override
    public Integer top() {
        if (this.head == null) {
            return null;
        }
        return this.head.data;
    }

    // TC: O(1)
    @Override
    public int size() {
        return this.size;
    }

    @Override
    public boolean isEmpty() {
        return this.head == null;

    }

    @Override
    public void print() {
        Node temp = this.head;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
        System.out.println("---------");
    }
}
