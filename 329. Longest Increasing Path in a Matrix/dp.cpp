/**
 * @file dp.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-05
 * 
 * @copyright Copyright (c) 2021
 * 
 * Runtime: 36 ms, faster than 97.08% of C++ online submissions for Longest Increasing Path in a Matrix.
 * Memory Usage: 15.9 MB, less than 86.37% of C++ online submissions for Longest Increasing Path in a Matrix.
 * 
 * Time complexity : O(m*n)
 * Space complexity : O(m*n)
 * 
 */

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    const int dr[4] = {1, -1, 0, 0};
    const int dc[4] = {0, 0, 1, -1};
    vector<vector<int>> d;

    int dfs(vector<vector<int>>& matrix, int r, int c) {
        d[r][c] = 1;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 <= nr && nr < matrix.size() && 0 <= nc && nc < matrix[r].size()) {
                if (matrix[r][c] < matrix[nr][nc]) {
                    if (d[nr][nc] == 0) dfs(matrix, nr, nc);
                    d[r][c] = max(d[r][c], d[nr][nc] + 1);
                }
            }
        }
        return d[r][c];
    }

   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int answer = 0;

        d.resize(matrix.size(), vector<int>(matrix[0].size()));

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (d[i][j] == 0) {
                    dfs(matrix, i, j);
                }
                answer = max(answer, d[i][j]);
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}};
    printf("answer = %d\n", s.longestIncreasingPath(matrix));

    return 0;
}