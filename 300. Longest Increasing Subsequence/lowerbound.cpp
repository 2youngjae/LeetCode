/**
 * @file lowerbound.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-10-24
 * @copyright Copyright (c) 2021
 *
 * Runtime: 13 ms, faster than 74.18% of C++ online submissions for Longest
 * Increasing Subsequence. Memory Usage: 10.5 MB, less than 63.39% of C++ online
 * submissions for Longest Increasing Subsequence.
 *
 * Time complexity : O(NlogN)
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
    vector<int> answer;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = lower_bound(answer.begin(), answer.end(), nums[i]);

      if (it == answer.end()) {
        answer.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
    }
    return answer.size();
  }
};