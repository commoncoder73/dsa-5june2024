package heap;

import java.util.*;

public class Solution {

    static class Student {
        int cgpa;
        int id;
        String name;

    }

    public static void main(String[] args) {


        List<Integer> nums = new ArrayList<>(Arrays.asList(25, 20, 11, 15, 13, 12, 15, 19, 9, 8, 7, 7));

        PriorityQueue<Integer> pq0 = new PriorityQueue<>(); // empty priority q
        // and then add N elements one by one.
        // NlogN
        // instead if you create min/max heap from all the elements at once
        // using buildHeap, we will get O(N) time Comp!

//        PriorityQueue<Student> pq = new PriorityQueue<>(new Comparator<Student>() {
//            @Override
//            public int compare(Student o1, Student o2) {
//                if (o1.cgpa < o2.cgpa) {
//                    return 1;
//                } else if (o1.cgpa > o2.cgpa) {
//                    return -1;
//                } else {
//                    return -1*o1.name.compareTo(o2.name);
//                }
//            }
//        });
//        new TreeMap<>(Collections.reverseOrder());
        pq0.addAll(nums);
        for (Integer val: pq0) {
            System.out.println(val);
        }
//        pq0.add(10); // add new value
//        pq0.peek(); // provide min or max value
//        pq0.poll(); // remove min or max

    }

}
