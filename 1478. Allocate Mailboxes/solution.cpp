/**
 * @file solution.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2022-07-04
 * @copyright Copyright (c) 2022
 *
 * Runtime: 146 ms, faster than 17.02% of C++ online submissions for Allocate
Mailboxes. Memory Usage: 9 MB, less than 40.12% of C++ online submissions for
Allocate Mailboxes.
 *
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minDistance(vector<int>& houses, int k) {
    int max_val = 987654321;
    int n = houses.size();
    vector<vector<int>> d(k + 1, vector<int>(n));
    vector<vector<int>> cost(n, vector<int>(n));

    sort(houses.begin(), houses.end());

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cost[i][j] = 0;
        for (int a = i; a <= j; ++a) {
          cost[i][j] += abs(houses[a] - houses[i + ((j - i) >> 1)]);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      d[1][i] = cost[0][i];
    }

    for (int a = 2; a <= k; ++a) {
      for (int i = 0; i < n; ++i) {
        d[a][i] = max_val;
        for (int j = 0; j < i; ++j) {
          d[a][i] = min(d[a][i], d[a - 1][j] + cost[j + 1][i]);
        }
      }
    }
    return d[k][n - 1];
  }
};