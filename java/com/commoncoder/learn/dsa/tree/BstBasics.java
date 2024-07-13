package com.commoncoder.learn.dsa.tree;

import java.util.Stack;

public class BstBasics {

    // SC: O(1) TC(Worst): O(N) TC(Avg): O(logN)
    public BinaryTreeNode addNewValue(BinaryTreeNode root, int newValue) {
        BinaryTreeNode newNode = new BinaryTreeNode(newValue);
        if (root == null) {
            return newNode;
        }
        BinaryTreeNode parent = null;
        BinaryTreeNode checking = root;
        boolean isLeft = false;
        while (checking != null) {
            parent = checking;
            if (checking.data < newValue) {
                checking = checking.right;
                isLeft = false;
            } else {
                checking = checking.left;
                isLeft = true;
            }
        }
        if (isLeft) {
            parent.left = newNode;
        } else {
            parent.right = newNode;
        }
        return root;
    }

    // SC(Worst): O(N) SC(Avg): O(logN)
    // TC(Worst): O(N) TC(Avg): O(logN)
    public BinaryTreeNode searchRecursive(BinaryTreeNode root, int valueToSearch) {
        if (root == null || root.data == valueToSearch) {
            return root;
        }
        if (valueToSearch <= root.data) {
            return searchRecursive(root.left, valueToSearch);
        } else {
            return searchRecursive(root.right, valueToSearch);
        }
    }

    // SC: O(1) TC(Worst): O(N) TC(Avg): O(logN)
    public BinaryTreeNode search(BinaryTreeNode root, int valueToSearch) {
        BinaryTreeNode checkingPtr = root;
        while (checkingPtr != null && checkingPtr.data != valueToSearch) {
            if (valueToSearch <= checkingPtr.data) {
                checkingPtr = checkingPtr.left;
            } else {
                checkingPtr = checkingPtr.right;
            }
        }
        return checkingPtr;

    }

    public boolean isValidBst(BinaryTreeNode root) {
        return isValidBst(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    // TC: O(N) SC: O(N)
    public boolean isValidBst(BinaryTreeNode root, int min, int max) {
        if (root == null) {
            return true;
        }
        if (!(root.data > min && root.data <= max)) {
            return false;
        }
        boolean isLeftSubTreeValid = isValidBst(root.left, min, root.data);
        boolean isRightSubTreeValid = isValidBst(root.right, root.data, max);
        return isLeftSubTreeValid && isRightSubTreeValid;
    }

    static class FloorCiel {
        BinaryTreeNode floor;
        BinaryTreeNode ciel;

        public FloorCiel(BinaryTreeNode floor, BinaryTreeNode ciel) {
            this.floor = floor;
            this.ciel = ciel;
        }
    }

    public FloorCiel floorCeil(BinaryTreeNode root, int value) {
        if (root == null) {
            return new FloorCiel(null, null);
        }
        Stack<BinaryTreeTraversals.TraversalStackNode> stack = new Stack<>();
        stack.push(new BinaryTreeTraversals.TraversalStackNode(root));
        BinaryTreeNode floor = null;
        while (!stack.isEmpty()) {
            BinaryTreeTraversals.TraversalStackNode top = stack.peek();
            if (top.isAllPreprocessingDone || top.node.left == null) {
                if (top.node.data < value) {
                    floor = top.node;
                }
                if (top.node.data > value) {
                    return new FloorCiel(floor, top.node);
                }
                stack.pop();
                if (top.node.right != null) {
                    stack.push(new BinaryTreeTraversals.TraversalStackNode(top.node.right));
                }
                continue;
            }
            top.isAllPreprocessingDone = true;
            stack.push(new BinaryTreeTraversals.TraversalStackNode(top.node.left));
        }
        return new FloorCiel(floor, null);
    }

    public static void main(String[] args) {
        int[] arr = new int[]{10, 5, 8, 3, 20, 25, 16, -1, 8, 15};
        BstBasics bstBasics = new BstBasics();
        BinaryTreeNode root = null;
        for (int val : arr) {
            root = bstBasics.addNewValue(root, val);
        }
        BinaryTreeTraversals binaryTreeTraversals = new BinaryTreeTraversals();
        System.out.println(binaryTreeTraversals.inorderRecursive(root));

    }


}
