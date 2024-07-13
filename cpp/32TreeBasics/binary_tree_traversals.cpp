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

// TC: O(N) SC: O(N)
vector<int>* preorder(BinaryTreeNode* root) {
  vector<int>* result = new vector<int>();
  if (root == nullptr) {
    return result;
  }
  stack<BinaryTreeNode*> s;
  s.push(root);
  while (!s.empty()) {
    BinaryTreeNode* topVal = s.top();
    s.pop();
    result->push_back(topVal->data);
    if (topVal->right != nullptr) {
      s.push(topVal->right);
    }
    if (topVal->left != nullptr) {
      s.push(topVal->left);
    }
  }
  return result;
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

// TC: O(N) SC: O(N)
vector<int>* postorder(BinaryTreeNode* root) {
  vector<int>* result = new vector<int>();
  if (root == nullptr) {
    return result;
  }
  stack<TraversalStackNode*> s;
  s.push(new TraversalStackNode(root));
  while (!s.empty()) {
    TraversalStackNode* top = s.top();
    if (top->isAllPreprcoessingDone ||
        (top->node->left == nullptr && top->node->right == nullptr)) {
      result->push_back(top->node->data);
      s.pop();
      continue;
    }
    top->isAllPreprcoessingDone = true;
    if (top->node->left != nullptr) {
      s.push(new TraversalStackNode(top->node->left));
    }
    if (top->node->right != nullptr) {
      s.push(new TraversalStackNode(top->node->right));
    }
  }
  return result;
}

// TC: O(N) SC: O(N)
vector<int>* inorder(BinaryTreeNode* root) {
  vector<int>* result = new vector<int>();
  if (root == nullptr) {
    return result;
  }
  stack<TraversalStackNode*> s;
  s.push(new TraversalStackNode(root));
  while (!s.empty()) {
    TraversalStackNode* top = s.top();
    if (top->isAllPreprcoessingDone || top->node->left == nullptr) {
      result->push_back(top->node->data);
      s.pop();
      if (top->node->right != nullptr) {
        s.push(new TraversalStackNode(top->node->right));
      }
      continue;
    }
    top->isAllPreprcoessingDone = true;
    s.push(new TraversalStackNode(top->node->left));
  }
  return result;
}

// TC: O(N) SC: O(N)
BinaryTreeNode* inorderPredecessor(BinaryTreeNode* root,
                                   BinaryTreeNode* nodeForFindingPredecessor) {
  if (root == nullptr || nodeForFindingPredecessor == nullptr) {
    return nullptr;
  }
  stack<TraversalStackNode*> s;
  s.push(new TraversalStackNode(root));
  BinaryTreeNode* cur = nullptr;
  BinaryTreeNode* prev = nullptr;
  while (!s.empty()) {
    TraversalStackNode* top = s.top();
    if (top->isAllPreprcoessingDone || top->node->left == nullptr) {
      prev = cur;
      cur = top->node;
      if (cur == nodeForFindingPredecessor) {
        return prev;
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
  return nullptr;
}

// TC: O(N) SC: O(N)
BinaryTreeNode* inorderSuccessor(BinaryTreeNode* root,
                                 BinaryTreeNode* nodeForFindingSuccessor) {
  if (root == nullptr || nodeForFindingSuccessor == nullptr) {
    return nullptr;
  }
  stack<TraversalStackNode*> s;
  s.push(new TraversalStackNode(root));
  BinaryTreeNode* cur = nullptr;
  BinaryTreeNode* prev = nullptr;
  while (!s.empty()) {
    TraversalStackNode* top = s.top();
    if (top->isAllPreprcoessingDone || top->node->left == nullptr) {
      prev = cur;
      cur = top->node;
      if (prev == nodeForFindingSuccessor) {
        return cur;
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
  return nullptr;
}

// TC: O(N) SC: O(N)
// root left right
vector<int>* preorderRecursive(BinaryTreeNode* root) {
  vector<int>* result = new vector<int>();
  preorderRecursive(root, result);
  return result;
}

void preorderRecursive(BinaryTreeNode* root, vector<int>* result) {
  if (root == nullptr) {
    return;
  }
  result->push_back(root->data);
  preorderRecursive(root->left, result);
  preorderRecursive(root->right, result);
}

// TC: O(N) SC: O(N)
// left right root
vector<int>* postorderRecursive(BinaryTreeNode* root) {
  vector<int>* result = new vector<int>();
  postorderRecursive(root, result);
  return result;
}

void postorderRecursive(BinaryTreeNode* root, vector<int>* result) {
  if (root == nullptr) {
    return;
  }
  postorderRecursive(root->left, result);
  postorderRecursive(root->right, result);
  result->push_back(root->data);
}

// TC: O(N) SC: O(N)
// left right root
vector<int>* inorderRecursive(BinaryTreeNode* root) {
  vector<int>* result = new vector<int>();
  inorderRecursive(root, result);
  return result;
}

void inorderRecursive(BinaryTreeNode* root, vector<int>* result) {
  if (root == nullptr) {
    return;
  }
  inorderRecursive(root->left, result);
  result->push_back(root->data);
  inorderRecursive(root->right, result);
}

// TC: O(N) SC: O(N)
vector<int>* levelOrderTraversal(BinaryTreeNode* root) {
  vector<int>* result = new vector<int>();
  if (root == nullptr) {
    return result;
  }
  queue<BinaryTreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    BinaryTreeNode* firstNode = q.front();
    q.pop();

    result->push_back(firstNode->data);

    if (firstNode->left != nullptr) {
      q.push(firstNode->left);
    }
    if (firstNode->right != nullptr) {
      q.push(firstNode->right);
    }
  }

  return result;
}

vector<vector<int>>* levelOrderTraversalSplittedByLevels(BinaryTreeNode* root) {
  vector<vector<int>>* result = new vector<vector<int>>();
  if (root == nullptr) {
    return result;
  }
  queue<BinaryTreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    vector<int> levelAns;
    int levelSize = q.size();
    while (levelSize > 0) {
      BinaryTreeNode* firstNode = q.front();
      q.pop();

      levelAns.push_back(firstNode->data);

      if (firstNode->left != nullptr) {
        q.push(firstNode->left);
      }
      if (firstNode->right != nullptr) {
        q.push(firstNode->right);
      }
      levelSize--;
    }
    result->push_back(levelAns);
  }

  return result;
}

vector<int>* rightView(BinaryTreeNode* root) {
  vector<int>* result = new vector<int>();
  if (root == nullptr) {
    return result;
  }
  queue<BinaryTreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int levelSize = q.size();
    for (int i=0; i<levelSize; i++) {
      BinaryTreeNode* firstNode = q.front();
      q.pop();

      if (i == levelSize - 1) {
        result->push_back(firstNode->data);
      }

      if (firstNode->left != nullptr) {
        q.push(firstNode->left);
      }
      if (firstNode->right != nullptr) {
        q.push(firstNode->right);
      }
      levelSize--;
    }
  }

  return result;
}

vector<int>* leftViewRecursive(BinaryTreeNode* root) {
    vector<int>* result = new vector<int>();
    leftViewRecursive(root, result, 0, -1);
    return result;
}

int leftViewRecursive(BinaryTreeNode* root, vector<int>* result, int height, int maxHeight) {
    if (root == nullptr) {
        return maxHeight;
    }
    if (height > maxHeight) {
        result->push_back(root->data);
        maxHeight = height;
    }
    maxHeight = leftViewRecursive(root->left, result, height + 1, maxHeight);
    maxHeight = leftViewRecursive(root->right, result, height + 1, maxHeight);
    return maxHeight;
}

vector<int>* rightViewRecursive(BinaryTreeNode* root) {
    vector<int>* result = new vector<int>();
    rightViewRecursive(root, result, 0, -1);
    return result;
}

int rightViewRecursive(BinaryTreeNode* root, vector<int>* result, int height, int maxHeight) {
    if (root == nullptr) {
        return maxHeight;
    }
    if (height > maxHeight) {
        result->push_back(root->data);
        maxHeight = height;
    }
    maxHeight = (root->left, result, height + 1, maxHeight);
    maxHeight = (root->right, result, height + 1, maxHeight);
    return maxHeight;
}


vector<int>* leftView(BinaryTreeNode* root) {
  vector<int>* result = new vector<int>();
  if (root == nullptr) {
    return result;
  }
  queue<BinaryTreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int levelSize = q.size();
    for (int i=0; i<levelSize; i++) {
      BinaryTreeNode* firstNode = q.front();
      q.pop();

      if (i == 0) {
        result->push_back(firstNode->data);
      }

      if (firstNode->left != nullptr) {
        q.push(firstNode->left);
      }
      if (firstNode->right != nullptr) {
        q.push(firstNode->right);
      }
      levelSize--;
    }
  }

  return result;
}
