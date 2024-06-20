package com.commoncoder.learn.dsa.linkedlist.l1Basics;

public class DoublyLinkedListNode {

    private int data;
    private DoublyLinkedListNode next;
    private DoublyLinkedListNode prev;

    DoublyLinkedListNode(int data) {
        this.data = data;
        // next is null
        // prev is null
    }

    DoublyLinkedListNode(int data, DoublyLinkedListNode next, DoublyLinkedListNode prev) {
        this.data = data;
        this.next = next;
        this.prev = prev;
    }

    public int getData() {
        return data;
    }

    public DoublyLinkedListNode getNext() {
        return next;
    }

    public void setData(int data) {
        this.data = data;
    }

    public void setNext(DoublyLinkedListNode next) {
        this.next = next;
    }

    public DoublyLinkedListNode getPrev() {
        return prev;
    }

    public void setPrev(DoublyLinkedListNode prev) {
        this.prev = prev;
    }
}
