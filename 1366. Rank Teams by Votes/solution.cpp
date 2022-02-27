/**
 * @file solution.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2022-02-27
 * @copyright Copyright (c) 2022
 *
 * Runtime: 6 ms, faster than 99.80% of C++ online submissions for Rank Teams by
Votes. Memory Usage: 10.5 MB, less than 89.36% of C++ online submissions for
Rank Teams by Votes.
 *
 * Time complexity : O(N*M)
 * Space complexity : O(N*M)
 *
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string rankTeams(vector<string>& votes) {
    int n = votes.size();
    int m = votes[0].size();
    vector<vector<int>> v(m, vector<int>(26, 0));

    for (auto& vote : votes) {
      for (int i = 0; i < m; ++i) {
        ++v[i][vote[i] - 'A'];
      }
    }
    sort(votes[0].begin(), votes[0].end(), [&](char& a, char& b) {
      for (int i = 0; i < m; ++i) {
        if (v[i][a - 'A'] == v[i][b - 'A'])
          continue;
        else
          return v[i][a - 'A'] > v[i][b - 'A'];
      }
      return a < b;
    });
    return votes[0];
  }
};