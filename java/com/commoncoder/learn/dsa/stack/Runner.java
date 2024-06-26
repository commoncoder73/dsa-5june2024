package com.commoncoder.learn.dsa.stack;

public class Runner {

    public static void main(String[] args) {
        Stack stack = new LinkedListBasedStack();
        stack.push(5);
        stack.push(9);
        stack.push(-1);
        stack.push(-10);
        stack.push(100);
        stack.print();
        System.out.println(stack.top() + " is at the top");
        System.out.println(stack.poll() + " polled");
        System.out.println(stack.top() + " is at the top");
        System.out.println(stack.poll() + " polled");
        stack.print();
        System.out.println(stack.top() + " is at the top");
    }

}
