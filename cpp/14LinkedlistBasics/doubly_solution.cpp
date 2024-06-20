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