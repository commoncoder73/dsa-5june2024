package com.commoncoder.learn.dsa.tree.t2InvertBinaryTree;

import com.commoncoder.learn.dsa.tree.BinaryTreeNode;

public class Solution {

    public void invertBinaryTree(BinaryTreeNode root) {
        if (root == null) {
            return;
        }
        swapChildren(root);
        invertBinaryTree(root.left);
        invertBinaryTree(root.right);
    }

    private void swapChildren(BinaryTreeNode node) {
        BinaryTreeNode temp = node.left;
        node.left = node.right;
        node.right = temp;
    }

}
