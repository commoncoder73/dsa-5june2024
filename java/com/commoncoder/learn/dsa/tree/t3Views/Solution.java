package com.commoncoder.learn.dsa.tree.t3Views;

import com.commoncoder.learn.dsa.tree.BinaryTreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {

    public List<Integer> rightView(BinaryTreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        Queue<BinaryTreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            while (levelSize > 0) {
                BinaryTreeNode firstNode = queue.poll();
                if (levelSize == 1) {
                    result.add(firstNode.data);
                }
                if (firstNode.left != null) {
                    queue.add(firstNode.left);
                }
                if (firstNode.right != null) {
                    queue.add(firstNode.right);
                }
                levelSize--;
            }
        }
        return result;
    }


    public List<Integer> leftView(BinaryTreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        Queue<BinaryTreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            int nodeCount = 1;
            while (nodeCount <= levelSize) {
                BinaryTreeNode firstNode = queue.poll();
                if (nodeCount == 1) {
                    result.add(firstNode.data);
                }
                if (firstNode.left != null) {
                    queue.add(firstNode.left);
                }
                if (firstNode.right != null) {
                    queue.add(firstNode.right);
                }
                nodeCount++;
            }
        }
        return result;
    }

}
