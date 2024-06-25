package com.commoncoder.learn.dsa.sorting;

public class MergeSort implements SortingAlgorithm {

    // TC: O(N*logN) SC: O(N)
    // Stability: stable
    @Override
    public void sort(int[] arr) {
        int[] sortedArray = mergeSort(arr, 0, arr.length - 1);
        copyArray(sortedArray, arr);
    }

    public int[] mergeSort(int[] arr, int start, int end) {
        if (start > end) {
            return new int[]{};
        } else if (start == end) {
            return new int[]{arr[start]};
        }
        int mid = (start + end) / 2;
        int[] sortedFirstHalf = mergeSort(arr, start, mid);
        int[] sortedSecondHalf = mergeSort(arr, mid + 1, end);
        return mergeSortedArray(sortedFirstHalf, sortedSecondHalf);
    }

    // TC: O(N+M) if N=M O(N)
    // SC: O(N+M) if N=M O(N)
    public int[] mergeSortedArray(int[] arr1, int[] arr2) {
        int[] mergedSortedArray = new int[arr1.length + arr2.length];
        int i = 0; // arr1
        int j = 0; // arr2
        int k = 0; // mergedSortedArray
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] <= arr2[j]) {
                mergedSortedArray[k] = arr1[i];
                k++;
                i++;
            } else {
                mergedSortedArray[k] = arr2[j];
                k++;
                j++;
            }
        }

        while (i < arr1.length) {
            mergedSortedArray[k] = arr1[i];
            k++;
            i++;
        }

        while (j < arr2.length) {
            mergedSortedArray[k] = arr2[j];
            k++;
            j++;
        }

        return mergedSortedArray;
    }

    private void copyArray(int[] source, int[] dest) {
        for (int i = 0; i < source.length; i++) {
            dest[i] = source[i];
        }
    }

}
