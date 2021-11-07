/**
 * @file dp.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-11-07
 * @copyright Copyright (c) 2021
 *
 * Time complexity : O(N^2)
 * Space complexity : O(N)
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int> > &triangle) {
    const int n = triangle.size();

    vector<int> result(triangle.back());

    for (int i = n - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        result[j] = min(result[j], result[j + 1]) + triangle[i][j];
      }
    }
    return result[0];
  }
};