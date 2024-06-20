package com.commoncoder.learn.dsa.linkedlist.l1Basics;

public class SinglyLinkedListNode {

    private int data;
    private SinglyLinkedListNode next;

    SinglyLinkedListNode(int data) {
        this.data = data;
        // next is null
    }

    SinglyLinkedListNode(int data, SinglyLinkedListNode next) {
        this.data = data;
        this.next = next;
    }

    public int getData() {
        return data;
    }

    public SinglyLinkedListNode getNext() {
        return next;
    }

    public void setData(int data) {
        this.data = data;
    }

    public void setNext(SinglyLinkedListNode next) {
        this.next = next;
    }
}
