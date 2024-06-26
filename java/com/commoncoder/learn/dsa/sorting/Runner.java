package com.commoncoder.learn.dsa.sorting;

import java.util.Arrays;

public class Runner {

    public static void main(String[] args) {
        SortingAlgorithm sortingAlgorithm = new RadixSort();
        int[] arr = new int[]{121, 432, 564, 23, 1, 45, 788};
        sortingAlgorithm.sort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
