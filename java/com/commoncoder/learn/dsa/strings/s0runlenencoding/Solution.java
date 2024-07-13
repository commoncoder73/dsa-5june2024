package com.commoncoder.learn.dsa.strings.s0runlenencoding;

public class Solution {

    // N is the length of original string - aaaaaabbbbbbbccccccccc
    // TC: O(N)
    // SC: O(N)
    public String runLengthEncoding(String str) {
        StringBuilder stringBuilder = new StringBuilder();
        int i=0;
        while (i < str.length()) {
            char currentChar = str.charAt(i);
            stringBuilder.append(currentChar); // append happens in O(1)
            int count = 0;
            while(i < str.length() && str.charAt(i) == currentChar) {
                count++;
                i++;
            }
            stringBuilder.append(count);
        }
        return stringBuilder.toString();
    }

}
