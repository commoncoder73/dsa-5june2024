#include <bits/stdc++.h>

using namespace std;

class Stack {

    Stack() {
        this->head = nullptr;
        this->sizeVal = 0;
    }

public:
    // 5->4->2->3 
    void push(int val) {
        sizeVal++;
        insertNewValAtHead(val);
    }

    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty!");
        }
        sizeVal--;
        return *removeFirstNode();
    }

    int top() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty!");
        }
        head->data;
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
    int sizeVal;

    void insertNewValAtHead(int newVal) {
        Node* newNode = new Node(newVal);
        if (head == nullptr) {
            this->head = newNode;
            return;
        }
        newNode->next = head;
        this->head = newNode;
    }

        // 4->2->3 
    int* removeFirstNode() {
        if (head == nullptr) {
            return nullptr;
        }
        Node* nodeToDelete = head;
        this->head = this->head->next;
        int valDeleted = nodeToDelete->data;
        delete nodeToDelete;
        return &valDeleted;
        
    }
    
};