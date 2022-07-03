/**
 * @file solution.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2022-07-04
 * @copyright Copyright (c) 2022
 *
 * Runtime: 51 ms, faster than 30.01% of C++ online submissions for
Non-decreasing Array. Memory Usage: 27.1 MB, less than 53.01% of C++ online
submissions for Non-decreasing Array.
 *
 */

#include <vector>
using namespace std;

class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] > nums[i + 1]) {
        if (i >= 1 && nums[i - 1] > nums[i + 1]) {
          nums[i + 1] = nums[i];
        } else {
          nums[i] = nums[i + 1];
        }
        break;
      }
    }
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] > nums[i + 1]) {
        return false;
      }
    }
    return true;
  }
};