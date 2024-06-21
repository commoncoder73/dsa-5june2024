package com.commoncoder.learn.dsa.sorting;

public class SelectionSort implements SortingAlgorithm {

    public void sort(int[] arr) {
        for (int i = 0; i < arr.length; i++) { //
            int minIndex = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr, minIndex, i);
        }
    }

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

}
