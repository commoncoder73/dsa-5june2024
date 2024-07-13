package com.commoncoder.learn.dsa.tree.t5SumRootToLeafNums;

public class Solution {

    public class TreeNode {
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

    // TC: O(N)
    // SC: O(H)
    public int sumNumbers(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return sumNumbers(root, 0, 0);
    }

    private int sumNumbers(TreeNode root, int numSoFar, int totalSum) {
        if (root == null) {
            return totalSum;
        }
        int newNum = numSoFar * 10 + root.val;
        if (root.left == null && root.right == null) {
            return totalSum + newNum;
        }
        if (root.left != null) {
            totalSum = sumNumbers(root.left, newNum, totalSum);
        }
        if (root.right != null) {
            totalSum = sumNumbers(root.right, newNum, totalSum);
        }
        return totalSum;
    }

}
