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

class DeleteNodeInfo {
 public:
  BinaryTreeNode* nodeToBeDeleted;
  BinaryTreeNode* parentOfNodeToBeDeleted;
  // If true then node to be deleted is present on left side of the parent
  // Else node to be deleted is present on right side of the parent
  bool isLeft;

  DeleteNodeInfo(BinaryTreeNode* nodeToBeDeleted,
                 BinaryTreeNode* parentOfNodeToBeDeleted, bool isLeft) {
    this->nodeToBeDeleted = nodeToBeDeleted;
    this->parentOfNodeToBeDeleted = parentOfNodeToBeDeleted;
    this->isLeft = isLeft;
  }
};

DeleteNodeInfo* searchNodeToBeDeleted(BinaryTreeNode* root,
                                      int valueToBeDeleted) {
  BinaryTreeNode* parent = nullptr;
  BinaryTreeNode* checking = root;
  bool isLeft = false;
  while (checking != nullptr && checking->data != valueToBeDeleted) {
    parent = checking;
    if (valueToBeDeleted < checking->data) {
      checking = checking->left;
      isLeft = true;
    } else {
      checking = checking->right;
      isLeft = false;
    }
  }
  return new DeleteNodeInfo(checking, parent, isLeft);
}

// TC: O(H) avg O(logN) worst O(N)
// SC: recursive:  O(H) avg O(logN) worst O(N)
// iterative: O(1)
BinaryTreeNode* deleteValueFromBst(BinaryTreeNode* root, int valueToBeDeleted) {
  // Empty tree
  if (root == nullptr) {
    return root;
  }

  DeleteNodeInfo* deleteNodeInfo =
      searchNodeToBeDeleted(root, valueToBeDeleted);
  // Node to be deleted not found from given BST
  if (deleteNodeInfo->nodeToBeDeleted == nullptr) {
    return root;
  }
  // We only have single node in BST and we are trying to delete that single
  // tree
  if (deleteNodeInfo->nodeToBeDeleted == root && root->left == nullptr &&
      root->right == nullptr) {
    return nullptr;
  }

  deleteNode(deleteNodeInfo);
  return root;
}

void deleteNode(DeleteNodeInfo* deleteNodeInfo) {
  while (deleteNodeInfo != nullptr) {
    // Node to be deleted is not having any children
    if (deleteNodeInfo->nodeToBeDeleted->left == nullptr &&
        deleteNodeInfo->nodeToBeDeleted->right == nullptr) {
      dettachFromParent(deleteNodeInfo);
      deleteNodeInfo = nullptr;
    }

    // If left subtree is present, then we can get inorder predecessor from left
    // subtree
    if (deleteNodeInfo->nodeToBeDeleted->left != nullptr) {
      // inorder predecessor will be promoted as root
      DeleteNodeInfo* inorderPredecessorInfo =
          inorderPredecessorInLeftSubtree(deleteNodeInfo->nodeToBeDeleted);
      deleteNodeInfo->nodeToBeDeleted->data =
          inorderPredecessorInfo->nodeToBeDeleted->data;
      deleteNodeInfo = inorderPredecessorInfo;
    }
    // Here right subtree will be present, and hence we can get inorder
    // successor
    else {  // deleteNodeInfo->nodeToBeDeleted->right != nullptr
      // inorder successor will be promoted as root
      DeleteNodeInfo* inorderSuccessorInfo =
          inorderSuccessorInRightSubtree(deleteNodeInfo->nodeToBeDeleted);
      deleteNodeInfo->nodeToBeDeleted->data =
          inorderSuccessorInfo->nodeToBeDeleted->data;
      deleteNodeInfo = inorderSuccessorInfo;
    }
  }
}

void dettachFromParent(DeleteNodeInfo* deleteNodeInfo) {
  if (deleteNodeInfo->parentOfNodeToBeDeleted == nullptr) {
    return;
  }
  if (deleteNodeInfo->isLeft) {
    deleteNodeInfo->parentOfNodeToBeDeleted->left = nullptr;
  } else {
    deleteNodeInfo->parentOfNodeToBeDeleted->right = nullptr;
  }
  delete deleteNodeInfo->nodeToBeDeleted;
}

// Rightmost node in left subtree
DeleteNodeInfo* inorderPredecessorInLeftSubtree(BinaryTreeNode* startingNode) {
  if (startingNode->left == nullptr) {
    return nullptr;
  }
  BinaryTreeNode* parent = startingNode;
  BinaryTreeNode* checking = startingNode->left;
  bool isLeft = true;
  while (checking->right != nullptr) {
    parent = checking;
    checking = checking->right;
    isLeft = false;
  }
  return new DeleteNodeInfo(checking, parent, isLeft);
}

// Leftmost node in right subtree
DeleteNodeInfo* inorderSuccessorInRightSubtree(BinaryTreeNode* startingNode) {
  if (startingNode->right == nullptr) {
    return nullptr;
  }
  BinaryTreeNode* parent = startingNode;
  BinaryTreeNode* checking = startingNode->right;
  bool isLeft = false;
  while (checking->left != nullptr) {
    parent = checking;
    checking = checking->left;
    isLeft = true;
  }
  return new DeleteNodeInfo(checking, parent, isLeft);
}
