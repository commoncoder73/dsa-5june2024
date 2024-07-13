#include <bits/stdc++.h>

using namespace std;

class Queue {

    Queue() {
        this->head = nullptr;
        this->tail = nullptr;
        this->sizeVal = 0;
    }

public:
    
    void push(int val) {
        sizeVal++;
        addNewNodeAtEnd(val);
    }

    int poll() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty!");
        }
        sizeVal--;
        return *removeFirstNode();
    }

    int peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty!");
        }
        return head->data;
    }

    int size() {
        return sizeVal;
    }

    bool isEmpty() {
        return head == nullptr;
    }

private:
    class Node{

    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }

        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }

    };
    
    Node* head;
    Node* tail;
    int sizeVal;

    

    int* removeFirstNode() {
        if (head == nullptr) {
            return nullptr;
        }
        Node* nodeToDelete = head;
        this->head = this->head->next;
        if (head == nullptr) {
            this->tail = nullptr;
        }
        int valDeleted = nodeToDelete->data;
        delete nodeToDelete;
        return &valDeleted;
        
    }

    void addNewNodeAtEnd(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            this->head = newNode;
            this->tail = newNode;
            return;
        }
        tail->next = newNode;
        this->tail = newNode;
    }
    
};