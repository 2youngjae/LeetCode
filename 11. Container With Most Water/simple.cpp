/**
 * @file simple.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2022-03-13
 * @copyright Copyright (c) 2022
 *
 * Runtime: 138 ms, faster than 42.06% of C++ online submissions for Container
With Most Water. Memory Usage: 59 MB, less than 39.09% of C++ online submissions
for Container With Most Water.

Time complexity : O(n)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
  int answer = 0;
  int i = 0, j = height.size() - 1;
  while (i < j) {
    int h = min(height[i], height[j]);
    answer = max(answer, (j - i) * h);
    while (height[i] <= h && i < j) ++i;
    while (height[j] <= h && i < j) --j;
  }
  return answer;
}