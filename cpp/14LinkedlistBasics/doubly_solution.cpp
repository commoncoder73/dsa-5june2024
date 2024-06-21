#include <bits/stdc++.h>

using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int data, Node *next, Node* prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

// TC: O(1)
// SC: O(1)
Node* addNewNodeAtStart(Node* head, int dataToAdd) {
    Node* newNode = new Node(dataToAdd);
    // if (head == nullptr) {
    //     return newNode;
    // }
    newNode->next = head;
    if (head != nullptr ) {
        head->prev = newNode;
    }
    return newNode;
}

// TC: O(N) SC: O(1)
Node* addNewNodeAtEnd(Node* head, int dataToAdd) {
     Node* newNode = new Node(dataToAdd);
     if (head == nullptr)
     {
         return newNode;
     }
     Node* temp = head;
     while(temp->next != nullptr) {
        temp = temp->next;
     }
     temp->next = newNode;
     newNode->prev = temp;
     return head;
}

// TC: O(N) SC: O(1)
Node* addNewNodeAtK(Node* head, int dataToAdd, int k) {
    if (k == 0) {
        return addNewNodeAtStart(head, dataToAdd);
    }

    Node* temp = head;
    while(k > 1) {
        temp = temp->next;
        k--;
    }

    Node* newNode = new Node(dataToAdd);
    newNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;

}
// if head is given, head will change if new node is added at start
// if last is given, last will change if new node is added at end


// TC: O(1) SC: O(1)
Node* deleteNodeAtStart(Node* head) {
    Node* newHead = head->next;
    // If there exists new head and it is not the scenario where there 
    // was only single node
    if (newHead != nullptr) {
        newHead->prev = nullptr;
    }
    delete head;
    return newHead;
}

// TC: O(N) SC: O(1)
Node* deleteNodeAtEnd(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }

    // only single node
    if (temp->prev == nullptr) {
        delete temp;
        return nullptr;
    } else {
        temp->prev->next = nullptr;
        delete temp;
    }
    return head;
}

// TC: O(N) SC: O(1)
Node* deleteNodeAtK(Node* head, int k) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    while(k > 0) {
        temp = temp->next;
        k--;
    }

    // first node
    if (temp->prev == nullptr) {
        head = temp->next;
    } else {
        temp->prev->next = temp->next;
    }

    //if not last node
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    return head;
}

// TC: O(N) SC: O(1)
Node* reverse(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    while(temp != nullptr) {
        if (temp->next == nullptr) {
            head = temp;
        }
        Node* swapTemp = temp->next;
        temp->next = temp->prev;
        temp->prev = swapTemp;

        temp = temp->prev;
    }
    return head;
    
}