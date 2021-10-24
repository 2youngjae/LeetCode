/**
 * @file sort.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-10-24
 * @copyright Copyright (c) 2021
 *
 * Runtime: 27 ms, faster than 39.11% of C++ online submissions for Merge
 * Intervals. Memory Usage: 14.3 MB, less than 56.70% of C++ online submissions
 * for Merge Intervals.
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
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) return intervals;

    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
    vector<vector<int>> answer;
    answer.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
      if (answer.back()[1] < intervals[i][0]) {
        answer.push_back(intervals[i]);
      } else {
        answer.back()[1] = max(answer.back()[1], intervals[i][1]);
      }
    }
    return answer;
  }
};