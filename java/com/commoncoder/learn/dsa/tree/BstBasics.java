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

    static class DeleteNodeInfo {
        BinaryTreeNode nodeToBeDeleted;
        BinaryTreeNode parentOfNodeToBeDeleted;
        // true if node to be deleted is on left side of its parent.
        // else if false then node to be deleted will be on right side of its parent
        boolean isLeft;

        public DeleteNodeInfo(BinaryTreeNode nodeToBeDeleted, BinaryTreeNode parentOfNodeToBeDeleted, boolean isLeft) {
            this.nodeToBeDeleted = nodeToBeDeleted;
            this.parentOfNodeToBeDeleted = parentOfNodeToBeDeleted;
            this.isLeft = isLeft;
        }
    }



    private DeleteNodeInfo searchNodeToBeDeleted(BinaryTreeNode root, int valueToBeDeleted) {
        BinaryTreeNode checking = root;
        BinaryTreeNode parent = null;
        boolean isLeft = false;
        while (checking != null && checking.data != valueToBeDeleted) {
            parent = checking;
            if (valueToBeDeleted < checking.data) {
                isLeft = true;
                checking = checking.left;
            } else {
                isLeft = false;
                checking = checking.right;
            }
        }
        return new DeleteNodeInfo(checking, parent, isLeft);
    }

    // TC: O(h) but in worst case, this h could be N so O(N)
    // in avg case h would be logN
    // SC: recursion stack uses O(h) space
    // SC: iterative version O(1) space
    public BinaryTreeNode deleteValueFromBst(BinaryTreeNode root, int valueToBeDeleted) {
        if (root == null) {
            return null;
        }
        DeleteNodeInfo deleteNodeInfo = searchNodeToBeDeleted(root, valueToBeDeleted);
        // We are not able to find the node to be deleted in BST!
        if (deleteNodeInfo.nodeToBeDeleted == null) {
            return root;
        }

        // We have single node in BST and we are deleting that single node
        if (deleteNodeInfo.nodeToBeDeleted == root
                && root.left == null && root.right == null) {
            return null;
        }
        deleteNode(deleteNodeInfo);
        return root;

    }

    // TC: O(h) but in worst case, this h could be N so O(N)
    // in avg case h would be logN
    // SC: recursion stack uses O(h) space
    // SC: iterative version O(1) space
    private void deleteNode(DeleteNodeInfo deleteNodeInfo) {
        while (deleteNodeInfo != null) {
            if (deleteNodeInfo.nodeToBeDeleted.left == null && deleteNodeInfo.nodeToBeDeleted.right == null) {
                simpleDetachNodeFromParent(deleteNodeInfo);
                deleteNodeInfo = null;
            } else if (deleteNodeInfo.nodeToBeDeleted.right != null) {
                DeleteNodeInfo inorderSuccessorDeleteNodeInfo = inorderSuccessorInRightSubtree(deleteNodeInfo.nodeToBeDeleted);
                deleteNodeInfo.nodeToBeDeleted.data = inorderSuccessorDeleteNodeInfo.nodeToBeDeleted.data;
                deleteNodeInfo = inorderSuccessorDeleteNodeInfo;
            } else { // deleteNodeInfo.nodeToBeDeleted.left != null
                DeleteNodeInfo inorderPredecessorDeleteNodeInfo = inorderPredecessorInLeftSubtree(deleteNodeInfo.nodeToBeDeleted);
                deleteNodeInfo.nodeToBeDeleted.data = inorderPredecessorDeleteNodeInfo.nodeToBeDeleted.data;
                deleteNodeInfo = inorderPredecessorDeleteNodeInfo;
            }
        }

    }

    private void simpleDetachNodeFromParent(DeleteNodeInfo deleteNodeInfo) {
        if (deleteNodeInfo.isLeft) {
            deleteNodeInfo.parentOfNodeToBeDeleted.left = null;
        } else {
            deleteNodeInfo.parentOfNodeToBeDeleted.right = null;
        }
        // delete deleteNodeInfo.nodeToBeDeleted
    }

    // TC: O(h)
    // SC: O(1)
    private DeleteNodeInfo inorderSuccessorInRightSubtree(BinaryTreeNode startingNode) {
        BinaryTreeNode checking = startingNode.right;
        BinaryTreeNode parent = startingNode;
        boolean isLeft = false;
        while (checking.left != null) {
            parent = checking;
            checking = checking.left;
            isLeft = true;
        }
        return new DeleteNodeInfo(checking, parent, isLeft);
    }

    // TC: O(h)
    // SC: O(1)
    private DeleteNodeInfo inorderPredecessorInLeftSubtree(BinaryTreeNode startingNode) {
        BinaryTreeNode checking = startingNode.left;
        BinaryTreeNode parent = startingNode;
        boolean isLeft = true;
        while (checking.right != null) {
            parent = checking;
            checking = checking.right;
            isLeft = false;
        }
        return new DeleteNodeInfo(checking, parent, isLeft);
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
