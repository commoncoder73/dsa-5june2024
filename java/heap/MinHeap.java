package heap;

import java.util.Arrays;

public class MinHeap {

    private int[] heapArray;
    // capacity of this heap = heapArray.length
    private int heapSize;

    MinHeap(int[] heapArray, int heapSize) {
        this.heapArray = heapArray;
        this.heapSize = heapSize;
        buildHeap();
    }

    public int getMin() {
        if (heapSize <= 0) {
            throw new RuntimeException("Heap is empty!");
        }
        return heapArray[0];
    }

    // TC: O(logN)
    // SC: O(1)
    public void add(int newValue) {
        if (heapSize == heapArray.length) {
            throw new RuntimeException("Heap is full!");
        }
        heapSize++;
        int indexOfAddingNewNode = heapSize - 1;
        heapArray[indexOfAddingNewNode] = newValue; // O(1)
        while (indexOfAddingNewNode > 0 &&
                heapArray[indexOfAddingNewNode] < heapArray[parent(indexOfAddingNewNode)]) {
            swap(indexOfAddingNewNode, parent(indexOfAddingNewNode));
            indexOfAddingNewNode = parent(indexOfAddingNewNode);
        }
    }

    // TC: O(logN)
    // SC: O(1)
    public int deleteByIndex(int index) {
        if (!(0 <= index && index < heapSize)) {
            throw new RuntimeException("Valid index not provided!");
        }
        int valueToBeDeleted = heapArray[index];
        swap(index, heapSize - 1);
        heapArray[heapSize - 1] = 0;
        heapSize--;
        heapify(index);
        return valueToBeDeleted;
    }

    // TC: O(logN) SC: O(1)
    public int removeMin() {
        return deleteByIndex(0);
    }

    public void print() {
        System.out.println(Arrays.toString(heapArray));
    }


    // TC: O(N) SC: O(1) ( if heapify is written iteratively else for recursion it would be O(logN)
    private void buildHeap() {
        // Last non leaf node is parent of last leaf node.
        // Last leaf node is present at last index of the array.
        int lastNonLeafNodeIndex = parent(heapSize - 1);
        for (int i = lastNonLeafNodeIndex; i >= 0; i--) {
            heapify(i);
        }
    }

    // Heapify ith node. This means compare it with children and find min values recursively.
    // TC: O(logN)
    private void heapify(int i) {
        int minimumValueIndex = i; // assume ith index has the minimum
        while (i < heapSize) {
            int leftChildIndex = left(i);
            int rightChildIndex = right(i);
            if (leftChildIndex < heapSize && heapArray[leftChildIndex] < heapArray[minimumValueIndex]) {
                minimumValueIndex = leftChildIndex;
            }
            if (rightChildIndex < heapSize && heapArray[rightChildIndex] < heapArray[minimumValueIndex]) {
                minimumValueIndex = rightChildIndex;
            }

            if (minimumValueIndex != i) {
                swap(i, minimumValueIndex);
                i = minimumValueIndex; // recursion - SC: O(logN) // without recursion: O(1)
            } else {
                break;
            }
        }

    }

    private void swap(int i, int j) {
        int temp = heapArray[i];
        heapArray[i] = heapArray[j];
        heapArray[j] = temp;
    }


    private int left(int i) {
        return 2 * i + 1;
    }

    private int right(int i) {
        return 2 * i + 2;
    }

    private int parent(int i) {
        return (i - 1) / 2;
    }

    public static void main(String[] args) {
        int[] arr = new int[]{25, 20, 11, 15, 13, 12, 15, 19, 9, 8, 7, 7, 0};
        MinHeap minHeap = new MinHeap(arr, 12);
        minHeap.print();
        minHeap.add(2);
        minHeap.print();
    }


}
