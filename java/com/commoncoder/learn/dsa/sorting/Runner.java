package com.commoncoder.learn.dsa.sorting;

import java.util.Arrays;

public class Runner {

    public static void main(String[] args) {
        SortingAlgorithm sortingAlgorithm = new SelectionSort();
        int[] arr = new int[]{6, 2, -1, 3, 9, -10, 9, 97};
        sortingAlgorithm.sort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
