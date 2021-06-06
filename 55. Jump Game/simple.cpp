/**
 * @file simple.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-06-06
 *
 * @copyright Copyright (c) 2021
 *
 * Runtime: 92 ms, faster than 22.12% of C++ online submissions for Jump Game.
 * Memory Usage: 48.3 MB, less than 12.88% of C++ online submissions for Jump
 * Game.
 *
 * Time complexity : O(n)
 * Space complexity : O(1)
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int max_idx = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i <= max_idx) {
        max_idx = max(max_idx, i + nums[i]);
        if (max_idx >= nums.size() - 1) {
          return true;
        }
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() { return 0; }