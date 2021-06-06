/**
 * @file bruteforce.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-06-04
 *
 * @copyright Copyright (c) 2021
 *
 * Runtime: 320 ms, faster than 17.14% of C++ online submissions for Jump Game.
 * Memory Usage: 48.6 MB, less than 5.07% of C++ online submissions for Jump
 * Game.
 *
 * Time complexity : O(length * value)
 * Space complexity : O(n)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    vector<bool> visited(nums.size());
    visited[0] = true;

    for (int i = 0; i < nums.size(); i++) {
      if (!visited[i]) {
        return false;
      }
      if (nums[i] + i >= nums.size() - 1) {
        return true;
      }
      for (int j = 1; j <= nums[i]; j++) {
        visited[i + j] = true;
      }
    }
    return false;
  }
};

int main() { return 0; }