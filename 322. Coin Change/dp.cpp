/**
 * @file dp.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-06-20
 * @copyright Copyright (c) 2021
 *
 * Runtime: 52 ms, faster than 90.63% of C++ online submissions for Coin Change.
 * Memory Usage: 14.5 MB, less than 23.98% of C++ online submissions for Coin
 * Change.
 *
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    const int MAX_AMOUNT = 10000;
    set<int> s;
    for (int i = 0; i < coins.size(); ++i) {
      s.insert(coins[i]);
    }

    vector<int> d(amount + 1, MAX_AMOUNT);
    d[0] = 0;

    for (int i = 0; i <= amount; ++i) {
      int min_val = MAX_AMOUNT;
      for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter) {
        if (*iter > i) {
          break;
        }
        min_val = min(min_val, d[i - *iter]);
      }
      if (min_val != MAX_AMOUNT) d[i] = min_val + 1;
    }
    return (d[amount] == MAX_AMOUNT) ? -1 : d[amount];
  }
};

int main() {
  vector<int> coins = {1, 2, 5};
  int amount = 11;

  cout << Solution().coinChange(coins, amount) << endl;
  return 0;
}