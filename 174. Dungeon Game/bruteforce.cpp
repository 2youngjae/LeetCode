#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    const vector<int> dr = {0, 1};
    const vector<int> dc = {1, 0};
    int answer = -987654321;

    void dfs(vector<vector<int>>& dungeon, int r, int c, int minHp, int curHp) {
        printf("(%d %d), (%d, %d)\n", r, c, minHp, curHp);
        curHp = curHp + dungeon[r][c];
        minHp = min(minHp, curHp);
        if (r == dungeon.size() - 1 && c == dungeon[0].size() - 1) {
            answer = max(answer, minHp);
            // printf("%d %d %d\n", minHp, curHp, answer);
        } else {
            for (int i = 0; i < 2; i++) {
                int nextR = r + dr[i];
                int nextC = c + dc[i];
                if (nextR < dungeon.size() && nextC < dungeon[0].size()) {
                    dfs(dungeon, nextR, nextC, minHp, curHp);
                }
            }
        }
    }

   public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        dfs(dungeon, 0, 0, 0, 0);
        return 1 - answer;
    }
};

int main() {
    Solution s;
    // vector<vector<int>> dungeon = {
    //     {-2, -3, 3},
    //     {-5, -10, 1},
    //     {10, 30, -5}};
    vector<vector<int>> dungeon = {{5,23,-48,-21,-72,-62,-19,-55,-3,-93,-84,14,-34,46,-82,-46,39,26,47,-71,-46,-3,-59,-93,-13,-72,19,-43,-51,-2,-6,-53,12,-40,15,-94,37,-3,-32,-97}};
    printf("answer = %d\n", s.calculateMinimumHP(dungeon));

    return 0;
}
