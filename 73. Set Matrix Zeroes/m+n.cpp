/**
 * @file m+n.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-06-04
 * @copyright Copyright (c) 2021
 *
 * Runtime: 12 ms, faster than 82.20% of C++ online submissions for Set Matrix
 * Zeroes. Memory Usage: 13.2 MB, less than 44.04% of C++ online submissions for
 * Set Matrix Zeroes.
 *
 * space complexity : O(N+M)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<bool> mv(m);
    vector<bool> nv(n);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          mv[i] = true;
          nv[j] = true;
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mv[i] || nv[j]) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

int main() { return 0; }