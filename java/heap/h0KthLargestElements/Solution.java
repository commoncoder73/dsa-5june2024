package heap.h0KthLargestElements;

import java.util.*;

public class Solution {

    // TC: O(KlogN) SC: O(N)
    public int findKthLargest(int[] nums, int k) {
        List<Integer> list = new ArrayList<>();
        for (int val : nums) { // O(N)
            list.add(val);
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        pq.addAll(list); // O(N)
        int count = 0;
        while (!pq.isEmpty()) { // K
            count++;
            if (count == k) {
                return pq.peek();
            } else {
                pq.poll(); // we will remove k-1 max values
                // logN
            }
        }
        return Integer.MIN_VALUE;
    }


}
