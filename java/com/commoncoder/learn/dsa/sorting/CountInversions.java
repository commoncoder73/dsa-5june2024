package com.commoncoder.learn.dsa.sorting;

/*
v1 v2 v3 cnt1
v4 v5 v6 cnt2
cnt3

[v1] [] - count = 0 ... base condition

6 5 4 3 2 1
15

6 5 4 - 3 [4 5 6]
3 2 1 - 3 [1 2 3]

arr[i] > arr[j]

1 2 3      4 5 6

  i             j
0 5 6       1 2 3

5 2
6 2
count += (n1 - i)
+= (n1 - i)
+= (n1 - i)


0 1





ith element of first half array is greater than jth element of second half
then all elements from i to n1 are greater that jth element

 */


public class CountInversions {

    static class Result {
        int count;
        // to reduce space complexity you should not return this array
        // and make modifications in original array itself.
        int[] sortedArray;

        public Result(int count, int[] sortedArray) {
            this.count = count;
            this.sortedArray = sortedArray;
        }
    }


    // TC: N*logN
    public int countInversions(int[] arr) {
        Result countInversionsResult = countInversions(arr, 0, arr.length - 1);
        return countInversionsResult.count;

    }

    public Result countInversions(int[] arr, int start, int end) {
        if (start > end) {
            return new Result(0, new int[]{});
        } else if (start == end) {
            return new Result(0, new int[]{arr[start]});
        }
        int mid = (start + end) / 2;
        Result countInversionsFirstHalf = countInversions(arr, start, mid);
        Result countInversionsSecondHalf = countInversions(arr, mid + 1, end);
        Result mergedResult = mergeForCountInversions(countInversionsFirstHalf.sortedArray, countInversionsSecondHalf.sortedArray);
        return new Result(
                countInversionsFirstHalf.count + countInversionsSecondHalf.count
                        + mergedResult.count,
                mergedResult.sortedArray
        );
    }

    // TC: O(N+M) if N=M O(N)
    // SC: O(N+M) if N=M O(N)
    public Result mergeForCountInversions(int[] arr1, int[] arr2) {
        int[] mergedSortedArray = new int[arr1.length + arr2.length];
        int i = 0; // arr1
        int j = 0; // arr2
        int k = 0; // mergedSortedArray
        int count = 0;
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] <= arr2[j]) {
                mergedSortedArray[k] = arr1[i];
                k++;
                i++;
            } else {
                count += (arr1.length - i);
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

        return new Result(count, mergedSortedArray);
    }

    public static void main(String[] args) {
        int[] arr = new int[]{6, 5, 4, 3, 2, 1};
        CountInversions countInversions = new CountInversions();
        System.out.println(countInversions.countInversions(arr));
    }


}
