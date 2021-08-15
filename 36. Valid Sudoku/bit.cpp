/**
 * @file bit.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-08-16
 * @copyright Copyright (c) 2021
 *
 * Runtime: 16 ms, faster than 91.65% of C++ online submissions for Valid
 * Sudoku.
 * Memory Usage: 18.2 MB, less than 63.25% of C++ online submissions for
 * Valid Sudoku.
 *
 * Time complexity : O(N^2)
 * Space complexity : O(3*N)
 *
 */

#include <vector>
using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<short> row(9, 0);    // 가로방향 확인
    vector<short> col(9, 0);    // 세로방향 확인
    vector<short> block(9, 0);  // 3x3 block 확인

    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') continue;  // 숫자가 아니면 continue

        int idx = 1 << (board[i][j] -
                        '0');  // 비트 마스킹을 사용하여 숫자번째 비트 켜기
        if (row[i] & idx || col[j] & idx ||
            block[i / 3 * 3 + j / 3] & idx) {  // 같은비트가 켜져 있으면 중복된
                                               // 숫자가 있으므로 false return
          return false;
        }

        row[i] |= idx;                    // 가로방향 마킹
        col[j] |= idx;                    // 세로방향 바킹
        block[i / 3 * 3 + j / 3] |= idx;  // 3x3 block 마킹
      }
    return true;
  }
};