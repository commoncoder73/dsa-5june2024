#include <bits/stdc++.h>

using namespace std;

class Deque {
 public:
  void addFirst(int value) {
    sizeValue++;
    Node* newNode = new Node(value);
    newNode->next = head;
    if (head == nullptr) {
      this->tail = newNode;
    }
    this->head = newNode;
  }

  void addLast(int value) {
    sizeValue++;
    Node* newNode = new Node(value);
    newNode->prev = tail;
    if (tail == nullptr) {
      this->head = newNode;
    }
    this->tail = newNode;
  }

  int pollFirst() {
    if (isEmpty()) {
      throw runtime_error("Deque is empty!");
    }
    sizeValue--;
    Node* nodeBeingDeleted = this->head;
    int valueBeingDeleted = nodeBeingDeleted->value;
    this->head = this->head->next;
    if (this->head == nullptr) {
      this->tail = nullptr;
    } else {
      this->head->prev = nullptr;
    }
    delete nodeBeingDeleted;
    return valueBeingDeleted;
  }

  int pollLast() {
    if (isEmpty()) {
      throw runtime_error("Deque is empty!");
    }
     sizeValue--;
    Node* nodeBeingDeleted = this->tail;
    int valueBeingDeleted = nodeBeingDeleted->value;
    this->tail = this->tail->prev;
    if (this->tail == nullptr) {
        this->head = nullptr;
    } else {
        this->tail->next = nullptr;
    }
    delete nodeBeingDeleted;
    return valueBeingDeleted;

  }

  int peekFirst() {
    if (isEmpty()) {
      throw runtime_error("Deque is empty!");
    }
    return head->value;
  }

  int peekLast() {
    if (isEmpty()) {
      throw runtime_error("Deque is empty!");
    }

    
    return tail->value;
  }

  int size() { return sizeValue; }

  bool isEmpty() { return sizeValue == 0; }

 private:
  class Node {
   public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
      this->value = value;
      this->prev = nullptr;
      this->next = nullptr;
    }

    Node(int value, Node* next, Node* prev) {
      this->value = value;
      this->prev = prev;
      ;
      this->next = next;
    }
  };

  Node* head = nullptr;
  Node* tail = nullptr;
  int sizeValue;


  unordered_map<int, string> um;
};