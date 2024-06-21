#include <bits/stdc++.h>

using namespace std;

int sumOfSqaureOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    int rem = n % 10;
    sum += (rem * rem);
    n /= 10;
  }
  return sum;
}

bool isHappyNumber(int n) {
  int slow = n;
  int fast = n;
  while (fast != 1) {
    slow = sumOfSqaureOfDigits(slow);
    fast = sumOfSqaureOfDigits(sumOfSqaureOfDigits(fast));
    if (slow == fast) {
      return false;
    }
  }
  return true;
}