/**
 * @file sort.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-10-10
 * @copyright Copyright (c) 2021
 *
 * Runtime: 412 ms, faster than 58.32% of C++ online submissions for Minimum
 * Number of Arrows to Burst Balloons. Memory Usage: 89.8 MB, less than 50.08%
 * of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
 *
 * Time complexity O(nlogn)
 * Space complexity O(n)
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(),
         [](const vector<int>& first, const vector<int>& second) {
           return first[1] < second[1];
         });
    int answer = 1;
    const int size = points.size();
    int min = points[0][1];
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] <= min) continue;
      ++answer;
      min = points[i][1];
    }
    return answer;
  }
};

int main() { return 0; }