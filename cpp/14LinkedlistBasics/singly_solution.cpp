#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int data;
  Node *next;

  Node() {
    this->data = 0;
    this->next = nullptr;
  }

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }

  Node(int data, Node *next) {
    this->data = data;
    this->next = next;
  }
};

void printLinkedlist(Node *head) {
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// TC: O(1)
// SC: O(1)
//----
// array TC: O(N) SC(1)
Node *addNewNodeAtStart(Node *head, int valToAdd) {
  Node *newNode = new Node(valToAdd);
  newNode->next = head;
  return newNode;
}

// TC: O(N)
// SC: O(1)
//----
// array TC: O(1) SC(1)
Node *addNewNodeAtEnd(Node *head, int valToAdd) {
  Node *newNode = new Node(valToAdd);
  if (head == nullptr) {
    return newNode;
  }
  Node *temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

// TC: O(N)
// SC: O(1)
//-----
// array TC: O(N) SC(1)
Node *addNewNodeAtK(Node *head, int k, int valToAdd) {
  if (k == 0) {
    return addNewNodeAtStart(head, k);
  }
  Node *temp = head;
  while (k > 1) {
    k--;
    temp = temp->next;
  }
  Node *newNode = new Node(valToAdd);
  newNode->next = temp->next;
  temp->next = newNode;
  return head;
}

// TC: O(N)
// SC: O(1)
//----
// array TC: O(N) SC(1)
Node *linearSearch(Node *head, int valToSearch) {
  while (head != nullptr) {
    if (head->data == valToSearch) {
      return head;
    }
    head = head->next;
  }
  return nullptr;
}

// TC: O(N)
// SC: O(1)
//----
// array TC: O(1) SC(1)
Node *nodeAt(Node *head, int k) {
  Node *temp = head;
  while (temp != nullptr || k > 0) {
    temp = temp->next;
    k--;
  }
  return temp;
}

// TC: O(1)
// SC: O(1)
//----
// array TC: O(N) SC(1)
Node *deleteFirstNode(Node *head) {
  if (head == nullptr) {
    return head;
  }
  Node *temp = head->next;
  head->next = nullptr;
  delete head;
  return temp;
}

// TC: O(N)
// SC: O(1)
//----
// array TC: O(1) SC(1)
Node *deleteLastNode(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return nullptr;
  }
  Node *temp = head;
  while (temp->next->next != nullptr) {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = nullptr;
  return head;
}

// TC: O(N)
// SC: O(1)
//----
// array TC: O(N) SC(1)
// assuming k is valid i.e. 0<=k<n
Node *deleteKthNode(Node *head, int k) {
  if (head == nullptr) {
    return nullptr;
  }
  if (k == 0) {
    return deleteFirstNode(head);
  }
  Node *temp = head;
  while (k > 1) {
    temp = temp->next;
    k--;
  }

  // []->[]->[]->[temp]->[]->[]->[]->null
  Node *nodeToDelete = temp->next;
  temp->next = nodeToDelete->next;  // temp->next->next; (same)
  delete nodeToDelete;
  return head;
}

// TC: O(N) SC: O(1)
Node *reverseLinkedList(Node *head) {
  Node *prev = nullptr;
  Node *cur = head;
  while (cur != nullptr) {
    Node *next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

int countNodes(Node *head) {
  if (head == nullptr) {
    return 0;
  }
  Node *temp = head;
  int count = 1;
  while (temp != nullptr) {
    count++;
    temp = temp->next;
  }
  return count;
}

// [2]->[1]->[0]->[]->[ \]
// n 5 -> 5/2 -> 2 times
// TC: O(N) SC: O(1)
Node *middleNodeTwoTraversal(Node *head) {
  int n = countNodes(head);
  int countTillMiddleNode = n / 2;
  Node *temp = head;
  while (countTillMiddleNode > 0) {
    temp = temp->next;
    countTillMiddleNode--;
  }
  return temp;
}

// TC: O(N) SC: O(1)
Node *middleNodeFastAndSlowPtr(Node *head) {
  Node *slow = head;
  Node *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

bool isCircularLinkedList(Node *head) {
  Node *slow = head;
  Node *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}

Node *getCycleStartNode(Node *head) {
  Node *slow = head;
  Node *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      break;
    }
  }
  if (fast == nullptr || fast->next == nullptr) {
    return nullptr;
  }
  slow = head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

Node *addOneToNumber(Node *head) {
  head = reverseLinkedList(head);

  Node *temp = head;
  int toAdd = 1;
  while (temp != nullptr && toAdd > 0) {
    int sum = temp->data + toAdd;
    temp->data = sum % 10;
    toAdd = sum / 10;
    temp = temp->next;
  }
  head = reverseLinkedList(head);
  if (toAdd > 0) {
    return addNewNodeAtStart(head, toAdd);
  }
  return head;
}

bool isPalindrome(Node *head) {
  Node *middleHead = middleNodeFastAndSlowPtr(head);
  middleHead = reverseLinkedList(middleHead);
  Node *temp1 = head;
  Node *temp2 = middleHead;
  bool isLlPalindrome = true;
  while (temp2 != nullptr) {
    if (temp1->data != temp2->data) {
      isLlPalindrome = false;
      break;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  reverseLinkedList(middleHead);
  return isLlPalindrome;
}

// TC: O(N) SC: O(1)
Node* insertInSortedLinkedList(Node* head, int valToInsert) {
    Node* prev = nullptr;
    Node* temp = head;
    while(temp != nullptr && temp->data < valToInsert) {
        prev = temp;
        temp = temp->next;
    }
    Node* newNode = new Node(valToInsert);
    // Insertion in empty LL or at beg.
    if (prev == nullptr) {
        head = newNode;
    } else {
        prev->next = newNode;
    }
    newNode->next = temp;
}

// TC: O(N) SC: O(1)
void removeAllDuplicatesFromSortedLinkedList(Node* head) {
    Node* temp = head;
    while(temp != nullptr && temp->next != nullptr) {
        if (temp->data == temp->next->data) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        } else {
            temp = temp->next;
        }
    }
}

int main() {
  Node *head = nullptr;
  Node *node = nullptr;
  Node *newNode = new Node(10);
  head = newNode;
  node = newNode;
  newNode = new Node(12);
  node->next = newNode;
  node = node->next;
  newNode = new Node(-100);
  node->next = newNode;
  node = node->next;
  newNode = new Node(22);
  node->next = newNode;
  node = node->next;
  printLinkedlist(head);
  head = addNewNodeAtStart(head, -10);
  return 0;
}

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

/**
 *
 * Given a sorted linked list and a new value,
 * insert new value such that final linked list remains sorted.
 *
 * Given a sorted linked list, remove all duplicates.
 *
 * Given a linked list and a value, delete all nodes of that value.
 *
 *
 */
