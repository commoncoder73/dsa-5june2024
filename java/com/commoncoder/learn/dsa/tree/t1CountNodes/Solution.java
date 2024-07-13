package com.commoncoder.learn.dsa.tree.t1CountNodes;

import com.commoncoder.learn.dsa.tree.BinaryTreeNode;

public class Solution {

    public int countNodes(BinaryTreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 +
                countNodes(root.left) +
                countNodes(root.right);
    }

}
