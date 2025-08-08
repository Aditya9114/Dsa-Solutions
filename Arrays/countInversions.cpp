#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int count = 0;  // Moved inside the class to avoid global pollution

    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
                count += (mid - left + 1);  // Key logic for counting inversions
            }
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for (int i = low; i <= high; ++i) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    int inversionCount(vector<int> &nums) {
        count = 0;  // Reset count before starting
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};
