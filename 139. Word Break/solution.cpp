/**
 * @file solution.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2022-06-19
 * @copyright Copyright (c) 2022
 *
 * Runtime: 11 ms, faster than 66.24% of C++ online submissions for Word Break.
 * Memory Usage: 7.6 MB, less than 94.67% of C++ online submissions for Word
 * Break.
 *
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size(), false);
    dp[0] = true;

    for (int i = 0; i <= s.size(); i++) {
      for (auto str : wordDict) {
        if (dp[i]) {
          if (!s.substr(i, str.size()).compare(str)) {
            dp[i + str.size()] = true;
          }
        }
      }
    }
    return dp[s.size()];
  }
};