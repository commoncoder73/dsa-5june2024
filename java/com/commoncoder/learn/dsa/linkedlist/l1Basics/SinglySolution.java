package com.commoncoder.learn.dsa.linkedlist.l1Basics;

public class SinglySolution {

    public static void main(String[] args) {
        SinglySolution solution = new SinglySolution();
        SinglyLinkedListNode head = null;
//        head = solution.insertAtBeg(null, 6);
        head = solution.insertAtBeg(head, 5);
        head = solution.insertAtBeg(head, 4);
        head = solution.insertAtBeg(head, 3);
        head = solution.insertAtBeg(head, 2);
        head = solution.insertAtBeg(head, 1);

        solution.traversal(head);
        System.out.println("---");
        solution.alternateNodes(head);
        solution.traversal(head);
    }

    public void traversal(SinglyLinkedListNode head) {
        SinglyLinkedListNode temp = head;
        while (temp != null) {
            System.out.println(temp.getData());
            temp = temp.getNext();
        }
    }

    // TC: O(N)
    // SC: O(1)
    public int length(SinglyLinkedListNode head) {
        int count = 0;
        SinglyLinkedListNode temp = head;
        while (temp != null) {
            count++;
            temp = temp.getNext();
        }
        return count;
    }

    public SinglyLinkedListNode insertAtBeg(SinglyLinkedListNode head, int valToInsert) {
        SinglyLinkedListNode newNode = new SinglyLinkedListNode(valToInsert);
        newNode.setNext(head);
        return newNode;
    }

    public SinglyLinkedListNode insertAtEnd(SinglyLinkedListNode head, int valToInsert) {
        SinglyLinkedListNode newNode = new SinglyLinkedListNode(valToInsert);
        if (head == null) {
            return newNode;
        }
        SinglyLinkedListNode temp = head;
        while (temp.getNext() != null) {
            temp = temp.getNext();
        }
        temp.setNext(newNode);
        return head;
    }

    public SinglyLinkedListNode linearSearch(SinglyLinkedListNode head, int valToSearch) {
        while (head != null) {
            if (head.getData() == valToSearch) {
                return head;
            }
        }
        return null;
    }

    public SinglyLinkedListNode insert(
            SinglyLinkedListNode head, int valToInsert, int k
    ) {
        if (k == 0) {
            return insertAtBeg(head, valToInsert);
        }
        SinglyLinkedListNode prev = head;
        SinglyLinkedListNode temp = head;
        while (k > 0) {
            prev = temp;
            temp = temp.getNext();
            k--;
        }
        SinglyLinkedListNode newNode = new SinglyLinkedListNode(valToInsert);
        newNode.setNext(temp);
        prev.setNext(newNode);
        return head;
    }

    public SinglyLinkedListNode deleteFromStart(SinglyLinkedListNode head) {
        if (head == null) {
            return null;
        }
        return head.getNext();
    }

    // head -> [] -> []
    public SinglyLinkedListNode deleteFromEnd(SinglyLinkedListNode head) {
        if (head == null || head.getNext() == null) {
            return null;
        }
//        LinkedListNode temp = head;
//        while (temp.getNext().getNext() != null) {
//            temp = temp.getNext();
//        }
//        temp.setNext(null);
//        return head;
        SinglyLinkedListNode prev = null;
        SinglyLinkedListNode temp = head;
        while (temp.getNext() != null) {
            prev = temp;
            temp = temp.getNext();
        }
        prev.setNext(null);
        return head;
    }

    // head -> [ /]

    public SinglyLinkedListNode deleteKthNode(SinglyLinkedListNode head, int k) {
        // check for validity of k (0<=k<n)
        if (head == null) {
            return null;
        }
        if (k == 0) {
            return deleteFromStart(head);
        }
        SinglyLinkedListNode prev = null;
        SinglyLinkedListNode temp = head;
        while (k > 0) {
            prev = temp;
            temp = temp.getNext();
            k--;
        }
        prev.setNext(temp.getNext());
        return head;
    }

