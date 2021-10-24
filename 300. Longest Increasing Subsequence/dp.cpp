/**
 * @file dp.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-10-24
 * @copyright Copyright (c) 2021
 *
 * Runtime: 372 ms, faster than 22.68% of C++ online submissions for Longest
 * Increasing Subsequence. Memory Usage: 10.6 MB, less than 12.56% of C++ online
 * submissions for Longest Increasing Subsequence.
 *
 * Time complexity : O(N^2)
 * Space complexity : O(N)
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    const int size = nums.size();
    if (size == 0) {
      return 0;
    }

    vector<int> d(size, 1);
    int answer = 1;
    for (int i = 1; i < size; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          d[i] = max(d[i], d[j] + 1);
        }
      }
      answer = max(answer, d[i]);
    }
    return answer;
  }
};