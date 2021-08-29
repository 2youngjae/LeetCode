/**
 * @file solution.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-08-30
 * @copyright Copyright (c) 2021
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter
 * Combinations of a Phone Number. Memory Usage: 6.5 MB, less than 63.18% of C++
 * online submissions for Letter Combinations of a Phone Number.
 */

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string>& generateCombination(string& str, vector<string>& result) {
    int jum = str.length();
    int n = result.size();
    vector<string> answer;

    if (n == 0) {
      for (int i = 0; i < jum; ++i) {
        string s(1, str[i]);
        answer.push_back(s);
      }
    } else {
      for (auto iter = result.begin(); iter != result.end(); ++iter) {
        for (int j = 0; j < jum; ++j) {
          string s(1, str[j]);
          answer.push_back(*iter + s);
        }
      }
    }

    return answer;
  }

  vector<string> letterCombinations(string digits) {
    vector<string> result;
    unordered_map<string, string> nums;
    nums["2"] = "abc";
    nums["3"] = "def";
    nums["4"] = "ghi";
    nums["5"] = "jkl";
    nums["6"] = "mno";
    nums["7"] = "pqrs";
    nums["8"] = "tuv";
    nums["9"] = "wxyz";

    for (int i = 0; i < digits.length(); i++) {
      string s(1, digits[i]);
      result = generateCombination(nums[s], result);
    }

    return result;
  }
};