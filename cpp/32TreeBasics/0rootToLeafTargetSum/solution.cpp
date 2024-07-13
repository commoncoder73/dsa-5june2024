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

bool hasPathSum(TreeNode *root, int targetSum) {
  vector<int> targetSumPath;
  return hasPathSum(root, targetSum, 0, targetSumPath);
}

bool hasPathSum(TreeNode *root, int targetSum, int sum,
                vector<int> targetSumPath) {
  if (root == nullptr) {
    return false;
  }
  if (root->left == nullptr && root->right == nullptr) {
    targetSumPath.push_back(root->val);
    return targetSum == (sum + root->val);
  }
  bool isTargetSumOnLeft =
      hasPathSum(root->left, targetSum, sum + root->val, targetSumPath);
  if (isTargetSumOnLeft) {
    targetSumPath.push_back(root->val);
    return true;
  }
  bool isTargetSumOnRight =
      hasPathSum(root->right, targetSum, sum + root->val, targetSumPath);
  if (isTargetSumOnRight) {
    targetSumPath.push_back(root->val);
    return true;
  }
  return false;
}