package com.commoncoder.learn.dsa.sorting;

public class RadixSort implements SortingAlgorithm {

    // TC: O(N*logK)
    // SC: O(N)
    // Stability: stable
    @Override
    public void sort(int[] arr) {
        int maxDigits = getMaxDigits(arr);
        int place = 1;
        for (int i = 0; i < maxDigits; i++) {
            sortDigit(arr, place);
            place *= 10;
        }
    }

    // 1 - unit
    // 10 - tens
    // 76453 -> 764
    // 100 - hundred
    // 1000 - thousand...
    private void sortDigit(int[] arr, int place) {
        int[] count = new int[10];
        for (int i = 0; i < arr.length; i++) {
            int digitAtGivenPlace = getDigitAtPlace(arr[i], place);
            count[digitAtGivenPlace]++;
        }
        inPlaceCumulativeSum(count);

        int[] sortedArray = new int[arr.length];

        for (int i = arr.length - 1; i >= 0; i--) {
            int digitAtGivenPlace = getDigitAtPlace(arr[i], place);
            int positionOfElement = count[digitAtGivenPlace];
            sortedArray[positionOfElement - 1] = arr[i];
            count[digitAtGivenPlace]--;
        }

        for (int i = 0; i < arr.length; i++) {
            arr[i] = sortedArray[i];
        }
    }

    private int getDigitAtPlace(int val, int place) {
        return (val / place) % 10;
    }

    private void inPlaceCumulativeSum(int[] arr) {
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            arr[i] = sum;
        }
    }

    private int getMaxDigits(int[] arr) {
        int max = Integer.MIN_VALUE;
        for (int val : arr) {
            if (max < val) {
                max = val;
            }
        }
        return getDigits(max);
    }

    private int getDigits(int val) {
        int count = 0;
        while (val > 0) {
            count++;
            val /= 10;
        }
        return count;
    }


}
