#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int sumNumbers(TreeNode *root) { return sumNumbers(root, 0, 0); }

int sumNumbers(TreeNode *root, int numberOfFar, int totalSum) {
  if (root == nullptr) {
    return totalSum;
  }
  int newNumber = numberOfFar * 10 + root->val;
  if (root->left == nullptr && root->right == nullptr) {
    return totalSum + newNumber;
  }
  totalSum = sumNumbers(root->left, newNumber, totalSum);
  totalSum = sumNumbers(root->right, newNumber, totalSum);
  return totalSum;
}