    public boolean isLinkedListCircular(SinglyLinkedListNode head) {
        SinglyLinkedListNode slow = head;
        SinglyLinkedListNode fast = head;
        while (fast != null && fast.getNext() != null) {
            slow = slow.getNext();
            fast = fast.getNext().getNext();
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    public SinglyLinkedListNode cyclePoint(SinglyLinkedListNode head) {
        SinglyLinkedListNode slow = head;
        SinglyLinkedListNode fast = head;
        while (fast != null && fast.getNext() != null) {
            slow = slow.getNext();
            fast = fast.getNext().getNext();
            if (slow == fast) {
                break;
            }
        }
        if (fast == null || fast.getNext() == null) {
            return null;
        }

        slow = head;
        while (slow != fast) {
            slow = slow.getNext();
            fast = fast.getNext();
        }
        return slow;
    }

    public SinglyLinkedListNode middleNode(SinglyLinkedListNode head) {
        SinglyLinkedListNode slow = head;
        SinglyLinkedListNode fast = head;
        while (fast != null && fast.getNext() != null) {
            slow = slow.getNext();
            fast = fast.getNext().getNext();
        }
        return slow;
    }

    // TC: O(N) SC: O(1)
    public SinglyLinkedListNode reverse(SinglyLinkedListNode head) {
        SinglyLinkedListNode prev = null;
        SinglyLinkedListNode curr = head;
        SinglyLinkedListNode next;
        // null  <-[]<-[] <-[p] c/n null
        while (curr != null) {
            next = curr.getNext();
            curr.setNext(prev);
            prev = curr;
            curr = next;
        }
        return prev; // new head
    }

    public boolean isPalindrome(SinglyLinkedListNode head) {
        if (head == null) {
            return true;
        }
        SinglyLinkedListNode middle = middleNode(head);
        SinglyLinkedListNode middleHeadOriginal = reverse(middle);
        SinglyLinkedListNode middleHead = middleHeadOriginal;
        while (head != middle) {
            if (middleHead.getData() != head.getData()) {
                return false;
            }
            middleHead = middleHead.getNext();
            head = head.getNext();
        }
        reverse(middleHeadOriginal);
        return true;
    }

    public SinglyLinkedListNode addOne(SinglyLinkedListNode head) {
        head = reverse(head);
        // now we have units tens hund thous...
        int carry = 1;
        SinglyLinkedListNode temp = head;
        while (carry != 0 && temp != null) {
            int sum = temp.getData() + carry; // 1 to 10
            temp.setData(sum % 10);
            carry = sum / 10;
            temp = temp.getNext();
        }
        // we had to add carry at the end
        head = reverse(head); // 0 0 0 0 0
        // adding 1 at beginning
        if (carry == 1) {
            return insertAtBeg(head, 1);
        }
        return head;
    }


    SinglyLinkedListNode insertInSortedLinkedList(SinglyLinkedListNode head, int valToInsert) {
        SinglyLinkedListNode prev = null;
        SinglyLinkedListNode temp = head;
        // while we move out of linkedlist or we find just greater or equal element
        while (temp != null && temp.getData() < valToInsert) {
            prev = temp;
            temp = temp.getNext();
        }

        SinglyLinkedListNode newNode = new SinglyLinkedListNode(valToInsert);
        // Is this first node to be inserted
        if (prev == null) {
            head = newNode;
        } else {
            prev.setNext(newNode);
        }
        newNode.setNext(temp);
        return head;
    }


    void removeDuplicatesFromSortedArray(SinglyLinkedListNode head) {
        SinglyLinkedListNode temp = head;
        while (temp != null && temp.getNext() != null) {
            if (temp.getData() == temp.getNext().getData()) {
                temp.setNext(temp.getNext().getNext());
            } else {
                temp = temp.getNext();
            }
        }
    }


    void alternateNodes(SinglyLinkedListNode head) {
        SinglyLinkedListNode mid = middleNode(head);
        SinglyLinkedListNode t2 = reverse(mid);
        SinglyLinkedListNode t1 = head;
        while (t1 != t2 && t1.getNext() != t2) {
            SinglyLinkedListNode t1Next = t1.getNext();
            t1.setNext(t2);
            t2 = t2.getNext();
            t1 = t1.getNext();
            t1.setNext(t1Next);
            t1 = t1Next;
        }
    }

}


/**
 * Given a sorted linked list and a new value,
 * insert new value such that final linked list remains sorted.
 * <p>
 * Given a sorted linked list, remove all duplicates.
 * <p>
 * Given a linked list and a value, delete all nodes of that value.
 * <p>
 * <p>
 * <p>
 * Comparison with array | singly linkedlist
 * <p>
 * Getting nth value O(1) | O(N)
 * Adding new value at end  O(1) (assuming enough space) | O(N)
 * Adding new value at beginning O(N) | O(1)
 * Adding new value in between  (N) | O(N)
 * <p>
 * Delete new value at end O(1) | O(N)
 * Delete new value at beginning O(N) | O(1)
 * Delete new value in between O(N) | O(N)
 * <p>
 * Linear Search O(N) | O(N)
 */

/**
 * Comparison with array | singly linkedlist
 *
 * Getting nth value O(1) | O(N)
 * Adding new value at end  O(1) (assuming enough space) | O(N)
 * Adding new value at beginning O(N) | O(1)
 * Adding new value in between  (N) | O(N)
 *
 * Delete new value at end O(1) | O(N)
 * Delete new value at beginning O(N) | O(1)
 * Delete new value in between O(N) | O(N)
 *
 * Linear Search O(N) | O(N)
 *
 */
