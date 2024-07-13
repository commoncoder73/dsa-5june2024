#include <bits/stdc++.h>

using namespace std;

class BinaryTreeNode {
 public:
  int data;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }

  BinaryTreeNode(int data, BinaryTreeNode* left, BinaryTreeNode* right) {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};

BinaryTreeNode* addNewNode(BinaryTreeNode* root, int newVal) {
  BinaryTreeNode* newNode = new BinaryTreeNode(newVal);
  if (root == nullptr) {
    return newNode;
  }
  BinaryTreeNode* parent = nullptr;
  BinaryTreeNode* checking = root;
  bool isLeft = false;
  while (checking != nullptr) {
    parent = checking;
    if (newVal > checking->data) {
      isLeft = false;
      checking = checking->right;
    } else {
      isLeft = true;
      checking = checking->left;
    }
  }
  if (isLeft) {
    parent->left = newNode;
  } else {
    parent->right = newNode;
  }
}

// TC(Worst): O(N) TC(Avg): O(logN)
// SC(Worst): O(N) SC(Avg): O(logN)
BinaryTreeNode* searchRecursive(BinaryTreeNode* root, int valToSearch) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->data == valToSearch) {
    return root;
  } else if (valToSearch < root->data) {
    return searchRecursive(root->left, valToSearch);
  } else {
    return searchRecursive(root->right, valToSearch);
  }
}

// TC(Worst): O(N) TC(Avg): O(logN)
// SC: O(1)
BinaryTreeNode* search(BinaryTreeNode* root, int valToSearch) {
  BinaryTreeNode* checking = root;
  while (checking != nullptr && checking->data != valToSearch) {
    if (valToSearch < checking->data) {
      checking = checking->left;
    } else {
      checking = checking->right;
    }
  }
  return checking;
}

bool isValidBst(BinaryTreeNode* root) {
  return isValidBst(root, INT_MIN, INT_MAX);
}

// TC: O(N)
// SC: O(N)
bool isValidBst(BinaryTreeNode* root, int min, int max) {
  if (root == nullptr) {
    return true;
  }
  if (!(root->data > min && root->data <= max)) {
    return false;
  }
  return isValidBst(root->left, min, root->data) &&
         isValidBst(root->right, root->data, max);
}

class TraversalStackNode {
 public:
  BinaryTreeNode* node;
  // In case of post order traversal, this means that all children(both left and
  // right) is explored. In case of inorder traversal, this means that left
  // child is completely explored.
  bool isAllPreprcoessingDone;

  TraversalStackNode(BinaryTreeNode* node) {
    this->node = node;
    this->isAllPreprcoessingDone = false;
  }
};

class FloorCeil {
 public:
  BinaryTreeNode* floor;
  BinaryTreeNode* ceil;

  FloorCeil(BinaryTreeNode* floor, BinaryTreeNode* ceil) {
    this->floor = floor;
    this->ceil = ceil;
  }
};

// TC: O(N) SC: O(N)
FloorCeil* floorCeilOfK(BinaryTreeNode* root, int k) {
  if (root == nullptr) {
    return nullptr;
  }
  stack<TraversalStackNode*> s;
  s.push(new TraversalStackNode(root));
  BinaryTreeNode* floor = nullptr;
  while (!s.empty()) {
    TraversalStackNode* top = s.top();
    if (top->isAllPreprcoessingDone || top->node->left == nullptr) {
      if (top->node->data < k) {
        floor = top->node;
      }
      if (top->node->data > k) {
        return new FloorCeil(floor, top->node);
      }
      s.pop();
      if (top->node->right != nullptr) {
        s.push(new TraversalStackNode(top->node->right));
      }
      continue;
    }
    top->isAllPreprcoessingDone = true;
    s.push(new TraversalStackNode(top->node->left));
  }
  return new FloorCeil(floor, nullptr);
}