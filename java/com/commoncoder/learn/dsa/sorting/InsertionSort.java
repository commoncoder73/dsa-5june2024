package com.commoncoder.learn.dsa.sorting;

public class InsertionSort implements SortingAlgorithm {

    // TC: O(N^2) SC: O(1)
    // Stable (Given that we don't cross same elements while inserting)
    @Override
    public void sort(int[] arr) {
        for (int i = 1; i<arr.length; i++) { // N
            insertElementInSortedArray(arr, i, arr[i]);
        }
    }

    private void insertElementInSortedArray(int[] arr, int length, int valToInsert) {
        int i = length - 1;
        while (i >= 0 && arr[i] > valToInsert) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i+1] = valToInsert;
    }

}
