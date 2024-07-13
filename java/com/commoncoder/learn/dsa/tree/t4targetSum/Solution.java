package com.commoncoder.learn.dsa.tree.t4targetSum;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return false;
        }
        List<Integer> targetSumPath = new ArrayList<>();
        return hasPathSum(root, targetSum, 0, targetSumPath);
    }

    public boolean hasPathSum(TreeNode root, int targetSum, int sum, List<Integer> targetSumPath) {
        if (root.left == null && root.right == null && targetSum == sum + root.val) {
            targetSumPath.add(root.val);
            return true;
        }
        boolean isSumPossibleOnLeft = false;
        if (root.left != null) {
            isSumPossibleOnLeft = hasPathSum(root.left, targetSum, sum + root.val, targetSumPath);
        }
        boolean isSumPossibleOnRight = false;
        if (root.right != null) {
            isSumPossibleOnRight = hasPathSum(root.right, targetSum, sum + root.val, targetSumPath);
        }
        boolean isSumPossible = isSumPossibleOnLeft || isSumPossibleOnRight;
        if (isSumPossible) {
            targetSumPath.add(root.val);
        }
        return isSumPossible;
    }

}
