#include <bits/stdc++.h>

/**
 * If element is found, we return index of that element else we return -1
 *
 * If N is input array size
 * TC: O(N)
 * SC: O(1) - without considering input
 */
int linearSearch(int arr[], int n, int elementToFind) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == elementToFind) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[10] = {1, 2, 9, 6, -3, 4, 11, 8, -1, -2};
  int n = 10;
  std::cout << linearSearch(arr, n, 8) << std::endl;
  std::cout << linearSearch(arr, n, 800) << std::endl;
  return 0;
}
