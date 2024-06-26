package com.commoncoder.learn.dsa.sorting;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Stack;

public class BucketSort {

    // T:
        // Avg: O(N+KlogK)
        // Worst:  O(NlogN)
    // S: O(N)
    // stability: depends on sorting algorithm used
    public void sort(float[] arr) {
        ArrayList<Float>[] buckets = (ArrayList<Float>[]) new ArrayList[10];
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new ArrayList<>();
        }
        for(int i=0; i<arr.length; i++) {
            int bucketIndex = getBucketIndex(arr[i]);
            buckets[bucketIndex].add(arr[i]);
        }
        int k=0;
        for (int i = 0; i < buckets.length; i++) {
            Collections.sort(buckets[i]);
            for(Float val: buckets[i]) {
                arr[k++] = val;
            }
        }

    }

    private int getBucketIndex(float val) {
        return (int)(val * 10) % 10;
    }


    public static void main(String[] args) {
        float[] arr = new float[]{0.734f, 0.543f, 0.111f, 0.012f, 0.923f};
        BucketSort bucketSort = new BucketSort();
        bucketSort.sort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
