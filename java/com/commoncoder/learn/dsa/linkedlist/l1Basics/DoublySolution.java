package com.commoncoder.learn.dsa.linkedlist.l1Basics;

public class DoublySolution {

    // TC: O(1) Sc: O(1)
    public DoublyLinkedListNode insertNodeAtStart(
            DoublyLinkedListNode head,
            int valToInsert
    ) {
        DoublyLinkedListNode newNode = new DoublyLinkedListNode(valToInsert);
        if (head != null) {
            newNode.setNext(head);
            head.setPrev(newNode);
        }
        return newNode;
    }

    public DoublyLinkedListNode insertNodeAtEnd(
            DoublyLinkedListNode head,
            int valToInsert
    ) {
        DoublyLinkedListNode newNode = new DoublyLinkedListNode(valToInsert);
        if (head == null) {
            return newNode;
        }
        DoublyLinkedListNode temp = head;
        while (temp.getNext() != null) {
            temp = temp.getNext();
        }
        temp.setNext(newNode); // temp.next = newNode
        newNode.setPrev(temp); // newNode.prev = temp
        return head;
    }

    public DoublyLinkedListNode insertNodeAtK(
            DoublyLinkedListNode head,
            int valToInsert,
            int k
    ) {
        if (k == 0) {
            return insertNodeAtStart(head, valToInsert);
        }
        DoublyLinkedListNode temp = head;
        while (k > 1) {
            temp = temp.getNext();
            k--;
        }
        DoublyLinkedListNode newNode = new DoublyLinkedListNode(valToInsert);
        newNode.setNext(temp.getNext());
        newNode.setPrev(temp);
        if (temp.getNext() != null) {
            temp.getNext().setPrev(newNode);
        }
        temp.setNext(newNode);
        return head;
    }

    public DoublyLinkedListNode deleteAtStart(
            DoublyLinkedListNode head
    ) {
        if (head == null) {
            return null;
        }
        head = head.getNext();

        if (head == null) {
            return head;
        }
        head.setPrev(null);
        return head;
    }

    public DoublyLinkedListNode deleteAtEnd(
            DoublyLinkedListNode head
    ) {
        if (head == null) {
            return head;
        }
        DoublyLinkedListNode temp = head;
        while (temp.getNext() != null) {
            temp = temp.getNext();
        }
        if (temp.getPrev() == null) {
            return null;
        }
        temp.getPrev().setNext(null);
        return head;
    }

    // assume 0<=k<n
    public DoublyLinkedListNode deleteAtK(
            DoublyLinkedListNode head,
            int k
    ) {
        if (head == null) {
            return head;
        }

        DoublyLinkedListNode temp = head;
        while (k > 0) {
            temp = temp.getNext();
            k--;
        }

        if (temp.getPrev() != null) {
            temp.getPrev().setNext(temp.getNext());
        } else {
            head = temp.getNext();
        }
        if (temp.getNext() != null) {
            temp.getNext().setPrev(temp.getPrev());
        }
        return head;
    }

    public DoublyLinkedListNode reverse(DoublyLinkedListNode head) {
        DoublyLinkedListNode iteratingPointer = head;
        DoublyLinkedListNode newHead = null;
        while (iteratingPointer != null) {
            if (iteratingPointer.getNext() == null) {
                newHead = iteratingPointer;
            }
            /**
             * temp = a
             * a = b
             * b = temp
             */
            DoublyLinkedListNode swapTemp = iteratingPointer.getNext();
            iteratingPointer.setNext(iteratingPointer.getPrev());
            iteratingPointer.setPrev(swapTemp);
            iteratingPointer = iteratingPointer.getPrev();
        }
        return newHead;
    }






}












