#include <bits/stdc++.h>

using namespace std;

void bucketSort(float arr[], int n) {
  vector<vector<float>> buckets;
  for (int i = 0; i < 10; i++) {
    vector<float> bucket;
    buckets.push_back(bucket);
  }

  for (int i = 0; i < n; i++) {
    int bucketIndex = (int)arr[i] * 10;
    buckets[bucketIndex].push_back(arr[i]);
  }

  int k = 0;
  for (int i = 0; i < 10; i++) {
    sort(buckets[i].begin(), buckets[i].end());
    for (int j = 0; j < buckets[i].size(); j++) {
      arr[k++] = buckets[i][j];
    }
  }
}

void printArray(float arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main() {
  float arr[]{0.777f, 0.734f, 0.543f, 0.111f, 0.102f, 0.012f, 0.923f};
  bucketSort(arr, 7);
  printArray(arr, 7);
}