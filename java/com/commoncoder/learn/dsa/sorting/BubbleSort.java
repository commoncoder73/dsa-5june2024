package com.commoncoder.learn.dsa.sorting;

public class BubbleSort implements SortingAlgorithm{

    // TC: O(N*2) SC: O(1)
    // Stable (given that we are not swapping equal elements)
    @Override
    public void sort(int[] arr) {
        for(int i=0; i<arr.length; i++) {
            for(int j=0; j<arr.length-1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr, j, j+1);
                }
            }
        }
    }

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
