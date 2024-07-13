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

int maxDepthBasedOnNumberOfEdges(NAryTreeNode* root) {
  if (root == nullptr) {
    return -1;
  }
  return maxDepthBasedOnNumberOfEdges(root, 0);
}

int maxDepthBasedOnNumberOfEdges(NAryTreeNode* root, int currentDepth) {
  if (root == nullptr) {
    return currentDepth;
  }
  int maxDepthVal = INT_MIN;
  for (NAryTreeNode* child : root->children) {
    int depth = maxDepthBasedOnNumberOfEdges(child, currentDepth + 1);
    maxDepthVal =
        depth > maxDepthVal ? depth : maxDepthVal;  // conditional operator
  }
  return maxDepthVal;
}