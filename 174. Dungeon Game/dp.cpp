/**
 * @file dp.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-21
 * 
 * Runtime: 8 ms, faster than 79.76% of C++ online submissions for Dungeon Game.
 * Memory Usage: 8.8 MB, less than 76.14% of C++ online submissions for Dungeon Game.
 * 
 * Time complexity : O(r*c)
 * Space complexity : O(r*c)
 * 
 * @copyright Copyright (c) 2021
 */

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        int c = dungeon[0].size();
        vector<vector<int>> d(r, vector<int>(c));

        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                if (i == r - 1 && j == c - 1) {
                    d[i][j] = max(1, 1 - dungeon[i][j]);
                } else {
                    d[i][j] = INT32_MAX;
                    if (i + 1 < r) d[i][j] = min(d[i][j], max(d[i + 1][j] - dungeon[i][j], 1));
                    if (j + 1 < c) d[i][j] = min(d[i][j], max(d[i][j + 1] - dungeon[i][j], 1));
                }
            }
        }

        return d[0][0];
    }
};

int main() {
    Solution s;
    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}};
    printf("answer = %d\n", s.calculateMinimumHP(dungeon));
    return 0;
}