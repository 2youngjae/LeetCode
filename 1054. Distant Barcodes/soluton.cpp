/**
 * @file soluton.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2022-02-27
 * @copyright Copyright (c) 2022
 *
 * Time complexity : O(nlogn)
 * Space complexity : O(3n)
 *
 * Runtime: 170 ms, faster than 31.96% of C++ online submissions for Distant
Barcodes. Memory Usage: 42 MB, less than 70.11% of C++ online submissions for
Distant Barcodes.
 *
 */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    vector<int> answer(barcodes.size(), 0);
    unordered_map<int, int> m;
    priority_queue<pair<int, int>> pq;

    for (auto& i : barcodes) ++m[i];
    for (auto& iter : m) pq.push({iter.second, iter.first});

    int idx = 0;
    while (!pq.empty()) {
      int k = pq.top().second;
      int v = pq.top().first;
      pq.pop();

      while (v) {
        if (idx >= answer.size()) {
          idx = 1;
        }
        answer[idx] = k;
        --v;
        idx += 2;
      }
    }
    return answer;
  }
};

int main() { return 0; }