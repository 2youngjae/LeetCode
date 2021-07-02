/**
 * @file simple.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-07-02
 * @copyright Copyright (c) 2021
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of
 * Life. Memory Usage: 6.9 MB, less than 54.15% of C++ online submissions for
 * Game of Life.
 *
 * Time complexity : O(m*n)
 * Space complexity : O(m*n)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  const int dc[8] = {1, 0, -1, 1, -1, 1, 0, -1};
  int getLiveNeighborCount(const vector<vector<int>>& board, const int& r,
                           const int& c) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
      const int nextR = r + dr[i];
      const int nextC = c + dc[i];
      if (0 <= nextR && nextR < board.size() && 0 <= nextC &&
          nextC < board[0].size()) {
        if (board[nextR][nextC] == 1) ++count;
      }
    }
    return count;
  }

  bool isOk(const int& live, const int& count) {
    return (live == 0 && count == 3) ||
           (live == 1 && (count == 2 || count == 3));
  }

  void fillZeros(vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        board[i][j] = 0;
      }
    }
  }

  void fillLives(vector<vector<int>>& board,
                 const vector<pair<int, int>>& lives) {
    for (auto pos : lives) {
      board[pos.first][pos.second] = 1;
    }
  }

  void gameOfLife(vector<vector<int>>& board) {
    vector<pair<int, int>> lives;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (isOk(board[i][j], getLiveNeighborCount(board, i, j))) {
          lives.push_back(pair<int, int>(i, j));
        }
      }
    }
    fillZeros(board);
    fillLives(board, lives);
  }
};

int main() {}