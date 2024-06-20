#include <bits/stdc++.h>

using namespace std;

int binarySearchRec(int arr[], int target, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (target < arr[mid])
    {
        return binarySearchRec(arr, target, start, mid - 1);
    }
    else
    { // arr[mid] < target
        return binarySearchRec(arr, target, mid + 1, end);
    }
}

int binarySearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        { // arr[mid] < target
            start = mid + 1;
        }
    }
}