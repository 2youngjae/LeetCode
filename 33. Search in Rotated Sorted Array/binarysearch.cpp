/**
 * @file binarysearch.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-09-26
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Search in
 * Rotated Sorted Array.
 * Memory Usage: 11.2 MB, less than 29.93% of C++ online submissions for Search
 * in Rotated Sorted Array.
 *
 * Time complexity : O(logn)
 * Space complexity : O(n)
 *
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (target == nums[m]) {
        return m;
      }

      if (nums[m] > nums[r]) {
        if (target < nums[m] && target >= nums[l]) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      } else if (nums[m] < nums[l]) {
        if (target > nums[m] && target <= nums[r]) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      } else {
        if (target < nums[m]) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }
    return -1;
  }
};