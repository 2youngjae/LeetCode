/**
 * @file simple.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-06-20
 * @copyright Copyright (c) 2021
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate
 * Image. Memory Usage: 7.2 MB, less than 28.97% of C++ online submissions for
 * Rotate Image.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void inline rotate_image(vector<vector<int>>& matrix, const int& i,
                           const int& j, const int& n) {
    int temp = matrix[i][j];
    matrix[i][j] = matrix[n - 1 - j][i];
    matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
    matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
    matrix[j][n - 1 - i] = temp;
  }

  void rotate(vector<vector<int>>& matrix) {
    const int n = matrix.size();
    for (int i = 0, i_end = (n + 1) >> 1; i < i_end; ++i) {
      for (int j = 0, j_end = (n >> 1); j < j_end; ++j) {
        rotate_image(matrix, i, j, n);
      }
    }
  }
};

int main() { return 0; }