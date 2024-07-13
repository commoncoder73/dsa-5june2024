#include <bits/stdc++.h>

using namespace std;

// This sample priority queue solution respects higher priority i.e.
// higher priority elements gets polled before lower priority elements.

// 10
//  3 3 3 2 [2]<---->[1] 1 1 1 1 1
class PriorityQueue {
 public:
  void push(int value, int priority) {
    sizeValue++;
    insertNewNodeAsPerPriority(value, priority);
  }

  int poll() {
    if (isEmpty()) {
      throw runtime_error("PQ is empty!");
    }
    sizeValue--;
    return *removeFirstNode();
  }

  int peek() {
    if (isEmpty()) {
      throw runtime_error("PQ is empty!");
    }
    return this->head->value;
  }

  int size() { return sizeValue; }

  bool isEmpty() { return head == nullptr; }

 private:
  class Node {
   public:
    int value;
    int priority;
    Node* next;

    Node(int value, int priority) {
      this->value = value;
      this->priority = priority;
      this->next = nullptr;
    }

    Node(int value, int priority, Node* next) {
      this->value = value;
      this->priority = priority;
      this->next = next;
    }
  };

  void insertNewNodeAsPerPriority(int value, int priority) {
    Node* newNode = new Node(value, priority);
    Node* prev = nullptr;
    Node* temp = head;
    while (temp != nullptr && temp->priority >= priority) {
      prev = temp;
      temp = temp->next;
    }
    newNode->next = temp;

    if (prev == nullptr) {
      this->head = newNode;
    } else {
      prev->next = newNode;
    }
  }

  int* removeFirstNode() {
    if (head == nullptr) {
      return nullptr;
    }
    Node* nodeToDelete = head;
    this->head = this->head->next;
    int valDeleted = nodeToDelete->value;
    delete nodeToDelete;
    return &valDeleted;
  }

  Node* head;
  int sizeValue = 0;
};