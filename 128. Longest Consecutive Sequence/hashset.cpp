/**
 * @file hashset.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-08-30
 * @copyright Copyright (c) 2021
 *
 * Runtime: 52 ms, faster than 87.86% of C++ online submissions for Longest
 * Consecutive Sequence. Memory Usage: 28.8 MB, less than 83.10% of C++ online
 * submissions for Longest Consecutive Sequence.
 *
 */

#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int answer = 0;
    for (auto& num : s) {
      if (!s.count(num - 1)) {
        int cur = num;
        int cnt = 1;

        while (s.count(cur + 1)) {
          ++cur;
          ++cnt;
        }

        answer = max(answer, cnt);
      }
    }
    return answer;
  }
};