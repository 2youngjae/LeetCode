/**
 * @file dp.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-11-07
 * @copyright Copyright (c) 2021
 *
 * Time complexity : O(N)
 * Space complexity : O(1)
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    const int size = nums.size();
    if (size == 0) return 0;
    int up = 1, down = 1;

    for (int i = 1; i < size; ++i) {
      if (nums[i] > nums[i - 1]) {
        up = down + 1;
      } else if (nums[i] < nums[i - 1]) {
        down = up + 1;
      }
    }
    return max(up, down);
  }
};