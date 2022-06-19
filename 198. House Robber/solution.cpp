/**
 * @file solution.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2022-06-19
 * @copyright Copyright (c) 2022
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for House
 * Robber. Memory Usage: 7.6 MB, less than 94.69% of C++ online submissions for
 * House Robber.
 *
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int a = 0;
    int b = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (i % 2 == 0) {
        a = max(a + nums[i], b);
      } else {
        b = max(a, b + nums[i]);
      }
    }

    return max(a, b);
  }
};
