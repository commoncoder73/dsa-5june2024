package com.commoncoder.learn.dsa.sorting;

public class CountingSort implements SortingAlgorithm{

    // Assume N is length of original array
    // and M is max number in the original array
    // TC: O(N+M)
    // SC: O(N+M)
    // Stability: stable
    @Override
    public void sort(int[] arr) {
        // T: O(N)  S: O(1)
        int maxVal = max(arr);

        // T: O(N)  S: O(M)
        int[] countArray = countOccurrencesOfAllElements(arr, maxVal);

        // T: O(N+M)   S: O(N)
        int[] sortedArray = countToSortedArrayUsingCumulativeSum(arr, countArray);

        // T: O(N)   S: O(1)
        copyArray(sortedArray, arr);
    }

    private int[] countOccurrencesOfAllElements(int[] arr, int maxVal) {
        int[] countArray = new int[maxVal + 1];
        for(int i=0; i<arr.length; i++) {
            countArray[arr[i]]++;
        }
        return countArray;
    }

    private void copyArray(int[] source, int[] dest) {
        for(int i=0; i<source.length; i++) {
            dest[i] = source[i];
        }
    }

    // method 1
    public int[] countToSortedArray(int[] arr, int[] countArray) {
        int[] sortedArray = new int[arr.length];
        int k = 0;
        for(int i=0; i<countArray.length; i++) {
            for(int j=1; j<=countArray[i]; j++) {
                sortedArray[k++] = i;
            }
        }
        return sortedArray;
    }

    // TC: O(N+M) SC: O(N)
    // method 2
    public int[] countToSortedArrayUsingCumulativeSum(int[] arr, int[] countArray) {
        int[] sortedArray = new int[arr.length];

        // O(M)
        inPlaceCumulativeSum(countArray);

        // O(N)
        for(int i=arr.length-1; i>=0; i--) {
            int positionOfElement = countArray[arr[i]];
            sortedArray[positionOfElement - 1] = arr[i];
            countArray[arr[i]]--;
        }
        return sortedArray;
    }

    private int max(int[] arr) {
        int max = Integer.MIN_VALUE;
        for(int i=0; i<arr.length; i++) {
            if (max < arr[i]) {
                max = arr[i];
            }
        }
        return max;
    }

    private void inPlaceCumulativeSum(int[] arr) {
        int sum = 0;
        for(int i=0; i<arr.length; i++) {
            sum += arr[i];
            arr[i] = sum;
        }
    }
}
