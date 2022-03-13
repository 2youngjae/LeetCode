/**
 * @file map.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2022-03-13
 * @copyright Copyright (c) 2022
 *
 * Runtime: 15 ms, faster than 72.17% of C++ online submissions for Longest
Substring Without Repeating Characters. Memory Usage: 8.6 MB, less than 38.65%
of C++ online submissions for Longest Substring Without Repeating Characters.

Time complexity : O(n)
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    map<char, int> m;
    int start = -1;
    int maxLen = 0;

    for (int i = 0; i < s.size(); i++) {
      if (m.count(s[i]) != 0) {
        start = max(start, m[s[i]]);
      }
      m[s[i]] = i;
      maxLen = max(maxLen, i - start);
    }

    return maxLen;
  }
};