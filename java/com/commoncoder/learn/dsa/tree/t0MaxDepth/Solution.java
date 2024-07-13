package com.commoncoder.learn.dsa.tree.t0MaxDepth;

import com.commoncoder.learn.dsa.tree.BinaryTreeNode;

public class Solution {

    public int maxDepthBasedOnNumberOfVertices(BinaryTreeNode root) {
        if (root == null) {
            return 0;
        }
        int maxDepthLeft = maxDepthBasedOnNumberOfVertices(root.left);
        int maxDepthRight = maxDepthBasedOnNumberOfVertices(root.right);
        return 1 + Math.max(maxDepthLeft, maxDepthRight);
    }

}
