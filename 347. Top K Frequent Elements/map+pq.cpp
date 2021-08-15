/**
 * @file map+pq.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-08-16
 * @copyright Copyright (c) 2021
 *
 * Runtime: 16 ms, faster than 65.77% of C++ online submissions for Top K
 * Frequent Elements.
 * Memory Usage: 13.8 MB, less than 39.18% of C++ online
 * submissions for Top K Frequent Elements.
 *
 * Time complexity : O(NlogN)
 * Space complexity : O(3*N)
 *
 */

#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  struct Node {
    int num;
    int count;
    Node(int num, int count) : num(num), count(count) {}
  };

  struct compare {
    bool operator()(const Node& n1, const Node& n2) {
      return n1.count < n2.count;
    }
  };

  vector<int> topKFrequent(vector<int>& nums, int k) {
    // 1. map 사용하여 숫자들이 각각 몇번씩 나왔는지 확인.
    unordered_map<int, int> m;
    for (int& num : nums) {
      ++m[num];
    }

    // 2. count 기준으로 pq에 push
    priority_queue<Node, vector<Node>, compare> pq;
    for (auto& element : m) {
      pq.push(Node(element.first, element.second));
    }

    // 3. pq에서 k개 만큼 pop하여 answer에 push
    vector<int> answer;
    for (int i = 0; i < k; ++i) {
      answer.push_back(pq.top().num);
      pq.pop();
    }

    return answer;
  }
};