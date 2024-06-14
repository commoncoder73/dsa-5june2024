#include <bits/stdc++.h>

using namespace std;

int main() {
  int arr[] = {1, 2, 5, 6, 7, 9, 11};
  int n = 7;
  int targetSum = 9;
  int start = 0;
  int end = n - 1;
  while (start < end) {
    int sum = arr[start] + arr[end];
    if (targetSum == sum) {
      cout << start << " " << end << endl;
      return 0;
    }
    if (targetSum > sum) {
      end--;
    } else {
      start++;
    }
  }
  cout << "No such pair!" << endl;
}
