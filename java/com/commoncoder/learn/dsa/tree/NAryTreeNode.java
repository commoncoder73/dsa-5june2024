package com.commoncoder.learn.dsa.tree;

import java.util.ArrayList;
import java.util.List;

public class NAryTreeNode {

    int data;
    List<NAryTreeNode> children;

    public NAryTreeNode(int data) {
        this.data = data;
        this.children = new ArrayList<>();
    }

    public NAryTreeNode(int data, List<NAryTreeNode> children) {
        this.data = data;
        this.children = children;
    }
}
