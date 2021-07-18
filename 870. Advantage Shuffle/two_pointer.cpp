/**
 * @file two_pointer.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-07-18
 * @copyright Copyright (c) 2021
 *
 * Runtime: 184 ms, faster than 19.39% of C++ online submissions for Advantage
 * Shuffle. Memory Usage: 131 MB, less than 5.02% of C++ online submissions for
 * Advantage Shuffle.
 *
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  static const int comp(const int& a, const int& b) { return a > b; }

  vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    const int size = nums1.size();

    vector<int> v;
    v.assign(nums2.begin(), nums2.end());

    sort(nums1.begin(), nums1.end());
    sort(v.begin(), v.end(), comp);

    map<int, queue<int>> m;
    int i = 0;
    int j = size - 1;
    for (int k = 0; k < nums1.size(); ++k) {
      m[v[k]].push((nums1[j] > v[k]) ? nums1[j--] : nums1[i++]);
    }

    for (int i = 0; i < size; ++i) {
      nums1[i] = m[nums2[i]].front();
      m[nums2[i]].pop();
    }
    return nums1;
  }
};

int main() { return 0; }