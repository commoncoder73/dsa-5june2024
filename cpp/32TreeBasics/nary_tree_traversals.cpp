#include <bits/stdc++.h>

using namespace std;

class NAryTreeNode {
 public:
  int data;
  vector<NAryTreeNode*> children;

  NAryTreeNode(int data) { this->data = data; }

  NAryTreeNode(int data, vector<NAryTreeNode*> children) {
    this->data = data;
    this->children = children;
  }
};

// TC: O(N) SC: O(N)
vector<int>* preorder(NAryTreeNode* root) {
  vector<int>* result = new vector<int>();
  if (root == nullptr) {
    return result;
  }
  stack<NAryTreeNode*> s;
  s.push(root);
  while (!s.empty()) {
    NAryTreeNode* topVal = s.top();
    s.pop();
    result->push_back(topVal->data);
    for (auto i = topVal->children.size() - 1; i >= 0; i--) {
      s.push(topVal->children[i]);
    }
  }
  return result;
}

class TraversalStackNode {
 public:
  NAryTreeNode* node;
  bool isAllPreprcoessingDone;

  TraversalStackNode(NAryTreeNode* node) {
    this->node = node;
    this->isAllPreprcoessingDone = false;
  }
};

// TC: O(N) SC: O(N)
vector<int>* postorder(NAryTreeNode* root) {
  vector<int>* result = new vector<int>();
  if (root == nullptr) {
    return result;
  }
  stack<TraversalStackNode*> s;
  s.push(new TraversalStackNode(root));
  while (!s.empty()) {
    TraversalStackNode* top = s.top();
    if (top->isAllPreprcoessingDone || top->node->children.empty()) {
      result->push_back(top->node->data);
      s.pop();
      continue;
    }
    top->isAllPreprcoessingDone = true;
    for (int i = top->node->children.size() - 1; i >= 0; i++) {
      s.push(new TraversalStackNode(top->node->children[i]));
    }
  }
  return result;
}

// TC: O(N) SC: O(N)
vector<int>* preorderRecursive(NAryTreeNode* root) {
  vector<int>* result = new vector<int>();
  preorderRecursive(root, result);
  return result;
}

void preorderRecursive(NAryTreeNode* root, vector<int>* result) {
  if (root == nullptr) {
    return;
  }
  result->push_back(root->data);
  for (NAryTreeNode* child : root->children) {
    preorderRecursive(child, result);
  }
}

NAryTreeNode* dfs(NAryTreeNode* root, int valToSearch) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->data == valToSearch) {
    return root;
  }
  for (NAryTreeNode* child : root->children) {
    NAryTreeNode* searchResult = dfs(child, valToSearch);
    if (searchResult != nullptr) {
      return searchResult;
    }
  }
  return nullptr;
}

int countNodes(NAryTreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  int count = 1;
  for (NAryTreeNode* child : root->children) {
    count += countNodes(child);
  }
  return count;
}

// TC: O(N) SC: O(N)
vector<int>* postorderRecursive(NAryTreeNode* root) {
  vector<int>* result = new vector<int>();
  postorderRecursive(root, result);
  return result;
}

void postorderRecursive(NAryTreeNode* root, vector<int>* result) {
  if (root == nullptr) {
    return;
  }
  for (NAryTreeNode* child : root->children) {
    postorderRecursive(child, result);
  }
  result->push_back(root->data);
}

// TC: O(N) SC: O(N)
vector<int>* levelOrderTraversal(NAryTreeNode* root) {
  vector<int>* result = new vector<int>();
  if (root == nullptr) {
    return result;
  }
  queue<NAryTreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    NAryTreeNode* firstNode = q.front();
    q.pop();

    result->push_back(firstNode->data);

    for (NAryTreeNode* child : root->children) {
      q.push(child);
    }
  }

  return result;
}

vector<vector<int>>* levelOrderTraversalSplittedByLevels(NAryTreeNode* root) {
  vector<vector<int>>* result = new vector<vector<int>>();
  if (root == nullptr) {
    return result;
  }
  queue<NAryTreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    vector<int> levelAns;
    int nextLevelSize = 0;
    int levelSize = q.size();
    while (levelSize > 0) {
      NAryTreeNode* firstNode = q.front();
      q.pop();

      levelAns.push_back(firstNode->data);

      for (NAryTreeNode* child : root->children) {
        q.push(child);
      }
      levelSize--;
    }
    result->push_back(levelAns);
  }
}

vector<vector<int>>* zigzagTraversal(NAryTreeNode* root) {
  vector<vector<int>>* result = new vector<vector<int>>();
  if (root == nullptr) {
    return result;
  }
  queue<NAryTreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    vector<int> levelAns;
    int nextLevelSize = 0;
    int levelSize = q.size();
    int levelCount = 0;
    while (levelSize > 0) {
      NAryTreeNode* firstNode = q.front();
      q.pop();

      levelAns.push_back(firstNode->data);

      for (NAryTreeNode* child : root->children) {
        q.push(child);
      }
      levelSize--;
    }
    if (levelCount % 2 == 1) {
      levelAns.reserve(levelAns.size());
    }
    result->push_back(levelAns);
    levelCount++;
  }
}

NAryTreeNode* bfs(NAryTreeNode* root, int valToSearch) {
  if (root == nullptr) {
    return nullptr;
  }
  queue<NAryTreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    NAryTreeNode* firstNode = q.front();
    q.pop();

    if (firstNode->data == valToSearch) {
      return firstNode;
    }

    for (NAryTreeNode* child : root->children) {
      q.push(child);
    }
  }

  return nullptr;
}
