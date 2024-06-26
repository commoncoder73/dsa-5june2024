package com.commoncoder.learn.dsa.sorting;

import java.util.Arrays;

public class QuickSort implements SortingAlgorithm {

    @Override
    public void sort(int[] arr) {
        quickSort(arr, 0, arr.length-1);
    }

    // TC:
        // Worst case: O(N^2)
        // Average case: O(NlogN)
    // SC:
        // Worst case: O(N)
        // Average case: O(logN)
    // Stability: unstable
    public void quickSort(int[] arr, int start, int end) {
        if(start >= end) {
            return;
        }
        int boundary = partitionAndSetCorrectPositionForPivot(arr, start, end);
        quickSort(arr, start, boundary-1);
        quickSort(arr, boundary+1, end);
    }

    // TC: O(N)
    // SC: O(1)
    public int partitionAndSetCorrectPositionForPivot(int[] arr, int start, int end) {
        int pivotValue = arr[start];
        int boundary = start - 1;
        for (int i=start; i<=end; i++) {
            if (arr[i] > pivotValue) {
                continue;
            }
            // <=
            boundary++;
            swap(arr, boundary, i);
        }
        swap(arr, start, boundary); // pivot value is set to correct position
        return boundary;
    }

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

}
