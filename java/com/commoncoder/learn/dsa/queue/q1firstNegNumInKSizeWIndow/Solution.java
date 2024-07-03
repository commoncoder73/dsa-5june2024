package com.commoncoder.learn.dsa.queue.q1firstNegNumInKSizeWIndow;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    // 0 1 2 3 4 5 6 7 8 9
    // n = 10
    // k = 3
    ArrayList<Integer> firstNegativeNumberInKSizeWindow(int[] arr, int k) {
        Queue<Integer> queue = new LinkedList<>();
        for (int i=0; i<k; i++) {
            if (arr[i] < 0) {
                queue.add(arr[i]);
            }
        }
        ArrayList<Integer> answer = new ArrayList<>();
        answer.add(getFirstNegativeNum(queue));
        for (int i=k; i<arr.length; i++) {
            if (arr[i] < 0) {
                queue.add(arr[i]);
            }
            if (arr[i-k] < 0) {
                queue.poll();
            }
            answer.add(getFirstNegativeNum(queue));
        }
        return answer;
    }

    private int getFirstNegativeNum(Queue<Integer> queue) {
        if (queue.isEmpty()) {
            return 0;
        } else {
            return queue.peek();
        }
    }

}
